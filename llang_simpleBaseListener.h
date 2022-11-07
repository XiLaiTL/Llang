
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "llang_simpleListener.h"


namespace llang {

/**
 * This class provides an empty implementation of llang_simpleListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  llang_simpleBaseListener : public llang_simpleListener {
public:

  virtual void enterApplication(llang_simpleParser::ApplicationContext * /*ctx*/) override { }
  virtual void exitApplication(llang_simpleParser::ApplicationContext * /*ctx*/) override { }

  virtual void enterDefineExpression(llang_simpleParser::DefineExpressionContext * /*ctx*/) override { }
  virtual void exitDefineExpression(llang_simpleParser::DefineExpressionContext * /*ctx*/) override { }

  virtual void enterPopExpression(llang_simpleParser::PopExpressionContext * /*ctx*/) override { }
  virtual void exitPopExpression(llang_simpleParser::PopExpressionContext * /*ctx*/) override { }

  virtual void enterPushExpression(llang_simpleParser::PushExpressionContext * /*ctx*/) override { }
  virtual void exitPushExpression(llang_simpleParser::PushExpressionContext * /*ctx*/) override { }

  virtual void enterSelectExpression(llang_simpleParser::SelectExpressionContext * /*ctx*/) override { }
  virtual void exitSelectExpression(llang_simpleParser::SelectExpressionContext * /*ctx*/) override { }

  virtual void enterRunExpression(llang_simpleParser::RunExpressionContext * /*ctx*/) override { }
  virtual void exitRunExpression(llang_simpleParser::RunExpressionContext * /*ctx*/) override { }

  virtual void enterDeleteExpression(llang_simpleParser::DeleteExpressionContext * /*ctx*/) override { }
  virtual void exitDeleteExpression(llang_simpleParser::DeleteExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(llang_simpleParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(llang_simpleParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext * /*ctx*/) override { }
  virtual void exitSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext * /*ctx*/) override { }

  virtual void enterParenExpression(llang_simpleParser::ParenExpressionContext * /*ctx*/) override { }
  virtual void exitParenExpression(llang_simpleParser::ParenExpressionContext * /*ctx*/) override { }

  virtual void enterSingleName(llang_simpleParser::SingleNameContext * /*ctx*/) override { }
  virtual void exitSingleName(llang_simpleParser::SingleNameContext * /*ctx*/) override { }

  virtual void enterAnonymousList(llang_simpleParser::AnonymousListContext * /*ctx*/) override { }
  virtual void exitAnonymousList(llang_simpleParser::AnonymousListContext * /*ctx*/) override { }

  virtual void enterGetChild(llang_simpleParser::GetChildContext * /*ctx*/) override { }
  virtual void exitGetChild(llang_simpleParser::GetChildContext * /*ctx*/) override { }

  virtual void enterConnectToNew(llang_simpleParser::ConnectToNewContext * /*ctx*/) override { }
  virtual void exitConnectToNew(llang_simpleParser::ConnectToNewContext * /*ctx*/) override { }

  virtual void enterListContentList(llang_simpleParser::ListContentListContext * /*ctx*/) override { }
  virtual void exitListContentList(llang_simpleParser::ListContentListContext * /*ctx*/) override { }

  virtual void enterListContentValue(llang_simpleParser::ListContentValueContext * /*ctx*/) override { }
  virtual void exitListContentValue(llang_simpleParser::ListContentValueContext * /*ctx*/) override { }

  virtual void enterIdentifier(llang_simpleParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(llang_simpleParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace llang
