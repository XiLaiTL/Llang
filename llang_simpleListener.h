
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "llang_simpleParser.h"


namespace llang {

/**
 * This interface defines an abstract listener for a parse tree produced by llang_simpleParser.
 */
class  llang_simpleListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterApplication(llang_simpleParser::ApplicationContext *ctx) = 0;
  virtual void exitApplication(llang_simpleParser::ApplicationContext *ctx) = 0;

  virtual void enterDefineExpression(llang_simpleParser::DefineExpressionContext *ctx) = 0;
  virtual void exitDefineExpression(llang_simpleParser::DefineExpressionContext *ctx) = 0;

  virtual void enterPopExpression(llang_simpleParser::PopExpressionContext *ctx) = 0;
  virtual void exitPopExpression(llang_simpleParser::PopExpressionContext *ctx) = 0;

  virtual void enterPushExpression(llang_simpleParser::PushExpressionContext *ctx) = 0;
  virtual void exitPushExpression(llang_simpleParser::PushExpressionContext *ctx) = 0;

  virtual void enterSelectExpression(llang_simpleParser::SelectExpressionContext *ctx) = 0;
  virtual void exitSelectExpression(llang_simpleParser::SelectExpressionContext *ctx) = 0;

  virtual void enterRunExpression(llang_simpleParser::RunExpressionContext *ctx) = 0;
  virtual void exitRunExpression(llang_simpleParser::RunExpressionContext *ctx) = 0;

  virtual void enterDeleteExpression(llang_simpleParser::DeleteExpressionContext *ctx) = 0;
  virtual void exitDeleteExpression(llang_simpleParser::DeleteExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(llang_simpleParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(llang_simpleParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext *ctx) = 0;
  virtual void exitSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext *ctx) = 0;

  virtual void enterParenExpression(llang_simpleParser::ParenExpressionContext *ctx) = 0;
  virtual void exitParenExpression(llang_simpleParser::ParenExpressionContext *ctx) = 0;

  virtual void enterSingleName(llang_simpleParser::SingleNameContext *ctx) = 0;
  virtual void exitSingleName(llang_simpleParser::SingleNameContext *ctx) = 0;

  virtual void enterAnonymousList(llang_simpleParser::AnonymousListContext *ctx) = 0;
  virtual void exitAnonymousList(llang_simpleParser::AnonymousListContext *ctx) = 0;

  virtual void enterGetChild(llang_simpleParser::GetChildContext *ctx) = 0;
  virtual void exitGetChild(llang_simpleParser::GetChildContext *ctx) = 0;

  virtual void enterConnectToNew(llang_simpleParser::ConnectToNewContext *ctx) = 0;
  virtual void exitConnectToNew(llang_simpleParser::ConnectToNewContext *ctx) = 0;

  virtual void enterListContentList(llang_simpleParser::ListContentListContext *ctx) = 0;
  virtual void exitListContentList(llang_simpleParser::ListContentListContext *ctx) = 0;

  virtual void enterListContentValue(llang_simpleParser::ListContentValueContext *ctx) = 0;
  virtual void exitListContentValue(llang_simpleParser::ListContentValueContext *ctx) = 0;

  virtual void enterIdentifier(llang_simpleParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(llang_simpleParser::IdentifierContext *ctx) = 0;


};

}  // namespace llang
