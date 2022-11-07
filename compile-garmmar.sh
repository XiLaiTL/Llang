cd bin
java -jar antlr-4.11.1-complete.jar \
    -Dlanguage=Cpp \
    -visitor \
    -package llang \
    -o "../" \
    "../antlr/llang_simple.g4" 