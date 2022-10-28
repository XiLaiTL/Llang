import org.antlr.v4.runtime.*
import java.io.StringReader
import javax.swing.SwingUtilities
import kotlin.random.Random

fun fori(
    i:Int=0,
    condition:(Int)->Boolean,
    next_i:(Int)->Int,
    action:(Int)->Any
){
    var presentI=i
    while(condition(presentI)){
        if(action(presentI)==true) break
        presentI=next_i(presentI)
    }
}

object LlangErrorListener:BaseErrorListener(){
    override fun syntaxError(recognizer: Recognizer<*, *>?, offendingSymbol: Any?, line: Int, charPositionInLine: Int, msg: String?, e: RecognitionException?) {
        val stack=(recognizer as Parser).ruleInvocationStack.apply { reverse() }
        LLPrintln("rule stack: $stack")
        LLPrintln("line $line:$charPositionInLine at $offendingSymbol: $msg")
    }
}

fun runAnalyses(reader: StringReader = LLCodeInPut.input(),environment: LlangEnvironment=GlobalEnvironment){
    val input = CharStreams.fromReader(reader)
    try {
        val lexer = llang_simpleLexer(input)
        val tokens=CommonTokenStream(lexer)
        val parser = llang_simpleParser(tokens).apply {
            buildParseTree=true
            addErrorListener(LlangErrorListener)
        }
        val tree = parser.application()
        println(tree.toStringTree(parser));LLTestOutPut.output(tree.toStringTree(parser)+"\n")
        val visitor = LlangVisitor(environment)
        visitor.visit(tree)
    }
    catch (e:Exception){
        LLPrintln(e.stackTraceToString())
        throw e
    }
}


fun main(args: Array<String>) {
    SwingUtilities.invokeLater {
        MainFrame.show()
    }
}
