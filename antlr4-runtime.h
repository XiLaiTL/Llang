#pragma once

#include "antlr4-runtime/antlr4-runtime.h"

namespace antlr4::internal {
	using OnceFlag = std::once_flag;
	using std::call_once;
}