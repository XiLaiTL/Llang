import llang_simpleParser.AnonymousListContext
import java.io.BufferedReader
import java.io.FileReader
import java.io.StringReader
import java.nio.file.Paths
import java.time.LocalTime
import kotlin.contracts.Returns

class LlangList(
    val name:String,
    val listContent: MutableList<String> = mutableListOf(),
    val env: LlangEnvironment,
    val isTemporary:Boolean = false,
    val temporaryFunction:()->Unit={}
) {
    fun push(_name: String)=listContent.add(_name)
    fun pop()=listContent.removeLast()

    fun value()=listContent.first()
    fun rotate(_number:String) {
        var number = _number.toIntOrNull() ?: return
        while (number > 0) {
            listContent.add( listContent.first())
            listContent.removeFirst()
            number--
        }
    }
    fun delete(){ if(!GlobalEnvironment.constant.contains(name)) env.vars.remove(name)}
    fun getChild(number: Int)=
        if (number>=0)
            env.varsNow(listContent[number])
        else
            env.varsNow(listContent[listContent.count()+ number])

    fun runContent(){
        LLPrintln("====running $name")
        if(isTemporary) {
            temporaryFunction();
            return
        }
        fori(0,{it<listContent.count()},{it+1}){
            val childList = env.varsNow(listContent[it])
            if (it==0&&childList.name==name) {
                LLPrintln("====constant $name")
                childList.dealConstant()
                return@fori true
            }
            LLPrint("====")
            childList.runContent()
        }
    }

    fun dealConstant(){
        when(name){
            "out"->{
                if(GlobalEnvironment.vars["@"]!!.listContent.count()==1) return
                val last = GlobalEnvironment.vars["@"]!!.getChild(-1)
                val names= last.listContent.joinToString { it.replace("\$","") }
                LLPrintln("${last.name}:[$names]",LLOutPut)
            }
            "print"->{
                val names= listContent.mapIndexed { i, s ->
                    if (i == 0) LlangList("", env = env)
                    else env.varsNow(s)
                }.joinToString("") { it.name }
                LLPrintln(names,LLOutPut)
            }
            "comment"->{
                val names= listContent.joinToString(" "){
                    if (listContent.indexOf(it)==0) ""
                    else it.replace("\$","")
                }
                LLPrintln(names,LLOutPut)
            }
            "0","1","2","3","4","5","6","7","8","9","10","11"->{
                if(GlobalEnvironment.vars["@"]!!.listContent.count()==1) return
                val last = GlobalEnvironment.vars["@"]!!.getChild(-1)
                last.rotate(name)
            }
            "same_run"->{
                if(listContent.count()>=3){
                    val controlList=env.varsNow(listContent[1])
                    val controlList2=env.varsNow(listContent[2])
                    LLPrintln("====same:[${controlList.name},${controlList2.name}]")
                    if(!env.vars.contains("logic"))
                        env.vars["logic"]= LlangList("logic", mutableListOf(),env)
                    env.vars["logic"]!!.listContent.add("${controlList.name==controlList2.name}");
                }
            }
            ":"->{
                if(listContent.count()>=3){
                    val controlList=env.varsNow(listContent[2])
                    env.vars[listContent[1]]=LlangList(listContent[1],controlList.listContent.toMutableList(),env)
                }
            }
            "del","~"->{
                if(listContent.count()>=2){
                    val controlList=env.varsNow(listContent[1])
                    controlList.delete()
                    LLPrintln("====remove ${listContent[1]}")
                }
            }
            ">"->{
                if(listContent.count()>=2){
                    val controlList=env.varsNow(listContent[1])
                    controlList.pop()
                    LLPrintln("====pop ${listContent[1]}")
                }
            }
            "<"->{
                if(listContent.count()>=3){
                    val controlList=env.varsNow(listContent[1])
                    controlList.push(listContent[2])
                    LLPrintln("====push ${listContent[2]} to ${listContent[1]}")
                }
            }
            "="->{
                //TODO: fake assign
                if(listContent.count()>=3){
                    val controlList=env.varsNow(listContent[1])
                    val controlList2=env.varsNow(listContent[2])
                    env.vars[controlList.name]=LlangList(controlList.name,controlList2.listContent.toMutableList(),env)
                }
            }
            "->"->{
                if(listContent.count()>=3){
                    GlobalEnvironment.vars["@"]!!.push(listContent[2])
                    val controlList=env.varsNow(listContent[1])
                    controlList.runContent()
                    GlobalEnvironment.vars["@"]!!.pop()
                }
            }
        }
    }
}

fun fileRead(fileName:String,environment: LlangEnvironment){
    val fileNameDeal =fileName.replace("#","")+".llg"
    val file=Paths.get(fileNameDeal).toFile()
    BufferedReader(FileReader(file)).use {
        runAnalyses(
            StringReader("$fileName:[${it.readText()}];"),
            environment = environment)
    }
}

val EnvMap:MutableMap<String,LlangEnvironment> = mutableMapOf()
open class LlangEnvironment(name: String){
    init {
        EnvMap[name]=this
    }
    val vars:MutableMap<String,LlangList> = mutableMapOf()
    val later: MutableMap<String, (()->LlangList) > = mutableMapOf()
    val anonymous:MutableMap<String,LlangList> = mutableMapOf()
//    val undefined:MutableMap<String,LlangList> = mutableMapOf()
    fun varsNow(name:String): LlangList =
        if(name.contains("\$anonymous")){
            anonymous[name]?:throw LlangException("Undefined anonymous $name")
        }
        else vars[name] ?: later[name]?.let { it() } ?:
            if (name.contains("#")) {
                fileRead(name,this)
                vars[name]?:throw LlangException("Couldn't find file: $name")
            }
            else if (this is GlobalEnvironment) {
//                undefined[name]=LlangList(name, mutableListOf(),GlobalEnvironment)
//                undefined[name]!!
                throw LlangException("Undefined variable $name")
            }
            else GlobalEnvironment.varsNow(name)
    fun clear(){
        vars.clear()
        later.clear()
        anonymous.clear()
//        undefined.clear()
    }
    
}

object GlobalEnvironment:LlangEnvironment("global"){
    val constant = listOf("@","0","1","2","3","4","5","6","7","8","9","10","11","out","print","del",">","<","=","->","~",":",
        "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","_")
    fun reInit()= constant.forEach { vars[it]=LlangList(it, mutableListOf(it),this) }
    init {
        reInit()
    }
}

class LlangVisitor(
    val env:LlangEnvironment
): llang_simpleBaseVisitor<LlangList>(){

    override fun visitApplication(ctx: llang_simpleParser.ApplicationContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.ApplicationContext::class)
        LLPrintln("====starting")
        for (listContent in ctx.listContent()){
            val list=visit(listContent)
            list.runContent()
        }
        return LlangList("begin",mutableListOf("begin"),env,true)
    }

    override fun visitDefineExpression(ctx: llang_simpleParser.DefineExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.DefineExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
//            val rightName ="<!>${ctx.right.text}"
//            env.later[rightName]={ visit(ctx.right) }
//            for(leftIdentifier in ctx.left){
//                LlangList(":", mutableListOf(":",leftIdentifier.text,rightName),env).dealConstant()
//            }

            val rightList=visit(ctx.right)
            for(leftIdentifier in ctx.left){
                LlangList(":", mutableListOf(":",leftIdentifier.text,rightList.name),env).dealConstant()


//                val name =leftIdentifier.text
//                if(ctx.right is AnonymousListContext)
//                    env.vars[name]=LlangList(name, preVisitAnonymousList(ctx.right as AnonymousListContext),env)
//
//                env.vars.remove(name)
//                env.later[name]={
//                                        val rightList=visit(ctx.right)
//                    val realList=LlangList(name,rightList.listContent.toMutableList(),env)
//                    env.vars[name]=realList
//                    env.vars[name]!!
//                }
            }
        }
    }
    override fun visitRunExpression(ctx: llang_simpleParser.RunExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.RunExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            for(leftValueExpression in ctx.left){
                val list=visit(leftValueExpression)
                list.runContent()
            }
        }
    }

    override fun visitPopExpression(ctx: llang_simpleParser.PopExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.PopExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            for(leftValueExpression in ctx.left){
                val list=visit(leftValueExpression)
                for(i in 0 until ctx.Pop().count()){
                    LlangList(">", mutableListOf(">",list.name),env).dealConstant()
                }
            }
        }
    }

    override fun visitPushExpression(ctx: llang_simpleParser.PushExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.PushExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            for(leftValueExpression in ctx.left){
                val leftList=visit(leftValueExpression)
                for(rightValueExpression in ctx.right){
                    val rightList=visit(rightValueExpression)
                    LlangList("<", mutableListOf("<",leftList.name,rightList.name),env).dealConstant()
                }
            }
        }
    }

    override fun visitSelectExpression(ctx: llang_simpleParser.SelectExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.SelectExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            for(leftValueExpression in ctx.left){
                val leftList=visit(leftValueExpression)
                for(rightValueExpression in ctx.right){
                    val rightList=visit(rightValueExpression)
                    LlangList("->", mutableListOf("->",leftList.name,rightList.name),env).dealConstant()
                }
            }
        }
    }

    override fun visitDeleteExpression(ctx: llang_simpleParser.DeleteExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.DeleteExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            for(rightValueExpression in ctx.right){
                val rightList=visit(rightValueExpression)
                LlangList("~", mutableListOf("~",rightList.name),env).dealConstant()
            }
        }
    }

    override fun visitAssignmentExpression(ctx: llang_simpleParser.AssignmentExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.AssignmentExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            val rightList=visit(ctx.right)
            for(leftValueExpression in ctx.left){
                val leftList=visit(leftValueExpression)
                LlangList("=", mutableListOf("=",leftList.name,rightList.name),env).dealConstant()
            }
        }
    }

    override fun visitSelfPlusExpression(ctx: llang_simpleParser.SelfPlusExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.SelfPlusExpressionContext::class)
        return LlangList("\$${ctx.text}", mutableListOf("\$${ctx.text}"),env,true){
            for(leftValueExpression in ctx.left){
                val leftList=visit(leftValueExpression)
                LlangList("->", mutableListOf("->","1",leftList.name),env).dealConstant()
            }
        }
    }

    override fun visitParenExpression(ctx: llang_simpleParser.ParenExpressionContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.ParenExpressionContext::class)
        return visit(ctx.listExpression())
    }

//////list content

    override fun visitSingleName(ctx: llang_simpleParser.SingleNameContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.SingleNameContext::class)
        val name = ctx.identifier()?.text?:throw LlangException("Unknow variable")
        return env.varsNow(name)
    }
    override fun visitAnonymousList(ctx: llang_simpleParser.AnonymousListContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.AnonymousListContext::class)
        val mutableList = ctx.listContent()?.map{
//                val child = visit(it)
//                env.vars[child.name]=child
//                child.name
            val name ="\$${it.text}"
            env.later[name]={ visit(it) }
            name
            }?.toMutableList()?: mutableListOf()

        val name ="\$anonymous${LocalTime.now().toString()}"
        val list =LlangList(name,mutableList,env,true)
        env.anonymous[name]=list //just forbid error, if want to change, need change the defineExpression
        return list
    }

    override fun visitGetChild(ctx: llang_simpleParser.GetChildContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.GetChildContext::class)
        val nameList =  visit(ctx.valueExpression())
        val number = ctx.NumericLiteral()?.text?.toInt() ?:0
        val nameListInEnvironment = env.varsNow(nameList.name)
        return nameListInEnvironment.getChild(number)
    }

    override fun visitConnectToNew(ctx: llang_simpleParser.ConnectToNewContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.ConnectToNewContext::class)
        val nameList =  visit(ctx.valueExpression())
        val names= nameList.listContent.map { s -> env.varsNow(s) }.joinToString("") { it.name }
        return env.varsNow(names)
    }

    override fun visitListContentList(ctx: llang_simpleParser.ListContentListContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.ListContentListContext::class)
        val list=visit(ctx.listExpression())
        return LlangList(list.name+";",list.listContent,list.env,list.isTemporary,list.temporaryFunction)
    }

    override fun visitListContentValue(ctx: llang_simpleParser.ListContentValueContext?): LlangList {
        ctx?: throw LlangException.at(llang_simpleParser.ListContentValueContext::class)
        return visit(ctx.valueExpression())
    }


}