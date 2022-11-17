#include "antlr4-runtime.h"
#include "llang_simpleLexer.h"
#include "llang_simpleParser.h"
//#include "LlangVisitor.h"
import <iostream>;
import <string>;
import llang.visitor;
import llang.utils;
using std::string;
using std::cout, std::operator<<, std::endl;
using antlr4::ANTLRInputStream, antlr4::CommonTokenStream, antlr4::tree::ParseTree, antlr4::Parser;
using llang::llang_simpleLexer;
using llang::llang_simpleParser;
using llang::LlangVisitor;

#pragma execution_character_set("utf-8")

auto main(int argc, const char* argv[])->int {

    auto inputString = std::stringstream{ };

    inputString << "#global:[";
    auto inputStringTemp = string{};
    while (std::getline(std::cin, inputStringTemp,'\n')) { inputString << "\n" << inputStringTemp; }
    inputString << "];#global;";

    auto input = ANTLRInputStream{ inputString };
    auto lexer = llang_simpleLexer{ &input };
    auto tokens = CommonTokenStream{ &lexer };
    auto parser = llang_simpleParser{ &tokens };
    parser.setBuildParseTree(true);
    auto tree = parser.application();
    cout<< tree->toStringTree(&parser) << endl;
    auto visitor = LlangVisitor(llang::getGlobalEnvironment());
    visitor.visit(tree);

    cout << endl << "Output:" << endl;
    llang::LLPrintALL();

    return 0;
}
