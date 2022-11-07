#include "LlangVisitor.h"
using std::views::iota;
using std::stoi;
using namespace llang;

auto LlangList::rotate(const string_view& _number) -> void
{
	auto number= stoi(string(_number));
	while (number > 0) {
		listContent.push_back(listContent[0]);
		listContent.erase(listContent.begin());
		number--;
	}
}

auto LlangList::deleteSelf() -> void
{
	auto v = constant;
	if (std::find(v.begin(), v.end(), name) == v.end()) {
		env->vars.erase(name);
	}
}

auto LlangList::getChild(int number) -> LlangList
{
	if (number >= 0)
		return env->varsNow(listContent[number]);
	else
		return env->varsNow(listContent[listContent.size() + number]);
}

auto LlangList::runContent() -> void
{
	LLPrintln("====running "+name);
	if (isTemporary) {
		temporaryFunction();
		return;
	}
	for (auto it = 0; it < listContent.size(); it++) {
		auto childList = env->varsNow(listContent[it]);
		if (it == 0 && childList.name == name) {
			LLPrintln("====constant "+name);
			childList.dealConstant();
			break;
		}
		LLPrint("====");
		childList.runContent();
	}
}

auto LlangList::dealConstant() -> void
{
	auto GlobalEnvironment = env->getGlobalEnvironment();
	switch (enumStringToInt(name.data())) {
		case "out"L:{
			if (GlobalEnvironment->vars.at("@"s).listContent.size() == 1) return;
			auto last = GlobalEnvironment->vars.at("@"s).getChild(-1);
			auto names = string{ "" };
			for (auto i = 0; i < last.listContent.size(); i++) {
				if(i > 0) names += ",";
				auto ite = last.listContent[i].find("$");
				names += ite != string::npos
					? last.listContent[i].replace(ite, 1, "")
					: last.listContent[i];
			}
			LLPrintln(last.name + ":[" + names + "]", LLOutput);
		}break;
		case "print"L:{
			auto names =  string{ "" };
			for (auto i = 1; i < listContent.size(); i++) {
				names += env->varsNow(listContent[i]).name;
			}
			LLPrintln(names, LLOutput);
		}break;
		case "comment"L:{
			auto names = string{ "" };
			for (auto i = 1; i < listContent.size(); i++) {
				if (i > 1) names += " ";
				auto ite = listContent[i].find("$");
				names += ite != string::npos
					? listContent[i].replace(ite, 1, "")
					: listContent[i];
			}
			LLPrintln(names,LLOutput);
		}break;
		case "0"L:case "1"L: case "2"L :case "3"L: case "4"L: case "5"L: case "6"L: 
		case "7"L: case "8"L: case "9"L: case "10"L: case "11"L:{
			if (GlobalEnvironment->vars.at("@"s).listContent.size() == 1) return;
			auto last = GlobalEnvironment->vars.at("@"s).getChild(-1);
			last.rotate(name);
		}break;
		case "same_run"L:{
			if (listContent.size() >= 3) {
				auto controlList = env->varsNow(listContent[1]);
				auto controlList2 = env->varsNow(listContent[2]);
				LLPrintln("====same:["+ controlList.name +","+controlList2.name+"]");
				if (!env->vars.contains("logic"))
					env->vars[ "logic"]= LlangList("logic", {}, env);
				env->vars.at("logic").listContent.push_back(std::to_string(controlList.name == controlList2.name));
			}
		}break;
		case ":"L:{
			LLPrintln("now insert new var");
			if (listContent.size() >= 3) { 
				auto controlList = env->varsNow(listContent[2]);
				LLPrintln("name:"+controlList.name);
				env->vars[listContent[1]]= LlangList(listContent[1], controlList.listContent, env);
				LLPrintln("insert:" + listContent[1]+controlList.listContent[0]);
			}
		}break;
		case "del"L: case "~"L:{
			if (listContent.size() >= 2) {
				auto controlList = env->varsNow(listContent[1]);
				controlList.deleteSelf();
				LLPrintln("====remove " + listContent[1]);
			}
		}break;
		case ">"L:{
			if (listContent.size() >= 2) {
				auto controlList = env->varsNow(listContent[1]);
				controlList.pop();
				LLPrintln("====pop " + listContent[1]);
			}
		}break;
		case "<"L:{
			if (listContent.size() >= 3) {
				auto controlList = env->varsNow(listContent[1]);
				controlList.push(listContent[2]);
				LLPrintln("====push "+listContent[2]+" to "+listContent[1]);
			}
		}break;
		case "="L:{
			//TODO: fake assign
			if (listContent.size() >= 3) {
				auto controlList = env->varsNow(listContent[1]);
				auto controlList2 = env->varsNow(listContent[2]);
				env->vars.at(controlList.name) = LlangList(controlList.name, vector(controlList2.listContent), env);
			}
		}break;
		case "->"L:{
			if (listContent.size() >= 3) {
				GlobalEnvironment->vars.at("@").push(listContent[2]);
				auto controlList = env->varsNow(listContent[1]);
				controlList.runContent();
				GlobalEnvironment->vars.at("@").pop();
			}
		}break;
	}
}
LlangEnvironment* LlangEnvironment::GlobalEnvironment = nullptr;
auto LlangEnvironment::varsNow(const string_view& _name) -> LlangList&
{
	auto name = string(_name);
	LLPrintln("now find" + name);
	if (name.find("$anonymous"s) != string::npos) {
		if (anonymous.contains(name)) { return anonymous.at(name); }
		else { LLPrintln("anonymous error"); return error; }
	//	return anonymous.contains(name) ? anonymous.at(name) : (LLPrintln("anonymous error"), error);//TODO: use exception or not
	}

	else if (vars.contains(name)) { return vars.at(name); }
	else if (later.contains(name)) { temp = later.at(name)(); return temp; }
	else if (this == GlobalEnvironment) { LLPrintln("normal error"); return error; }
	else { return GlobalEnvironment->varsNow(name); }
	//else {
	//	return vars.contains(name) ? vars.at(name)
	//		: later.contains(name) ? (temp = later.at(name)(), temp)
	//					: name.find("#"s) != string::npos ?  
	//		: this == GlobalEnvironment ? (LLPrintln("normal error"), error)
	//		: GlobalEnvironment->varsNow(name)
	//		;
	//}
}

auto LlangEnvironment::clear() -> void
{
	vars.clear();
	later.clear();
	anonymous.clear();
}

auto LlangEnvironment::getGlobalEnvironment() -> LlangEnvironment*
{
	if (GlobalEnvironment == nullptr) {
		GlobalEnvironment = new LlangEnvironment("global"s);
	}
	return GlobalEnvironment;
}


auto LlangEnvironment::reInit() -> void
{
	if(name=="global"s)
		for (auto it : constant) {
			auto tempList = LlangList(it, { it }, this);
			vars[ it]=tempList;
		}
}

auto LlangVisitor::visitApplication(llang_simpleParser::ApplicationContext* ctx)->any
{
	if (ctx == nullptr) return nullptr;
	LLPrintln("start"sv);
	for (auto listContent : ctx->listContent()) {
		auto list = any_cast<LlangList>(visit(listContent)) ;
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
			for (auto i:iota(0,size)) {
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
		for (auto leftValueExpression: ctx->left) {
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
		env->later[ name]=[ct,this]()->LlangList { return any_cast<LlangList>(visit(ct)); } ;
		mutableList.push_back(name);
	}
	auto name = "$anonymous"s+LocalTimeNow();
	auto list = LlangList(name, mutableList, env, true);
	env->anonymous[ name]=list ; //just forbid error, if want to change, need change the defineExpression
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
