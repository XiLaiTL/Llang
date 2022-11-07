
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace llang {


class  llang_simpleParser : public antlr4::Parser {
public:
  enum {
    NumericLiteral = 1, Identifier = 2, OpenBracket = 3, CloseBracket = 4, 
    OpenParen = 5, CloseParen = 6, Colon = 7, SemiColon = 8, SelectArrow = 9, 
    Push = 10, Pop = 11, GlobalList = 12, Comma = 13, SelfPlus = 14, Assign = 15, 
    DeleteWord = 16, Delete = 17, Connect = 18, Seperator = 19, FilePrefix = 20, 
    WS = 21
  };

  enum {
    RuleApplication = 0, RuleListExpression = 1, RuleValueExpression = 2, 
    RuleListContent = 3, RuleIdentifier = 4
  };

  explicit llang_simpleParser(antlr4::TokenStream *input);

  llang_simpleParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~llang_simpleParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ApplicationContext;
  class ListExpressionContext;
  class ValueExpressionContext;
  class ListContentContext;
  class IdentifierContext; 

  class  ApplicationContext : public antlr4::ParserRuleContext {
  public:
    ApplicationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ListContentContext *> listContent();
    ListContentContext* listContent(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ApplicationContext* application();

  class  ListExpressionContext : public antlr4::ParserRuleContext {
  public:
    ListExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ListExpressionContext() = default;
    void copyFrom(ListExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DeleteExpressionContext : public ListExpressionContext {
  public:
    DeleteExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> right;
    antlr4::tree::TerminalNode *Delete();
    antlr4::tree::TerminalNode *DeleteWord();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DefineExpressionContext : public ListExpressionContext {
  public:
    DefineExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::IdentifierContext *identifierContext = nullptr;
    std::vector<IdentifierContext *> left;
    llang_simpleParser::ValueExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Colon();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    ValueExpressionContext *valueExpression();
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RunExpressionContext : public ListExpressionContext {
  public:
    RunExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> left;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentExpressionContext : public ListExpressionContext {
  public:
    AssignmentExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> left;
    llang_simpleParser::ValueExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Assign();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExpressionContext : public ListExpressionContext {
  public:
    ParenExpressionContext(ListExpressionContext *ctx);

    antlr4::tree::TerminalNode *OpenParen();
    ListExpressionContext *listExpression();
    antlr4::tree::TerminalNode *CloseParen();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PopExpressionContext : public ListExpressionContext {
  public:
    PopExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> left;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Pop();
    antlr4::tree::TerminalNode* Pop(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelfPlusExpressionContext : public ListExpressionContext {
  public:
    SelfPlusExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> left;
    antlr4::tree::TerminalNode *SelfPlus();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PushExpressionContext : public ListExpressionContext {
  public:
    PushExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> left;
    std::vector<ValueExpressionContext *> right;
    antlr4::tree::TerminalNode *Push();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelectExpressionContext : public ListExpressionContext {
  public:
    SelectExpressionContext(ListExpressionContext *ctx);

    llang_simpleParser::ValueExpressionContext *valueExpressionContext = nullptr;
    std::vector<ValueExpressionContext *> left;
    std::vector<ValueExpressionContext *> right;
    antlr4::tree::TerminalNode *SelectArrow();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Seperator();
    antlr4::tree::TerminalNode* Seperator(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ListExpressionContext* listExpression();

  class  ValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    ValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ValueExpressionContext() = default;
    void copyFrom(ValueExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleNameContext : public ValueExpressionContext {
  public:
    SingleNameContext(ValueExpressionContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AnonymousListContext : public ValueExpressionContext {
  public:
    AnonymousListContext(ValueExpressionContext *ctx);

    antlr4::tree::TerminalNode *OpenBracket();
    antlr4::tree::TerminalNode *CloseBracket();
    std::vector<ListContentContext *> listContent();
    ListContentContext* listContent(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GetChildContext : public ValueExpressionContext {
  public:
    GetChildContext(ValueExpressionContext *ctx);

    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *OpenBracket();
    antlr4::tree::TerminalNode *NumericLiteral();
    antlr4::tree::TerminalNode *CloseBracket();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConnectToNewContext : public ValueExpressionContext {
  public:
    ConnectToNewContext(ValueExpressionContext *ctx);

    antlr4::tree::TerminalNode *Connect();
    ValueExpressionContext *valueExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ValueExpressionContext* valueExpression();
  ValueExpressionContext* valueExpression(int precedence);
  class  ListContentContext : public antlr4::ParserRuleContext {
  public:
    ListContentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ListContentContext() = default;
    void copyFrom(ListContentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ListContentValueContext : public ListContentContext {
  public:
    ListContentValueContext(ListContentContext *ctx);

    ValueExpressionContext *valueExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListContentListContext : public ListContentContext {
  public:
    ListContentListContext(ListContentContext *ctx);

    ListExpressionContext *listExpression();
    antlr4::tree::TerminalNode *SemiColon();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ListContentContext* listContent();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *NumericLiteral();
    antlr4::tree::TerminalNode *Colon();
    antlr4::tree::TerminalNode *SelectArrow();
    antlr4::tree::TerminalNode *Push();
    antlr4::tree::TerminalNode *Pop();
    antlr4::tree::TerminalNode *GlobalList();
    antlr4::tree::TerminalNode *SelfPlus();
    antlr4::tree::TerminalNode *Assign();
    antlr4::tree::TerminalNode *DeleteWord();
    antlr4::tree::TerminalNode *Delete();
    antlr4::tree::TerminalNode *FilePrefix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace llang
