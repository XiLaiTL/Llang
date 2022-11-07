
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "llang_simpleParser.h"


namespace llang {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by llang_simpleParser.
 */
class  llang_simpleVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by llang_simpleParser.
   */
    virtual std::any visitApplication(llang_simpleParser::ApplicationContext *context) = 0;

    virtual std::any visitDefineExpression(llang_simpleParser::DefineExpressionContext *context) = 0;

    virtual std::any visitPopExpression(llang_simpleParser::PopExpressionContext *context) = 0;

    virtual std::any visitPushExpression(llang_simpleParser::PushExpressionContext *context) = 0;

    virtual std::any visitSelectExpression(llang_simpleParser::SelectExpressionContext *context) = 0;

    virtual std::any visitRunExpression(llang_simpleParser::RunExpressionContext *context) = 0;

    virtual std::any visitDeleteExpression(llang_simpleParser::DeleteExpressionContext *context) = 0;

    virtual std::any visitAssignmentExpression(llang_simpleParser::AssignmentExpressionContext *context) = 0;

    virtual std::any visitSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext *context) = 0;

    virtual std::any visitParenExpression(llang_simpleParser::ParenExpressionContext *context) = 0;

    virtual std::any visitSingleName(llang_simpleParser::SingleNameContext *context) = 0;

    virtual std::any visitAnonymousList(llang_simpleParser::AnonymousListContext *context) = 0;

    virtual std::any visitGetChild(llang_simpleParser::GetChildContext *context) = 0;

    virtual std::any visitConnectToNew(llang_simpleParser::ConnectToNewContext *context) = 0;

    virtual std::any visitListContentList(llang_simpleParser::ListContentListContext *context) = 0;

    virtual std::any visitListContentValue(llang_simpleParser::ListContentValueContext *context) = 0;

    virtual std::any visitIdentifier(llang_simpleParser::IdentifierContext *context) = 0;


};

}  // namespace llang
