
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "llang_simpleVisitor.h"


namespace llang {

/**
 * This class provides an empty implementation of llang_simpleVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  llang_simpleBaseVisitor : public llang_simpleVisitor {
public:

  virtual std::any visitApplication(llang_simpleParser::ApplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefineExpression(llang_simpleParser::DefineExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPopExpression(llang_simpleParser::PopExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPushExpression(llang_simpleParser::PushExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectExpression(llang_simpleParser::SelectExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRunExpression(llang_simpleParser::RunExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeleteExpression(llang_simpleParser::DeleteExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentExpression(llang_simpleParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpression(llang_simpleParser::ParenExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleName(llang_simpleParser::SingleNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnonymousList(llang_simpleParser::AnonymousListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGetChild(llang_simpleParser::GetChildContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConnectToNew(llang_simpleParser::ConnectToNewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListContentList(llang_simpleParser::ListContentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListContentValue(llang_simpleParser::ListContentValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(llang_simpleParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace llang
