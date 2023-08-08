
// Generated from SysY.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace front {


class  SysYLexer : public antlr4::Lexer {
public:
  enum {
    Int = 1, Float = 2, Void = 3, Const = 4, Return = 5, If = 6, Else = 7, 
    For = 8, While = 9, Do = 10, Break = 11, Continue = 12, Lparen = 13, 
    Rparen = 14, Lbrkt = 15, Rbrkt = 16, Lbrace = 17, Rbrace = 18, Comma = 19, 
    Semicolon = 20, Question = 21, Colon = 22, Assign = 23, Minus = 24, 
    Exclamation = 25, Tilde = 26, Addition = 27, Multiplication = 28, Division = 29, 
    Modulo = 30, LAND = 31, LOR = 32, EQ = 33, NEQ = 34, LT = 35, LE = 36, 
    GT = 37, GE = 38, IntLiteral = 39, FloatLiteral = 40, Identifier = 41, 
    STRING = 42, WS = 43, LINE_COMMENT = 44, COMMENT = 45
  };

  explicit SysYLexer(antlr4::CharStream *input);

  ~SysYLexer() override;


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

}  // namespace front
