import java.awt.Component
import java.awt.Dimension
import java.awt.GridBagConstraints
import java.awt.GridBagLayout
import java.io.*
import java.time.LocalTime
import javax.swing.*
import javax.swing.border.TitledBorder

object LLCodeInPut {
    val area = JTextArea().apply {}
    fun input()=StringReader(
        "#global:[${area.text}];#global;"
    )
    fun readFile(file:File)=
        BufferedReader(FileReader(file)).use {
            area.text = it.readText()
        }
    fun saveFile(file:File)=
        BufferedWriter(FileWriter(file)).use {
            it.write(area.text)
        }

}

interface LLBaseOutPutType{ fun output(s: Any) }
object LLTestOutPut: LLBaseOutPutType {
    val area=JTextArea().apply {
        isEditable=false
    }
    override fun output(s: Any){ area.text+=s.toString(); }
    fun clear(){ area.text = "" }
}

object LLOutPut: LLBaseOutPutType {
    val area=JTextArea().apply {
        isEditable=false
    }
    override fun output(s: Any){ area.text+=s.toString(); }
    fun clear(){ area.text = "" }
}

object MainFrame{
    private lateinit var componentsMap:Map<String,Pair<Component, Any>>
    init {
        componentsMap=mapOf(
            "Code" to (
                    JScrollPane(LLCodeInPut.area).apply {
                        border=TitledBorder("Code")
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=1;gridy=0;gridheight=10
                            }),
            "Log" to (
                    JScrollPane(LLTestOutPut.area).apply {
                        border=TitledBorder("Log")
                    }to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=2;gridy=0;gridheight=5
                            }),
            "Output" to (
                    JScrollPane(LLOutPut.area).apply {
                        border=TitledBorder("Output")
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=2;gridy=5;gridheight=5
                            }),

            "Run Button" to (
                    JButton("Run").apply {
                        addActionListener {
                            LLOutPut.clear()
                            LLTestOutPut.clear()
                            runAnalyses()
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=0;gridheight=1;gridwidth=1
                            }),
            "Show Env Button" to (
                    JButton("Show Env").apply {
                        addActionListener {
                            EnvMap.forEach{ (name,env)->
                                LLPrintln("envName:$name" )
                                val varss= env.vars.map { (k,v)->"key:: $k value:: ${v.name}:[${v.listContent.joinToString(",")}]" }.joinToString ("\n")
                                val laters= env.later.map { (k,v)->"key:: $k" }.joinToString ("\n")
                                val anonymous= env.anonymous.map { (k,v)->"key:: $k value:: [${v.listContent.joinToString(",")}]" }.joinToString ("\n")

                                LLPrintln("vars:\n$varss")
                                LLPrintln("laters:\n$laters")
                                LLPrintln("anonymous:\n$anonymous")

                            }
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=1;gridheight=1;gridwidth=1
                            }),
            "Clear Env Button" to (
                    JButton("Clear Env").apply {
                        addActionListener {
                            EnvMap.clear()
                            GlobalEnvironment.clear()
                            GlobalEnvironment.reInit()
                            EnvMap["global"]=GlobalEnvironment
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=2;gridheight=1;gridwidth=1
                            }),
            "Open File Button" to (
                    JButton("Open File").apply {
                        addActionListener {
                            JFileChooser().apply {
                                if (showOpenDialog(frame)==JFileChooser.APPROVE_OPTION){
                                    LLCodeInPut.apply {
                                        readFile(selectedFile)
                                    }
                                }
                            }
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=6;gridheight=1;gridwidth=1
                            }),
            "Save File Button" to (
                    JButton("Save File").apply {
                        addActionListener {
                            JFileChooser().apply {
                                if (showSaveDialog(frame)==JFileChooser.APPROVE_OPTION)
                                    LLCodeInPut.saveFile(selectedFile)
                            }
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=7;gridheight=1;gridwidth=1
                            }),
            "OutPut Button" to(
                    JButton("Output Area").apply {
                        addActionListener {
                            val (pane,cons) = componentsMap["Output"]!!
                            pane.isVisible=!pane.isVisible
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=8;gridheight=1;gridwidth=1
                            }),
            "Log Button" to(
                    JButton("Log Area").apply {
                        addActionListener {
                            val (pane,cons) = componentsMap["Log"]!!
                            pane.isVisible=!pane.isVisible
                        }
                    } to
                            GridBagConstraints().apply {
                                fill=GridBagConstraints.BOTH
                                gridx=0;gridy=9;gridheight=1;gridwidth=1
                            }),
        )
    }
    private val frame = JFrame("Llang Playground").apply {
        layout=GridBagLayout().apply {
            columnWidths= intArrayOf(0,0,0)
            columnWeights= doubleArrayOf(0.05,0.6,0.35)
            rowHeights= intArrayOf(0,0,0,0,0,0,0,0,0,0)
            rowWeights= doubleArrayOf(0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1)
        }
        componentsMap.forEach { (name,pair) ->
            add(pair.first,pair.second)
        }

        size= Dimension(800,450)
    }
    fun show(){
        frame.isVisible=true
    }
}


fun LLPrint(message:Any,outputObject: LLBaseOutPutType=LLTestOutPut){
    LLTestOutPut.output(message)
    if (outputObject is LLOutPut) outputObject.output(message)
    print(message)
}
fun LLPrintln(message: Any,outputObject: LLBaseOutPutType=LLTestOutPut){
    LLTestOutPut.output(message.toString()+"\n")
    if (outputObject is LLOutPut) outputObject.output(message.toString()+"\n")
    println(message)
}

