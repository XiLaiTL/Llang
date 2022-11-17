export module llang.list;

import <string>;
import <vector>;
import <map>;
import <functional>;
import <any>;
import llang.utils;
using namespace std::string_literals;
using namespace std::string_view_literals;
using std::string;
using std::string_view;
using std::vector;
using std::map;
using std::function;
using std::any;


namespace llang {
	class LlangEnvironment;

	auto defaultFun = []() {};
    export class LlangList {
    public:
        string name;
        vector<string> listContent;
        LlangEnvironment* env;//TODO: or use unique_ptr
        bool isTemporary;
        function<void()> temporaryFunction;
        LlangList() {}
        LlangList(const string_view& _name, const vector<string>& _listContent, LlangEnvironment* _env, bool _isTemporary = false, function<void()> _temporaryFunction = defaultFun) :
            name(_name), listContent(_listContent), isTemporary(_isTemporary), temporaryFunction(_temporaryFunction) {
            env = _env;
        }
        auto push(const string_view& name) -> void { listContent.push_back(string(name)); }
        auto pop() -> void { listContent.pop_back(); }
        auto value() -> string const { return listContent[0]; }
        auto rotate(const string_view& _number) -> void;
        auto deleteSelf() -> void;
        auto getChild(int number) -> LlangList&;
        auto runContent() -> void;
        auto dealConstant() -> void;
    };

	export auto EnvMap = map<string, LlangEnvironment* >{};
	const vector<string> constant{ "@"s,"0"s,"1"s,"2"s,"3"s,"4"s,"5"s,"6"s,"7"s,"8"s,"9"s,"10"s,"11"s,"out"s,"print"s,"del"s,">"s,"<"s,"="s,"->"s,"~"s,":"s,
		"a"s,"b"s,"c"s,"d"s,"e"s,"f"s,"g"s,"h"s,"i"s,"j"s,"k"s,"l"s,"m"s,"n"s,"o"s,"p"s,"q"s,"r"s,"s"s,"t"s,"u"s,"v"s,"w"s,"x"s,"y"s,"z"s,"_"s };

	export class LlangEnvironment {
		//      using getLlangList = LlangList*(*)();
	public:

		map<string, LlangList > vars{}; //TODO: use ptr or just value
		map<string, function<LlangList()>> later{};
		map<string, LlangList > anonymous{};
		LlangList error;
		LlangList temp;
		string name;
		LlangEnvironment(const string_view& _name) :vars(),later(),anonymous() {
			name = string(_name);
			EnvMap.insert({ name, this });

			//error = LlangList("error"s, {}, this);

			if (name == "global"s) reInit();
		}
		auto varsInsert(string name, LlangList list) -> void;
		auto laterInsert(string name, function<LlangList()> list) -> void;
		auto anonymousInsert(string name, LlangList list) -> void;
		auto varsNow(const string_view& name) -> LlangList&;
		
		auto clear() -> void;
	private:
		auto reInit() -> void;
	};
	export auto GlobalEnvironmentAddress = LlangEnvironment("global"s);
	export auto getGlobalEnvironment() -> LlangEnvironment* { return &GlobalEnvironmentAddress; }
}

module :private;
using namespace llang;

auto LlangList::rotate(const string_view& _number) -> void
{
	auto number = stoi(string(_number));
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

auto LlangList::getChild(int number) -> LlangList&
{
	if (number >= 0)
		return env->varsNow(listContent[number]);
	else
		return env->varsNow(listContent[listContent.size() + number]);
}

auto LlangList::runContent() -> void
{
	LLPrintln("====running "s + name);
	if (isTemporary) {
		temporaryFunction();
		return;
	}
	for (auto it = 0; it < listContent.size(); it++) {
		auto childList = env->varsNow(listContent[it]);
		if (it == 0 && childList.name == name) {
			LLPrintln("====constant "s + name);
			childList.dealConstant();
			break;
		}
		LLPrint("====");
		childList.runContent();
	}
}

auto LlangList::dealConstant() -> void
{
	auto GlobalEnvironment = getGlobalEnvironment();
	switch (enumStringToInt(name.data())) {
	case "out"L: {
		if (GlobalEnvironment->vars.at("@"s).listContent.size() == 1) return;
		auto& last = GlobalEnvironment->vars.at("@"s).getChild(-1);
		auto names = string{ "" };
		for (auto i = 0; i < last.listContent.size(); i++) {
			if (i > 0) names += ",";
			auto ite = last.listContent[i].find("$");
			names += ite != string::npos
				? last.listContent[i].replace(ite, 1, "")
				: last.listContent[i];
		}
		auto snames = last.name + ":["s + names + "]"s;
		LLPrintln(snames , LLOutput);
	}break;
	case "print"L: {
		auto names = string{ "" };
		for (auto i = 1; i < listContent.size(); i++) {
			names += env->varsNow(listContent[i]).name;
		}
		LLPrintln(names, LLOutput);
	}break;
	case "comment"L: {
		auto names = string{ "" };
		for (auto i = 1; i < listContent.size(); i++) {
			if (i > 1) names += " ";
			auto ite = listContent[i].find("$");
			names += ite != string::npos
				? listContent[i].replace(ite, 1, "")
				: listContent[i];
		}
		LLPrintln(names, LLOutput);
	}break;
	case "0"L:case "1"L: case "2"L:case "3"L: case "4"L: case "5"L: case "6"L:
	case "7"L: case "8"L: case "9"L: case "10"L: case "11"L: {
		if (GlobalEnvironment->vars.at("@"s).listContent.size() == 1) return;
		auto& last = GlobalEnvironment->vars.at("@"s).getChild(-1);
		last.rotate(name);
	}break;
	case "same_run"L: {
		if (listContent.size() >= 3) {
			auto& controlList = env->varsNow(listContent[1]);
			auto& controlList2 = env->varsNow(listContent[2]);
			LLPrintln("====same:["s + controlList.name + ","s + controlList2.name + "]"s);
			if (!env->vars.contains("logic"))
				env->vars["logic"] = LlangList("logic", {}, env);
			env->vars.at("logic").listContent.push_back(std::to_string(controlList.name == controlList2.name));
		}
	}break;
	case ":"L: {
		LLPrintln("now insert new var"s);
		if (listContent.size() >= 3) {
			auto& controlList = env->varsNow(listContent[2]);
			LLPrintln("name:"s + controlList.name);
			env->vars[listContent[1]] = LlangList(listContent[1], controlList.listContent, env);
			LLPrintln("insert:"s + listContent[1] + controlList.listContent[0]);
		}
	}break;
	case "del"L: case "~"L: {
		if (listContent.size() >= 2) {
			auto& controlList = env->varsNow(listContent[1]);
			controlList.deleteSelf();
			LLPrintln("====remove "s + listContent[1]);
		}
	}break;
	case ">"L: {
		if (listContent.size() >= 2) {
			auto& controlList = env->varsNow(listContent[1]);
			controlList.pop();
			LLPrintln("====pop "s + listContent[1]);
		}
	}break;
	case "<"L: {
		if (listContent.size() >= 3) {
			auto& controlList = env->varsNow(listContent[1]);
			controlList.push(listContent[2]);
			LLPrintln("====push "s + listContent[2] + " to "s + listContent[1]);
		}
	}break;
	case "="L: {
		//TODO: fake assign
		if (listContent.size() >= 3) {
			auto& controlList = env->varsNow(listContent[1]);
			auto& controlList2 = env->varsNow(listContent[2]);
			env->vars.at(controlList.name) = LlangList(controlList.name, vector(controlList2.listContent), env);
		}
	}break;
	case "->"L: {
		if (listContent.size() >= 3) {
			GlobalEnvironment->vars.at("@").push(listContent[2]);
			auto& controlList = env->varsNow(listContent[1]);
			controlList.runContent();
			GlobalEnvironment->vars.at("@").pop();
		}
	}break;
	}
}

auto LlangEnvironment::varsInsert(string name, LlangList list) -> void
{
	if (vars.contains(name)) vars.at(name) = list;
	else vars.insert({ name,list });
}

auto LlangEnvironment::laterInsert(string name, function<LlangList()> list) -> void
{
	if (later.contains(name)) later.at(name) = list;
	else later.insert({ name,list });
}

auto LlangEnvironment::anonymousInsert(string name, LlangList list) -> void
{
	if (anonymous.contains(name)) anonymous.at(name) = list;
	else anonymous.insert({ name,list });
}

auto LlangEnvironment::varsNow(const string_view& _name) -> LlangList&
{
	auto GlobalEnvironment = getGlobalEnvironment();
	auto name = string(_name);
	LLPrintln("now find"s + name);
	if (name.find("$anonymous"s) != string::npos) {
		if (anonymous.contains(name)) { return anonymous.at(name); }
		else { LLPrintln("anonymous error"s); return error; }
		//	return anonymous.contains(name) ? anonymous.at(name) : (LLPrintln("anonymous error"), error);//TODO: use exception or not
	}

	else if (vars.contains(name)) { return vars.at(name); }
	else if (later.contains(name)) { temp = later.at(name)(); return temp; }
	else if (this == GlobalEnvironment) { LLPrintln("normal error"s); return error; }
	else { return GlobalEnvironment->varsNow(name); }
}

auto LlangEnvironment::clear() -> void
{
	vars.clear();
	later.clear();
	anonymous.clear();
}

auto LlangEnvironment::reInit() -> void
{
	if (name == "global"s)
		for (auto it : constant) {
			auto tempList = LlangList(it, { it }, this);
			vars[it] = tempList;
		}
}