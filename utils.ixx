module;
#include <sstream>
#include<array>
import <ctime>;
import <iostream>;
import <string>;
import <map>;
import <chrono>;
using std::string;
using std::map;
using std::cout, std::operator<<, std::endl;
using std::stringstream;

export module llang_utils;
namespace llang {
	enum class LLBaseOutPutType {
		LLTestOutput, LLOutput
	};
	export using LLBaseOutPutType::LLTestOutput;
	export using LLBaseOutPutType::LLOutput;
	auto stringQueue = stringstream{};
	export auto LLPrint(auto message,LLBaseOutPutType outputType = LLTestOutput)->void {
		cout << message;
		if (outputType == LLOutput)
			stringQueue << message;
	}
	export auto LLPrintln(auto message, LLBaseOutPutType outputType = LLTestOutput)->void {
		cout << message <<endl;
		if (outputType == LLOutput)
			stringQueue << message << endl;
	}
	export auto LLPrintALL()->void { cout << stringQueue.str() << endl; }

	export auto LocalTimeNormalize()->string;
	export auto LocalTimeNow()->string;

	export constexpr auto enumStringToInt(const char* name)->unsigned long long;
	export constexpr unsigned long long operator"" L(const char* _Str, std::size_t _Len) { return enumStringToInt(_Str);}
}

module:private;
constexpr auto llang::enumStringToInt(const char* name)->unsigned long long {
	auto result = unsigned long long{ 0 };
	for (auto j = 0; name[j]!='\0'; j++) {
		result = (result * 131) + name[j];
	}
	return result;
}
auto llang::LocalTimeNormalize()->string
{
	auto secSinceEpoch = std::time_t{ std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) };    //Seconds since the Epoch
	auto calendarTime = tm{};
	localtime_s(&calendarTime,&secSinceEpoch);    //转换成本地日历时间
	auto usrdefFormat = std::array<char, 50>{0};    //自定义格式存储位置
	strftime(usrdefFormat.data(), 50, "%Y%m%d%H%M%S", &calendarTime);    //格式：20191101135525
	return string(usrdefFormat.data());
}
auto llang::LocalTimeNow()->string
{
	auto t1 = std::chrono::high_resolution_clock::now();
	return std::to_string(t1.time_since_epoch().count());
}