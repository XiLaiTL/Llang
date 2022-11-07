
// Generated from ../antlr/llang_simple.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace llang {


class  llang_simpleLexer : public antlr4::Lexer {
public:
  enum {
    NumericLiteral = 1, Identifier = 2, OpenBracket = 3, CloseBracket = 4, 
    OpenParen = 5, CloseParen = 6, Colon = 7, SemiColon = 8, SelectArrow = 9, 
    Push = 10, Pop = 11, GlobalList = 12, Comma = 13, SelfPlus = 14, Assign = 15, 
    DeleteWord = 16, Delete = 17, Connect = 18, Seperator = 19, FilePrefix = 20, 
    WS = 21
  };

  explicit llang_simpleLexer(antlr4::CharStream *input);

  ~llang_simpleLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace llang
