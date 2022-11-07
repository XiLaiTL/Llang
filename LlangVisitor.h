#pragma once
#include "llang_simpleBaseVisitor.h"
//#include <array> //could not use import<array>; could not use array
import <string>;
import <vector>;
import <map>;
import <functional>;
import <any>;
import <ranges>;
import llang_utils;
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
    struct LlangList {
    public:
        string name;
        vector<string> listContent;
        LlangEnvironment* env;//TODO: or use unique_ptr
        bool isTemporary;
        function<void()> temporaryFunction;
        LlangList() {}
        LlangList(const string_view& _name, const vector<string>&_listContent, LlangEnvironment* _env, bool _isTemporary=false, function<void()> _temporaryFunction = []() {}) :
            name(_name), listContent(_listContent), isTemporary(_isTemporary), temporaryFunction(_temporaryFunction) {
            env = _env;
        }
        auto push(const string_view& name)->void { listContent.push_back(string(name)); }
        auto pop()->void { listContent.pop_back(); }
        auto value()->string const { listContent[0]; }
        auto rotate(const string_view& _number)->void;
        auto deleteSelf()->void;
        auto getChild(int number)->LlangList;
        auto runContent()->void;
        auto dealConstant()->void;
    };
    static auto EnvMap = map<string, LlangEnvironment* >{};
    static const vector<string> constant{ "@"s,"0"s,"1"s,"2"s,"3"s,"4"s,"5"s,"6"s,"7"s,"8"s,"9"s,"10"s,"11"s,"out"s,"print"s,"del"s,">"s,"<"s,"="s,"->"s,"~"s,":"s,
        "a"s,"b"s,"c"s,"d"s,"e"s,"f"s,"g"s,"h"s,"i"s,"j"s,"k"s,"l"s,"m"s,"n"s,"o"s,"p"s,"q"s,"r"s,"s"s,"t"s,"u"s,"v"s,"w"s,"x"s,"y"s,"z"s,"_"s };
    class LlangEnvironment {
//      using getLlangList = LlangList*(*)();
    public:
        map<string, LlangList > vars{}; //TODO: use ptr or just value
        map<string, function<LlangList()>> later{};
        map<string, LlangList > anonymous{};
        string name;
        LlangEnvironment(const string_view& _name) {
            name = string(_name); EnvMap[name] = this; error = LlangList("error"s, {}, this);
            if(name== "global"s) reInit();
        }
        auto varsNow(const string_view& name)->LlangList&;
        auto clear()->void;
        auto static getGlobalEnvironment()->LlangEnvironment*;
        LlangList error;
        LlangList temp;
    private:
        static LlangEnvironment* GlobalEnvironment;
        auto reInit()->void;
    };

    class LlangVisitor :
        public llang_simpleBaseVisitor
    {
    private:
        LlangEnvironment* env;
    public:
        LlangVisitor(LlangEnvironment* _env) :llang_simpleBaseVisitor(){
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

