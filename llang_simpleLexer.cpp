
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1


#include "llang_simpleLexer.h"


using namespace antlr4;

using namespace llang;


using namespace antlr4;

namespace {

struct Llang_simpleLexerStaticData final {
  Llang_simpleLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Llang_simpleLexerStaticData(const Llang_simpleLexerStaticData&) = delete;
  Llang_simpleLexerStaticData(Llang_simpleLexerStaticData&&) = delete;
  Llang_simpleLexerStaticData& operator=(const Llang_simpleLexerStaticData&) = delete;
  Llang_simpleLexerStaticData& operator=(Llang_simpleLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag llang_simplelexerLexerOnceFlag;
Llang_simpleLexerStaticData *llang_simplelexerLexerStaticData = nullptr;

void llang_simplelexerLexerInitialize() {
  assert(llang_simplelexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<Llang_simpleLexerStaticData>(
    std::vector<std::string>{
      "NumericLiteral", "DecimalIntegerLiteral", "Identifier", "IdentifierPart", 
      "OpenBracket", "CloseBracket", "OpenParen", "CloseParen", "Colon", 
      "SemiColon", "SelectArrow", "Push", "Pop", "GlobalList", "Comma", 
      "SelfPlus", "Assign", "DeleteWord", "Delete", "Connect", "Seperator", 
      "FilePrefix", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "'['", "']'", "'('", "')'", "':'", "';'", "'->'", "'<'", 
      "'>'", "'@'", "','", "'++'", "'='", "'del'", "'~'", "'&'", "'''", 
      "'#'"
    },
    std::vector<std::string>{
      "", "NumericLiteral", "Identifier", "OpenBracket", "CloseBracket", 
      "OpenParen", "CloseParen", "Colon", "SemiColon", "SelectArrow", "Push", 
      "Pop", "GlobalList", "Comma", "SelfPlus", "Assign", "DeleteWord", 
      "Delete", "Connect", "Seperator", "FilePrefix", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,21,116,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,1,0,3,0,49,8,0,1,0,1,0,1,1,1,1,1,1,5,1,56,8,1,10,1,12,
  	1,59,9,1,3,1,61,8,1,1,2,4,2,64,8,2,11,2,12,2,65,1,3,1,3,1,4,1,4,1,5,1,
  	5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,12,1,12,
  	1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,17,1,18,
  	1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,4,22,111,8,22,11,22,12,22,112,
  	1,22,1,22,0,0,23,1,1,3,0,5,2,7,0,9,3,11,4,13,5,15,6,17,7,19,8,21,9,23,
  	10,25,11,27,12,29,13,31,14,33,15,35,16,37,17,39,18,41,19,43,20,45,21,
  	1,0,4,1,0,49,57,1,0,48,57,3,0,65,90,95,95,97,122,3,0,9,10,13,13,32,32,
  	118,0,1,1,0,0,0,0,5,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,1,48,
  	1,0,0,0,3,60,1,0,0,0,5,63,1,0,0,0,7,67,1,0,0,0,9,69,1,0,0,0,11,71,1,0,
  	0,0,13,73,1,0,0,0,15,75,1,0,0,0,17,77,1,0,0,0,19,79,1,0,0,0,21,81,1,0,
  	0,0,23,84,1,0,0,0,25,86,1,0,0,0,27,88,1,0,0,0,29,90,1,0,0,0,31,92,1,0,
  	0,0,33,95,1,0,0,0,35,97,1,0,0,0,37,101,1,0,0,0,39,103,1,0,0,0,41,105,
  	1,0,0,0,43,107,1,0,0,0,45,110,1,0,0,0,47,49,5,45,0,0,48,47,1,0,0,0,48,
  	49,1,0,0,0,49,50,1,0,0,0,50,51,3,3,1,0,51,2,1,0,0,0,52,61,5,48,0,0,53,
  	57,7,0,0,0,54,56,7,1,0,0,55,54,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,
  	58,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,60,52,1,0,0,0,60,53,1,0,0,0,61,
  	4,1,0,0,0,62,64,3,7,3,0,63,62,1,0,0,0,64,65,1,0,0,0,65,63,1,0,0,0,65,
  	66,1,0,0,0,66,6,1,0,0,0,67,68,7,2,0,0,68,8,1,0,0,0,69,70,5,91,0,0,70,
  	10,1,0,0,0,71,72,5,93,0,0,72,12,1,0,0,0,73,74,5,40,0,0,74,14,1,0,0,0,
  	75,76,5,41,0,0,76,16,1,0,0,0,77,78,5,58,0,0,78,18,1,0,0,0,79,80,5,59,
  	0,0,80,20,1,0,0,0,81,82,5,45,0,0,82,83,5,62,0,0,83,22,1,0,0,0,84,85,5,
  	60,0,0,85,24,1,0,0,0,86,87,5,62,0,0,87,26,1,0,0,0,88,89,5,64,0,0,89,28,
  	1,0,0,0,90,91,5,44,0,0,91,30,1,0,0,0,92,93,5,43,0,0,93,94,5,43,0,0,94,
  	32,1,0,0,0,95,96,5,61,0,0,96,34,1,0,0,0,97,98,5,100,0,0,98,99,5,101,0,
  	0,99,100,5,108,0,0,100,36,1,0,0,0,101,102,5,126,0,0,102,38,1,0,0,0,103,
  	104,5,38,0,0,104,40,1,0,0,0,105,106,5,39,0,0,106,42,1,0,0,0,107,108,5,
  	35,0,0,108,44,1,0,0,0,109,111,7,3,0,0,110,109,1,0,0,0,111,112,1,0,0,0,
  	112,110,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,0,114,115,6,22,0,0,115,
  	46,1,0,0,0,6,0,48,57,60,65,112,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  llang_simplelexerLexerStaticData = staticData.release();
}

}

llang_simpleLexer::llang_simpleLexer(CharStream *input) : Lexer(input) {
  llang_simpleLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *llang_simplelexerLexerStaticData->atn, llang_simplelexerLexerStaticData->decisionToDFA, llang_simplelexerLexerStaticData->sharedContextCache);
}

llang_simpleLexer::~llang_simpleLexer() {
  delete _interpreter;
}

std::string llang_simpleLexer::getGrammarFileName() const {
  return "llang_simple.g4";
}

const std::vector<std::string>& llang_simpleLexer::getRuleNames() const {
  return llang_simplelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& llang_simpleLexer::getChannelNames() const {
  return llang_simplelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& llang_simpleLexer::getModeNames() const {
  return llang_simplelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& llang_simpleLexer::getVocabulary() const {
  return llang_simplelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView llang_simpleLexer::getSerializedATN() const {
  return llang_simplelexerLexerStaticData->serializedATN;
}

const atn::ATN& llang_simpleLexer::getATN() const {
  return *llang_simplelexerLexerStaticData->atn;
}




void llang_simpleLexer::initialize() {
  ::antlr4::internal::call_once(llang_simplelexerLexerOnceFlag, llang_simplelexerLexerInitialize);
}
