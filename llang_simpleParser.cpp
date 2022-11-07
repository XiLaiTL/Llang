
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1


#include "llang_simpleListener.h"
#include "llang_simpleVisitor.h"

#include "llang_simpleParser.h"


using namespace antlrcpp;
using namespace llang;

using namespace antlr4;

namespace {

struct Llang_simpleParserStaticData final {
  Llang_simpleParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Llang_simpleParserStaticData(const Llang_simpleParserStaticData&) = delete;
  Llang_simpleParserStaticData(Llang_simpleParserStaticData&&) = delete;
  Llang_simpleParserStaticData& operator=(const Llang_simpleParserStaticData&) = delete;
  Llang_simpleParserStaticData& operator=(Llang_simpleParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag llang_simpleParserOnceFlag;
Llang_simpleParserStaticData *llang_simpleParserStaticData = nullptr;

void llang_simpleParserInitialize() {
  assert(llang_simpleParserStaticData == nullptr);
  auto staticData = std::make_unique<Llang_simpleParserStaticData>(
    std::vector<std::string>{
      "application", "listExpression", "valueExpression", "listContent", 
      "identifier"
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
  	4,1,21,172,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,3,0,12,8,0,1,0,
  	5,0,15,8,0,10,0,12,0,18,9,0,1,1,1,1,1,1,5,1,23,8,1,10,1,12,1,26,9,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,5,1,34,8,1,10,1,12,1,37,9,1,1,1,4,1,40,8,1,11,1,
  	12,1,41,1,1,1,1,1,1,5,1,47,8,1,10,1,12,1,50,9,1,1,1,1,1,1,1,1,1,5,1,56,
  	8,1,10,1,12,1,59,9,1,1,1,1,1,1,1,5,1,64,8,1,10,1,12,1,67,9,1,1,1,1,1,
  	1,1,1,1,5,1,73,8,1,10,1,12,1,76,9,1,1,1,1,1,1,1,5,1,81,8,1,10,1,12,1,
  	84,9,1,1,1,1,1,1,1,1,1,5,1,90,8,1,10,1,12,1,93,9,1,1,1,1,1,1,1,5,1,98,
  	8,1,10,1,12,1,101,9,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,109,8,1,10,1,12,1,112,
  	9,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,120,8,1,1,2,1,2,1,2,1,2,1,2,3,2,127,8,
  	2,1,2,5,2,130,8,2,10,2,12,2,133,9,2,3,2,135,8,2,1,2,1,2,1,2,3,2,140,8,
  	2,1,2,1,2,1,2,1,2,5,2,146,8,2,10,2,12,2,149,9,2,1,3,1,3,1,3,1,3,3,3,155,
  	8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,170,8,4,1,
  	4,0,1,4,5,0,2,4,6,8,0,1,1,0,16,17,205,0,16,1,0,0,0,2,119,1,0,0,0,4,139,
  	1,0,0,0,6,154,1,0,0,0,8,169,1,0,0,0,10,12,5,13,0,0,11,10,1,0,0,0,11,12,
  	1,0,0,0,12,13,1,0,0,0,13,15,3,6,3,0,14,11,1,0,0,0,15,18,1,0,0,0,16,14,
  	1,0,0,0,16,17,1,0,0,0,17,1,1,0,0,0,18,16,1,0,0,0,19,24,3,8,4,0,20,21,
  	5,19,0,0,21,23,3,8,4,0,22,20,1,0,0,0,23,26,1,0,0,0,24,22,1,0,0,0,24,25,
  	1,0,0,0,25,27,1,0,0,0,26,24,1,0,0,0,27,28,5,7,0,0,28,29,3,4,2,0,29,120,
  	1,0,0,0,30,35,3,4,2,0,31,32,5,19,0,0,32,34,3,4,2,0,33,31,1,0,0,0,34,37,
  	1,0,0,0,35,33,1,0,0,0,35,36,1,0,0,0,36,39,1,0,0,0,37,35,1,0,0,0,38,40,
  	5,11,0,0,39,38,1,0,0,0,40,41,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,120,
  	1,0,0,0,43,48,3,4,2,0,44,45,5,19,0,0,45,47,3,4,2,0,46,44,1,0,0,0,47,50,
  	1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,51,1,0,0,0,50,48,1,0,0,0,51,52,
  	5,10,0,0,52,57,3,4,2,0,53,54,5,19,0,0,54,56,3,4,2,0,55,53,1,0,0,0,56,
  	59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,120,1,0,0,0,59,57,1,0,0,0,60,
  	65,3,4,2,0,61,62,5,19,0,0,62,64,3,4,2,0,63,61,1,0,0,0,64,67,1,0,0,0,65,
  	63,1,0,0,0,65,66,1,0,0,0,66,68,1,0,0,0,67,65,1,0,0,0,68,69,5,9,0,0,69,
  	74,3,4,2,0,70,71,5,19,0,0,71,73,3,4,2,0,72,70,1,0,0,0,73,76,1,0,0,0,74,
  	72,1,0,0,0,74,75,1,0,0,0,75,120,1,0,0,0,76,74,1,0,0,0,77,82,3,4,2,0,78,
  	79,5,19,0,0,79,81,3,4,2,0,80,78,1,0,0,0,81,84,1,0,0,0,82,80,1,0,0,0,82,
  	83,1,0,0,0,83,120,1,0,0,0,84,82,1,0,0,0,85,86,7,0,0,0,86,91,3,4,2,0,87,
  	88,5,19,0,0,88,90,3,4,2,0,89,87,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,
  	92,1,0,0,0,92,120,1,0,0,0,93,91,1,0,0,0,94,99,3,4,2,0,95,96,5,19,0,0,
  	96,98,3,4,2,0,97,95,1,0,0,0,98,101,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,
  	0,100,102,1,0,0,0,101,99,1,0,0,0,102,103,5,15,0,0,103,104,3,4,2,0,104,
  	120,1,0,0,0,105,110,3,4,2,0,106,107,5,19,0,0,107,109,3,4,2,0,108,106,
  	1,0,0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,113,1,0,0,
  	0,112,110,1,0,0,0,113,114,5,14,0,0,114,120,1,0,0,0,115,116,5,5,0,0,116,
  	117,3,2,1,0,117,118,5,6,0,0,118,120,1,0,0,0,119,19,1,0,0,0,119,30,1,0,
  	0,0,119,43,1,0,0,0,119,60,1,0,0,0,119,77,1,0,0,0,119,85,1,0,0,0,119,94,
  	1,0,0,0,119,105,1,0,0,0,119,115,1,0,0,0,120,3,1,0,0,0,121,122,6,2,-1,
  	0,122,140,3,8,4,0,123,134,5,3,0,0,124,131,3,6,3,0,125,127,5,13,0,0,126,
  	125,1,0,0,0,126,127,1,0,0,0,127,128,1,0,0,0,128,130,3,6,3,0,129,126,1,
  	0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,132,1,0,0,0,132,135,1,0,0,0,
  	133,131,1,0,0,0,134,124,1,0,0,0,134,135,1,0,0,0,135,136,1,0,0,0,136,140,
  	5,4,0,0,137,138,5,18,0,0,138,140,3,4,2,1,139,121,1,0,0,0,139,123,1,0,
  	0,0,139,137,1,0,0,0,140,147,1,0,0,0,141,142,10,2,0,0,142,143,5,3,0,0,
  	143,144,5,1,0,0,144,146,5,4,0,0,145,141,1,0,0,0,146,149,1,0,0,0,147,145,
  	1,0,0,0,147,148,1,0,0,0,148,5,1,0,0,0,149,147,1,0,0,0,150,151,3,2,1,0,
  	151,152,5,8,0,0,152,155,1,0,0,0,153,155,3,4,2,0,154,150,1,0,0,0,154,153,
  	1,0,0,0,155,7,1,0,0,0,156,170,5,2,0,0,157,170,5,1,0,0,158,170,5,7,0,0,
  	159,170,5,9,0,0,160,170,5,10,0,0,161,170,5,11,0,0,162,170,5,12,0,0,163,
  	170,5,14,0,0,164,170,5,15,0,0,165,170,5,16,0,0,166,170,5,17,0,0,167,168,
  	5,20,0,0,168,170,5,2,0,0,169,156,1,0,0,0,169,157,1,0,0,0,169,158,1,0,
  	0,0,169,159,1,0,0,0,169,160,1,0,0,0,169,161,1,0,0,0,169,162,1,0,0,0,169,
  	163,1,0,0,0,169,164,1,0,0,0,169,165,1,0,0,0,169,166,1,0,0,0,169,167,1,
  	0,0,0,170,9,1,0,0,0,21,11,16,24,35,41,48,57,65,74,82,91,99,110,119,126,
  	131,134,139,147,154,169
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  llang_simpleParserStaticData = staticData.release();
}

}

llang_simpleParser::llang_simpleParser(TokenStream *input) : llang_simpleParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

llang_simpleParser::llang_simpleParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  llang_simpleParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *llang_simpleParserStaticData->atn, llang_simpleParserStaticData->decisionToDFA, llang_simpleParserStaticData->sharedContextCache, options);
}

llang_simpleParser::~llang_simpleParser() {
  delete _interpreter;
}

const atn::ATN& llang_simpleParser::getATN() const {
  return *llang_simpleParserStaticData->atn;
}

std::string llang_simpleParser::getGrammarFileName() const {
  return "llang_simple.g4";
}

const std::vector<std::string>& llang_simpleParser::getRuleNames() const {
  return llang_simpleParserStaticData->ruleNames;
}

const dfa::Vocabulary& llang_simpleParser::getVocabulary() const {
  return llang_simpleParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView llang_simpleParser::getSerializedATN() const {
  return llang_simpleParserStaticData->serializedATN;
}


//----------------- ApplicationContext ------------------------------------------------------------------

llang_simpleParser::ApplicationContext::ApplicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<llang_simpleParser::ListContentContext *> llang_simpleParser::ApplicationContext::listContent() {
  return getRuleContexts<llang_simpleParser::ListContentContext>();
}

llang_simpleParser::ListContentContext* llang_simpleParser::ApplicationContext::listContent(size_t i) {
  return getRuleContext<llang_simpleParser::ListContentContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::ApplicationContext::Comma() {
  return getTokens(llang_simpleParser::Comma);
}

tree::TerminalNode* llang_simpleParser::ApplicationContext::Comma(size_t i) {
  return getToken(llang_simpleParser::Comma, i);
}


size_t llang_simpleParser::ApplicationContext::getRuleIndex() const {
  return llang_simpleParser::RuleApplication;
}

void llang_simpleParser::ApplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApplication(this);
}

void llang_simpleParser::ApplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApplication(this);
}


std::any llang_simpleParser::ApplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitApplication(this);
  else
    return visitor->visitChildren(this);
}

llang_simpleParser::ApplicationContext* llang_simpleParser::application() {
  ApplicationContext *_localctx = _tracker.createInstance<ApplicationContext>(_ctx, getState());
  enterRule(_localctx, 0, llang_simpleParser::RuleApplication);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1572526) != 0) {
      setState(11);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == llang_simpleParser::Comma) {
        setState(10);
        match(llang_simpleParser::Comma);
      }
      setState(13);
      listContent();
      setState(18);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListExpressionContext ------------------------------------------------------------------

llang_simpleParser::ListExpressionContext::ListExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t llang_simpleParser::ListExpressionContext::getRuleIndex() const {
  return llang_simpleParser::RuleListExpression;
}

void llang_simpleParser::ListExpressionContext::copyFrom(ListExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeleteExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::DeleteExpressionContext::Delete() {
  return getToken(llang_simpleParser::Delete, 0);
}

tree::TerminalNode* llang_simpleParser::DeleteExpressionContext::DeleteWord() {
  return getToken(llang_simpleParser::DeleteWord, 0);
}

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::DeleteExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::DeleteExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::DeleteExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::DeleteExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::DeleteExpressionContext::DeleteExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::DeleteExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeleteExpression(this);
}
void llang_simpleParser::DeleteExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeleteExpression(this);
}

std::any llang_simpleParser::DeleteExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitDeleteExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DefineExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::DefineExpressionContext::Colon() {
  return getToken(llang_simpleParser::Colon, 0);
}

std::vector<llang_simpleParser::IdentifierContext *> llang_simpleParser::DefineExpressionContext::identifier() {
  return getRuleContexts<llang_simpleParser::IdentifierContext>();
}

llang_simpleParser::IdentifierContext* llang_simpleParser::DefineExpressionContext::identifier(size_t i) {
  return getRuleContext<llang_simpleParser::IdentifierContext>(i);
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::DefineExpressionContext::valueExpression() {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(0);
}

std::vector<tree::TerminalNode *> llang_simpleParser::DefineExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::DefineExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::DefineExpressionContext::DefineExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::DefineExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefineExpression(this);
}
void llang_simpleParser::DefineExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefineExpression(this);
}

std::any llang_simpleParser::DefineExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitDefineExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RunExpressionContext ------------------------------------------------------------------

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::RunExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::RunExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::RunExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::RunExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::RunExpressionContext::RunExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::RunExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRunExpression(this);
}
void llang_simpleParser::RunExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRunExpression(this);
}

std::any llang_simpleParser::RunExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitRunExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::AssignmentExpressionContext::Assign() {
  return getToken(llang_simpleParser::Assign, 0);
}

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::AssignmentExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::AssignmentExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::AssignmentExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::AssignmentExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::AssignmentExpressionContext::AssignmentExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}
void llang_simpleParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}

std::any llang_simpleParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::ParenExpressionContext::OpenParen() {
  return getToken(llang_simpleParser::OpenParen, 0);
}

llang_simpleParser::ListExpressionContext* llang_simpleParser::ParenExpressionContext::listExpression() {
  return getRuleContext<llang_simpleParser::ListExpressionContext>(0);
}

tree::TerminalNode* llang_simpleParser::ParenExpressionContext::CloseParen() {
  return getToken(llang_simpleParser::CloseParen, 0);
}

llang_simpleParser::ParenExpressionContext::ParenExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::ParenExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpression(this);
}
void llang_simpleParser::ParenExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpression(this);
}

std::any llang_simpleParser::ParenExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitParenExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PopExpressionContext ------------------------------------------------------------------

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::PopExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::PopExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::PopExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::PopExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::PopExpressionContext::Pop() {
  return getTokens(llang_simpleParser::Pop);
}

tree::TerminalNode* llang_simpleParser::PopExpressionContext::Pop(size_t i) {
  return getToken(llang_simpleParser::Pop, i);
}

llang_simpleParser::PopExpressionContext::PopExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::PopExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPopExpression(this);
}
void llang_simpleParser::PopExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPopExpression(this);
}

std::any llang_simpleParser::PopExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitPopExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelfPlusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::SelfPlusExpressionContext::SelfPlus() {
  return getToken(llang_simpleParser::SelfPlus, 0);
}

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::SelfPlusExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::SelfPlusExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::SelfPlusExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::SelfPlusExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::SelfPlusExpressionContext::SelfPlusExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::SelfPlusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelfPlusExpression(this);
}
void llang_simpleParser::SelfPlusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelfPlusExpression(this);
}

std::any llang_simpleParser::SelfPlusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitSelfPlusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PushExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::PushExpressionContext::Push() {
  return getToken(llang_simpleParser::Push, 0);
}

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::PushExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::PushExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::PushExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::PushExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::PushExpressionContext::PushExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::PushExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPushExpression(this);
}
void llang_simpleParser::PushExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPushExpression(this);
}

std::any llang_simpleParser::PushExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitPushExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelectExpressionContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::SelectExpressionContext::SelectArrow() {
  return getToken(llang_simpleParser::SelectArrow, 0);
}

std::vector<llang_simpleParser::ValueExpressionContext *> llang_simpleParser::SelectExpressionContext::valueExpression() {
  return getRuleContexts<llang_simpleParser::ValueExpressionContext>();
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::SelectExpressionContext::valueExpression(size_t i) {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::SelectExpressionContext::Seperator() {
  return getTokens(llang_simpleParser::Seperator);
}

tree::TerminalNode* llang_simpleParser::SelectExpressionContext::Seperator(size_t i) {
  return getToken(llang_simpleParser::Seperator, i);
}

llang_simpleParser::SelectExpressionContext::SelectExpressionContext(ListExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::SelectExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectExpression(this);
}
void llang_simpleParser::SelectExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectExpression(this);
}

std::any llang_simpleParser::SelectExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitSelectExpression(this);
  else
    return visitor->visitChildren(this);
}
llang_simpleParser::ListExpressionContext* llang_simpleParser::listExpression() {
  ListExpressionContext *_localctx = _tracker.createInstance<ListExpressionContext>(_ctx, getState());
  enterRule(_localctx, 2, llang_simpleParser::RuleListExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<llang_simpleParser::DefineExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(19);
      antlrcpp::downCast<DefineExpressionContext *>(_localctx)->identifierContext = identifier();
      antlrcpp::downCast<DefineExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<DefineExpressionContext *>(_localctx)->identifierContext);
      setState(24);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(20);
        match(llang_simpleParser::Seperator);
        setState(21);
        antlrcpp::downCast<DefineExpressionContext *>(_localctx)->identifierContext = identifier();
        antlrcpp::downCast<DefineExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<DefineExpressionContext *>(_localctx)->identifierContext);
        setState(26);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(27);
      match(llang_simpleParser::Colon);
      setState(28);
      antlrcpp::downCast<DefineExpressionContext *>(_localctx)->right = valueExpression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<llang_simpleParser::PopExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(30);
      antlrcpp::downCast<PopExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<PopExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<PopExpressionContext *>(_localctx)->valueExpressionContext);
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(31);
        match(llang_simpleParser::Seperator);
        setState(32);
        antlrcpp::downCast<PopExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<PopExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<PopExpressionContext *>(_localctx)->valueExpressionContext);
        setState(37);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(38);
        match(llang_simpleParser::Pop);
        setState(41); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == llang_simpleParser::Pop);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<llang_simpleParser::PushExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(43);
      antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<PushExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext);
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(44);
        match(llang_simpleParser::Seperator);
        setState(45);
        antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<PushExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext);
        setState(50);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(51);
      match(llang_simpleParser::Push);
      setState(52);
      antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<PushExpressionContext *>(_localctx)->right.push_back(antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext);
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(53);
        match(llang_simpleParser::Seperator);
        setState(54);
        antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<PushExpressionContext *>(_localctx)->right.push_back(antlrcpp::downCast<PushExpressionContext *>(_localctx)->valueExpressionContext);
        setState(59);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<llang_simpleParser::SelectExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(60);
      antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<SelectExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext);
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(61);
        match(llang_simpleParser::Seperator);
        setState(62);
        antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<SelectExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext);
        setState(67);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(68);
      match(llang_simpleParser::SelectArrow);
      setState(69);
      antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<SelectExpressionContext *>(_localctx)->right.push_back(antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext);
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(70);
        match(llang_simpleParser::Seperator);
        setState(71);
        antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<SelectExpressionContext *>(_localctx)->right.push_back(antlrcpp::downCast<SelectExpressionContext *>(_localctx)->valueExpressionContext);
        setState(76);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<llang_simpleParser::RunExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(77);
      antlrcpp::downCast<RunExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<RunExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<RunExpressionContext *>(_localctx)->valueExpressionContext);
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(78);
        match(llang_simpleParser::Seperator);
        setState(79);
        antlrcpp::downCast<RunExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<RunExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<RunExpressionContext *>(_localctx)->valueExpressionContext);
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<llang_simpleParser::DeleteExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(85);
      _la = _input->LA(1);
      if (!(_la == llang_simpleParser::DeleteWord

      || _la == llang_simpleParser::Delete)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(86);
      antlrcpp::downCast<DeleteExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<DeleteExpressionContext *>(_localctx)->right.push_back(antlrcpp::downCast<DeleteExpressionContext *>(_localctx)->valueExpressionContext);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(87);
        match(llang_simpleParser::Seperator);
        setState(88);
        antlrcpp::downCast<DeleteExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<DeleteExpressionContext *>(_localctx)->right.push_back(antlrcpp::downCast<DeleteExpressionContext *>(_localctx)->valueExpressionContext);
        setState(93);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<llang_simpleParser::AssignmentExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(94);
      antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->valueExpressionContext);
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(95);
        match(llang_simpleParser::Seperator);
        setState(96);
        antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->valueExpressionContext);
        setState(101);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(102);
      match(llang_simpleParser::Assign);
      setState(103);
      antlrcpp::downCast<AssignmentExpressionContext *>(_localctx)->right = valueExpression(0);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<llang_simpleParser::SelfPlusExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(105);
      antlrcpp::downCast<SelfPlusExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
      antlrcpp::downCast<SelfPlusExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<SelfPlusExpressionContext *>(_localctx)->valueExpressionContext);
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == llang_simpleParser::Seperator) {
        setState(106);
        match(llang_simpleParser::Seperator);
        setState(107);
        antlrcpp::downCast<SelfPlusExpressionContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        antlrcpp::downCast<SelfPlusExpressionContext *>(_localctx)->left.push_back(antlrcpp::downCast<SelfPlusExpressionContext *>(_localctx)->valueExpressionContext);
        setState(112);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(113);
      match(llang_simpleParser::SelfPlus);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<llang_simpleParser::ParenExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(115);
      match(llang_simpleParser::OpenParen);
      setState(116);
      listExpression();
      setState(117);
      match(llang_simpleParser::CloseParen);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueExpressionContext ------------------------------------------------------------------

llang_simpleParser::ValueExpressionContext::ValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t llang_simpleParser::ValueExpressionContext::getRuleIndex() const {
  return llang_simpleParser::RuleValueExpression;
}

void llang_simpleParser::ValueExpressionContext::copyFrom(ValueExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleNameContext ------------------------------------------------------------------

llang_simpleParser::IdentifierContext* llang_simpleParser::SingleNameContext::identifier() {
  return getRuleContext<llang_simpleParser::IdentifierContext>(0);
}

llang_simpleParser::SingleNameContext::SingleNameContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::SingleNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleName(this);
}
void llang_simpleParser::SingleNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleName(this);
}

std::any llang_simpleParser::SingleNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitSingleName(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AnonymousListContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::AnonymousListContext::OpenBracket() {
  return getToken(llang_simpleParser::OpenBracket, 0);
}

tree::TerminalNode* llang_simpleParser::AnonymousListContext::CloseBracket() {
  return getToken(llang_simpleParser::CloseBracket, 0);
}

std::vector<llang_simpleParser::ListContentContext *> llang_simpleParser::AnonymousListContext::listContent() {
  return getRuleContexts<llang_simpleParser::ListContentContext>();
}

llang_simpleParser::ListContentContext* llang_simpleParser::AnonymousListContext::listContent(size_t i) {
  return getRuleContext<llang_simpleParser::ListContentContext>(i);
}

std::vector<tree::TerminalNode *> llang_simpleParser::AnonymousListContext::Comma() {
  return getTokens(llang_simpleParser::Comma);
}

tree::TerminalNode* llang_simpleParser::AnonymousListContext::Comma(size_t i) {
  return getToken(llang_simpleParser::Comma, i);
}

llang_simpleParser::AnonymousListContext::AnonymousListContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::AnonymousListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnonymousList(this);
}
void llang_simpleParser::AnonymousListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnonymousList(this);
}

std::any llang_simpleParser::AnonymousListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitAnonymousList(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GetChildContext ------------------------------------------------------------------

llang_simpleParser::ValueExpressionContext* llang_simpleParser::GetChildContext::valueExpression() {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(0);
}

tree::TerminalNode* llang_simpleParser::GetChildContext::OpenBracket() {
  return getToken(llang_simpleParser::OpenBracket, 0);
}

tree::TerminalNode* llang_simpleParser::GetChildContext::NumericLiteral() {
  return getToken(llang_simpleParser::NumericLiteral, 0);
}

tree::TerminalNode* llang_simpleParser::GetChildContext::CloseBracket() {
  return getToken(llang_simpleParser::CloseBracket, 0);
}

llang_simpleParser::GetChildContext::GetChildContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::GetChildContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGetChild(this);
}
void llang_simpleParser::GetChildContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGetChild(this);
}

std::any llang_simpleParser::GetChildContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitGetChild(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConnectToNewContext ------------------------------------------------------------------

tree::TerminalNode* llang_simpleParser::ConnectToNewContext::Connect() {
  return getToken(llang_simpleParser::Connect, 0);
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::ConnectToNewContext::valueExpression() {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(0);
}

llang_simpleParser::ConnectToNewContext::ConnectToNewContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::ConnectToNewContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConnectToNew(this);
}
void llang_simpleParser::ConnectToNewContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConnectToNew(this);
}

std::any llang_simpleParser::ConnectToNewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitConnectToNew(this);
  else
    return visitor->visitChildren(this);
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::valueExpression() {
   return valueExpression(0);
}

llang_simpleParser::ValueExpressionContext* llang_simpleParser::valueExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  llang_simpleParser::ValueExpressionContext *_localctx = _tracker.createInstance<ValueExpressionContext>(_ctx, parentState);
  llang_simpleParser::ValueExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, llang_simpleParser::RuleValueExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case llang_simpleParser::NumericLiteral:
      case llang_simpleParser::Identifier:
      case llang_simpleParser::Colon:
      case llang_simpleParser::SelectArrow:
      case llang_simpleParser::Push:
      case llang_simpleParser::Pop:
      case llang_simpleParser::GlobalList:
      case llang_simpleParser::SelfPlus:
      case llang_simpleParser::Assign:
      case llang_simpleParser::DeleteWord:
      case llang_simpleParser::Delete:
      case llang_simpleParser::FilePrefix: {
        _localctx = _tracker.createInstance<SingleNameContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(122);
        identifier();
        break;
      }

      case llang_simpleParser::OpenBracket: {
        _localctx = _tracker.createInstance<AnonymousListContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(123);
        match(llang_simpleParser::OpenBracket);
        setState(134);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1564334) != 0) {
          setState(124);
          listContent();
          setState(131);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1572526) != 0) {
            setState(126);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == llang_simpleParser::Comma) {
              setState(125);
              match(llang_simpleParser::Comma);
            }
            setState(128);
            listContent();
            setState(133);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(136);
        match(llang_simpleParser::CloseBracket);
        break;
      }

      case llang_simpleParser::Connect: {
        _localctx = _tracker.createInstance<ConnectToNewContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(137);
        match(llang_simpleParser::Connect);
        setState(138);
        valueExpression(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(147);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<GetChildContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleValueExpression);
        setState(141);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(142);
        match(llang_simpleParser::OpenBracket);
        setState(143);
        match(llang_simpleParser::NumericLiteral);
        setState(144);
        match(llang_simpleParser::CloseBracket); 
      }
      setState(149);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ListContentContext ------------------------------------------------------------------

llang_simpleParser::ListContentContext::ListContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t llang_simpleParser::ListContentContext::getRuleIndex() const {
  return llang_simpleParser::RuleListContent;
}

void llang_simpleParser::ListContentContext::copyFrom(ListContentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ListContentValueContext ------------------------------------------------------------------

llang_simpleParser::ValueExpressionContext* llang_simpleParser::ListContentValueContext::valueExpression() {
  return getRuleContext<llang_simpleParser::ValueExpressionContext>(0);
}

llang_simpleParser::ListContentValueContext::ListContentValueContext(ListContentContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::ListContentValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListContentValue(this);
}
void llang_simpleParser::ListContentValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListContentValue(this);
}

std::any llang_simpleParser::ListContentValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitListContentValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListContentListContext ------------------------------------------------------------------

llang_simpleParser::ListExpressionContext* llang_simpleParser::ListContentListContext::listExpression() {
  return getRuleContext<llang_simpleParser::ListExpressionContext>(0);
}

tree::TerminalNode* llang_simpleParser::ListContentListContext::SemiColon() {
  return getToken(llang_simpleParser::SemiColon, 0);
}

llang_simpleParser::ListContentListContext::ListContentListContext(ListContentContext *ctx) { copyFrom(ctx); }

void llang_simpleParser::ListContentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListContentList(this);
}
void llang_simpleParser::ListContentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListContentList(this);
}

std::any llang_simpleParser::ListContentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitListContentList(this);
  else
    return visitor->visitChildren(this);
}
llang_simpleParser::ListContentContext* llang_simpleParser::listContent() {
  ListContentContext *_localctx = _tracker.createInstance<ListContentContext>(_ctx, getState());
  enterRule(_localctx, 6, llang_simpleParser::RuleListContent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<llang_simpleParser::ListContentListContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(150);
      listExpression();
      setState(151);
      match(llang_simpleParser::SemiColon);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<llang_simpleParser::ListContentValueContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(153);
      valueExpression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

llang_simpleParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::Identifier() {
  return getToken(llang_simpleParser::Identifier, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::NumericLiteral() {
  return getToken(llang_simpleParser::NumericLiteral, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::Colon() {
  return getToken(llang_simpleParser::Colon, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::SelectArrow() {
  return getToken(llang_simpleParser::SelectArrow, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::Push() {
  return getToken(llang_simpleParser::Push, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::Pop() {
  return getToken(llang_simpleParser::Pop, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::GlobalList() {
  return getToken(llang_simpleParser::GlobalList, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::SelfPlus() {
  return getToken(llang_simpleParser::SelfPlus, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::Assign() {
  return getToken(llang_simpleParser::Assign, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::DeleteWord() {
  return getToken(llang_simpleParser::DeleteWord, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::Delete() {
  return getToken(llang_simpleParser::Delete, 0);
}

tree::TerminalNode* llang_simpleParser::IdentifierContext::FilePrefix() {
  return getToken(llang_simpleParser::FilePrefix, 0);
}


size_t llang_simpleParser::IdentifierContext::getRuleIndex() const {
  return llang_simpleParser::RuleIdentifier;
}

void llang_simpleParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void llang_simpleParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<llang_simpleListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


std::any llang_simpleParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<llang_simpleVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

llang_simpleParser::IdentifierContext* llang_simpleParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 8, llang_simpleParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case llang_simpleParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        match(llang_simpleParser::Identifier);
        break;
      }

      case llang_simpleParser::NumericLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(157);
        match(llang_simpleParser::NumericLiteral);
        break;
      }

      case llang_simpleParser::Colon: {
        enterOuterAlt(_localctx, 3);
        setState(158);
        match(llang_simpleParser::Colon);
        break;
      }

      case llang_simpleParser::SelectArrow: {
        enterOuterAlt(_localctx, 4);
        setState(159);
        match(llang_simpleParser::SelectArrow);
        break;
      }

      case llang_simpleParser::Push: {
        enterOuterAlt(_localctx, 5);
        setState(160);
        match(llang_simpleParser::Push);
        break;
      }

      case llang_simpleParser::Pop: {
        enterOuterAlt(_localctx, 6);
        setState(161);
        match(llang_simpleParser::Pop);
        break;
      }

      case llang_simpleParser::GlobalList: {
        enterOuterAlt(_localctx, 7);
        setState(162);
        match(llang_simpleParser::GlobalList);
        break;
      }

      case llang_simpleParser::SelfPlus: {
        enterOuterAlt(_localctx, 8);
        setState(163);
        match(llang_simpleParser::SelfPlus);
        break;
      }

      case llang_simpleParser::Assign: {
        enterOuterAlt(_localctx, 9);
        setState(164);
        match(llang_simpleParser::Assign);
        break;
      }

      case llang_simpleParser::DeleteWord: {
        enterOuterAlt(_localctx, 10);
        setState(165);
        match(llang_simpleParser::DeleteWord);
        break;
      }

      case llang_simpleParser::Delete: {
        enterOuterAlt(_localctx, 11);
        setState(166);
        match(llang_simpleParser::Delete);
        break;
      }

      case llang_simpleParser::FilePrefix: {
        enterOuterAlt(_localctx, 12);
        setState(167);
        match(llang_simpleParser::FilePrefix);
        setState(168);
        match(llang_simpleParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool llang_simpleParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return valueExpressionSempred(antlrcpp::downCast<ValueExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool llang_simpleParser::valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void llang_simpleParser::initialize() {
  ::antlr4::internal::call_once(llang_simpleParserOnceFlag, llang_simpleParserInitialize);
}
