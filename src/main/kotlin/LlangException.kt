import kotlin.reflect.KClass

class LlangException: RuntimeException {
    constructor():super(){}
    constructor(message:String):super(message){

    }
    companion object{
        fun <T : Any> at(e:KClass<T>):LlangException{
            return LlangException(e::qualifiedName.name)
        }
    }
}