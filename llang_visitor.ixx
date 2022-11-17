module;

#include "llang_simpleBaseVisitor.h"

export module llang.visitor;

import <string>;
import <vector>;
import <map>;
import <functional>;
import <any>;
import <ranges>;
import llang.utils;
import llang.list;
using namespace std::string_literals;
using namespace std::string_view_literals;
using std::string;
using std::string_view;
using std::vector;
using std::map;
using std::function;
using std::any;
using std::views::iota;

namespace llang {
    export class LlangVisitor :
        public llang_simpleBaseVisitor
    {
    private:
        LlangEnvironment* env;
    public:
        LlangVisitor(LlangEnvironment* _env) :llang_simpleBaseVisitor() {
            env = _env;
        };
        auto virtual visitApplication(llang_simpleParser::ApplicationContext* ctx)->any override;
        auto virtual visitDefineExpression(llang_simpleParser::DefineExpressionContext* ctx)->any override;
        auto virtual visitPopExpression(llang_simpleParser::PopExpressionContext* ctx)->any override;
        auto virtual visitPushExpression(llang_simpleParser::PushExpressionContext* ctx)->any override;
        auto virtual visitSelectExpression(llang_simpleParser::SelectExpressionContext* ctx)->any override;
        auto virtual visitRunExpression(llang_simpleParser::RunExpressionContext* ctx)->any override;
        auto virtual visitDeleteExpression(llang_simpleParser::DeleteExpressionContext* ctx)->any override;
        auto virtual visitAssignmentExpression(llang_simpleParser::AssignmentExpressionContext* ctx)->any override;
        auto virtual visitSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext* ctx)->any override;
        auto virtual visitParenExpression(llang_simpleParser::ParenExpressionContext* ctx)->any override;
        auto virtual visitSingleName(llang_simpleParser::SingleNameContext* ctx)->any override;
        auto virtual visitAnonymousList(llang_simpleParser::AnonymousListContext* ctx)->any override;
        auto virtual visitGetChild(llang_simpleParser::GetChildContext* ctx)->any override;
        auto virtual visitConnectToNew(llang_simpleParser::ConnectToNewContext* ctx)->any override;
        auto virtual visitListContentList(llang_simpleParser::ListContentListContext* ctx)->any override;
        auto virtual visitListContentValue(llang_simpleParser::ListContentValueContext* ctx)->any override;
    };

}


module:private;
using namespace llang;


auto LlangVisitor::visitApplication(llang_simpleParser::ApplicationContext* ctx)->any
{
	if (ctx == nullptr) return nullptr;
//	LLPrintln("start"sv);
	for (auto listContent : ctx->listContent()) {
		auto list = any_cast<LlangList>(visit(listContent));
		list.runContent();
	}
	return LlangList("begin"sv, { "begin"s }, env, true);
	//TODO: figure out the new and no new
}


#define laterRun \
	if (ctx == nullptr) return nullptr;\
	auto name = "$" + ctx->getText();\
	return LlangList(name, { name }, env, true, [ctx, this]()
#define endRun );

auto LlangVisitor::visitDefineExpression(llang_simpleParser::DefineExpressionContext* ctx) -> any
{
	laterRun{
		auto rightList = any_cast<LlangList>(visit(ctx->right));
		for (auto leftIdentifier : ctx->left) {
			LlangList(":"sv, { ":"s,leftIdentifier->getText(),rightList.name }, env, true).dealConstant();
		}
	}endRun;
}
auto LlangVisitor::visitPopExpression(llang_simpleParser::PopExpressionContext* ctx) -> any
{
	laterRun{
		for (auto leftValueExpression : ctx->left) {
			auto list = any_cast<LlangList> (visit(leftValueExpression));
			auto size = static_cast<int>(ctx->Pop().size());
			for (auto i : iota(0,size)) {
				LlangList(">"sv, { ">"s,list.name }, env).dealConstant();
			}
		}
	}endRun;
}

auto LlangVisitor::visitPushExpression(llang_simpleParser::PushExpressionContext* ctx) -> any
{
	laterRun{
		for (auto leftValueExpression : ctx->left) {
			auto leftList = any_cast<LlangList> (visit(leftValueExpression));
			for (auto rightValueExpression : ctx->right) {
				auto rightList = any_cast<LlangList>(visit(rightValueExpression));
				LlangList("<"sv, { "<"s,leftList.name,rightList.name }, env).dealConstant();
			}
		}
	}endRun;
}

auto LlangVisitor::visitSelectExpression(llang_simpleParser::SelectExpressionContext* ctx) -> any
{
	laterRun{
		for (auto leftValueExpression : ctx->left) {
			auto leftList = any_cast<LlangList> (visit(leftValueExpression));
			for (auto rightValueExpression : ctx->right) {
				auto rightList = any_cast<LlangList>(visit(rightValueExpression));
				LlangList("->"sv, { "->"s,leftList.name,rightList.name }, env).dealConstant();
			}
		}
	}endRun;
}

auto LlangVisitor::visitRunExpression(llang_simpleParser::RunExpressionContext* ctx) -> any
{
	laterRun{
		for (auto leftValueExpression : ctx->left) {
			auto list = any_cast<LlangList>(visit(leftValueExpression));
			list.runContent();
		}
	}endRun;
}

auto LlangVisitor::visitDeleteExpression(llang_simpleParser::DeleteExpressionContext* ctx) -> any
{
	laterRun{
		for (auto rightValueExpression : ctx->right) {
			auto rightList = any_cast<LlangList>(visit(rightValueExpression));
			LlangList("~"sv, { "~",rightList.name }, env).dealConstant();
		}
	}endRun;
}

auto LlangVisitor::visitAssignmentExpression(llang_simpleParser::AssignmentExpressionContext* ctx) -> any
{
	laterRun{
		auto rightList = any_cast<LlangList>(visit(ctx->right));
		for (auto leftValueExpression : ctx->left) {
			auto leftList = any_cast<LlangList>(visit(leftValueExpression));
			LlangList("="sv, { "="s,leftList.name,rightList.name }, env).dealConstant();
			}
	}endRun;
}

auto LlangVisitor::visitSelfPlusExpression(llang_simpleParser::SelfPlusExpressionContext* ctx) -> any
{
	laterRun{
		for (auto leftValueExpression : ctx->left) {
			auto leftList = any_cast<LlangList>(visit(leftValueExpression));
			LlangList("->"sv, { "->"s,"1"s,leftList.name }, env).dealConstant();
		}
	}endRun;
}

auto LlangVisitor::visitParenExpression(llang_simpleParser::ParenExpressionContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	return any_cast<LlangList>(visit(ctx->listExpression()));
}

auto LlangVisitor::visitSingleName(llang_simpleParser::SingleNameContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	auto name = ctx->identifier()->getText();
	return env->varsNow(name);
}

auto LlangVisitor::visitAnonymousList(llang_simpleParser::AnonymousListContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	auto mutableList = vector<string>{};
	for (auto ct : ctx->listContent()) {
		auto name = "$" + ct->getText();
		env->laterInsert(name,[ct, this]()->LlangList { return any_cast<LlangList>(visit(ct)); } );
		mutableList.push_back(name);
	}
	auto name = "$anonymous"s + LocalTimeNow();
	auto list = LlangList(name, mutableList, env, true);
	env->anonymousInsert(name,list); //just forbid error, if want to change, need change the defineExpression
	return list;

}

auto LlangVisitor::visitGetChild(llang_simpleParser::GetChildContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	auto nameList = any_cast<LlangList>(visit(ctx->valueExpression()));
	auto number = std::stoi(ctx->NumericLiteral()->getText());
	auto nameListInEnvironment = env->varsNow(nameList.name);
	return nameListInEnvironment.getChild(number);
}

auto LlangVisitor::visitConnectToNew(llang_simpleParser::ConnectToNewContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	auto nameList = any_cast<LlangList>(visit(ctx->valueExpression()));
	string name = ""s;
	for (auto child : nameList.listContent) {
		auto childList = env->varsNow(child);
		name += childList.name;
	}
	return env->varsNow(name);

}

auto LlangVisitor::visitListContentList(llang_simpleParser::ListContentListContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	auto list = any_cast<LlangList>(visit(ctx->listExpression()));
	return LlangList(list.name + ";", list.listContent, list.env, list.isTemporary, list.temporaryFunction);
	//?? list.name = list.name+";";
}

auto LlangVisitor::visitListContentValue(llang_simpleParser::ListContentValueContext* ctx) -> any
{
	if (ctx == nullptr) return nullptr;
	return any_cast<LlangList>(visit(ctx->valueExpression()));
}



