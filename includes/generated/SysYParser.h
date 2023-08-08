
// Generated from SysY.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace front {


class  SysYParser : public antlr4::Parser {
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

  enum {
    RuleCompUnit = 0, RuleDecl = 1, RuleConstDecl = 2, RuleBType = 3, RuleConstDef = 4, 
    RuleConstInitVal = 5, RuleVarDecl = 6, RuleVarDef = 7, RuleInitVal = 8, 
    RuleFuncDef = 9, RuleFuncType = 10, RuleFuncFparamList = 11, RuleFuncFparam = 12, 
    RuleBlock = 13, RuleBlockItem = 14, RuleStmt = 15, RuleExp = 16, RuleCond = 17, 
    RuleLVal = 18, RuleRVal = 19, RulePrimExp = 20, RuleNumber = 21, RuleUnaryExp = 22, 
    RuleUnaryOp = 23, RuleFuncRparamList = 24, RuleFuncRparam = 25, RuleMulExp = 26, 
    RuleAddExp = 27, RuleRelExp = 28, RuleEqExp = 29, RuleLAndExp = 30, 
    RuleLOrExp = 31, RuleConstExp = 32
  };

  explicit SysYParser(antlr4::TokenStream *input);

  SysYParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SysYParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class ConstInitValContext;
  class VarDeclContext;
  class VarDefContext;
  class InitValContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFparamListContext;
  class FuncFparamContext;
  class BlockContext;
  class BlockItemContext;
  class StmtContext;
  class ExpContext;
  class CondContext;
  class LValContext;
  class RValContext;
  class PrimExpContext;
  class NumberContext;
  class UnaryExpContext;
  class UnaryOpContext;
  class FuncRparamListContext;
  class FuncRparamContext;
  class MulExpContext;
  class AddExpContext;
  class RelExpContext;
  class EqExpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstExpContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Const();
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Assign();
    ConstInitValContext *constInitVal();
    std::vector<antlr4::tree::TerminalNode *> Lbrkt();
    antlr4::tree::TerminalNode* Lbrkt(size_t i);
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbrkt();
    antlr4::tree::TerminalNode* Rbrkt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDefContext* constDef();

  class  ConstInitValContext : public antlr4::ParserRuleContext {
  public:
    ConstInitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstInitValContext() = default;
    void copyFrom(ConstInitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ListConstInitValContext : public ConstInitValContext {
  public:
    ListConstInitValContext(ConstInitValContext *ctx);

    antlr4::tree::TerminalNode *Lbrace();
    antlr4::tree::TerminalNode *Rbrace();
    std::vector<ConstInitValContext *> constInitVal();
    ConstInitValContext* constInitVal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ScalarConstInitValContext : public ConstInitValContext {
  public:
    ScalarConstInitValContext(ConstInitValContext *ctx);

    ConstExpContext *constExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstInitValContext* constInitVal();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnInitVarDefContext : public VarDefContext {
  public:
    UnInitVarDefContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> Lbrkt();
    antlr4::tree::TerminalNode* Lbrkt(size_t i);
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbrkt();
    antlr4::tree::TerminalNode* Rbrkt(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InitVarDefContext : public VarDefContext {
  public:
    InitVarDefContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Assign();
    InitValContext *initVal();
    std::vector<antlr4::tree::TerminalNode *> Lbrkt();
    antlr4::tree::TerminalNode* Lbrkt(size_t i);
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbrkt();
    antlr4::tree::TerminalNode* Rbrkt(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarDefContext* varDef();

  class  InitValContext : public antlr4::ParserRuleContext {
  public:
    InitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    InitValContext() = default;
    void copyFrom(InitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ScalarInitValContext : public InitValContext {
  public:
    ScalarInitValContext(InitValContext *ctx);

    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListInitValContext : public InitValContext {
  public:
    ListInitValContext(InitValContext *ctx);

    antlr4::tree::TerminalNode *Lbrace();
    antlr4::tree::TerminalNode *Rbrace();
    std::vector<InitValContext *> initVal();
    InitValContext* initVal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  InitValContext* initVal();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Lparen();
    antlr4::tree::TerminalNode *Rparen();
    BlockContext *block();
    FuncFparamListContext *funcFparamList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncTypeContext* funcType();

  class  FuncFparamListContext : public antlr4::ParserRuleContext {
  public:
    FuncFparamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncFparamContext *> funcFparam();
    FuncFparamContext* funcFparam(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncFparamListContext* funcFparamList();

  class  FuncFparamContext : public antlr4::ParserRuleContext {
  public:
    FuncFparamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> Lbrkt();
    antlr4::tree::TerminalNode* Lbrkt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbrkt();
    antlr4::tree::TerminalNode* Rbrkt(size_t i);
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncFparamContext* funcFparam();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Lbrace();
    antlr4::tree::TerminalNode *Rbrace();
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileStmtContext : public StmtContext {
  public:
    WhileStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *Lparen();
    CondContext *cond();
    antlr4::tree::TerminalNode *Rparen();
    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfStmtContext : public StmtContext {
  public:
    IfStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *Lparen();
    CondContext *cond();
    antlr4::tree::TerminalNode *Rparen();
    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlockStmtContext : public StmtContext {
  public:
    BlockStmtContext(StmtContext *ctx);

    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfElseStmtContext : public StmtContext {
  public:
    IfElseStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *Lparen();
    CondContext *cond();
    antlr4::tree::TerminalNode *Rparen();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakStmtContext : public StmtContext {
  public:
    BreakStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpStmtContext : public StmtContext {
  public:
    ExpStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Semicolon();
    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Semicolon();
    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ContinueStmtContext : public StmtContext {
  public:
    ContinueStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignmentStmtContext : public StmtContext {
  public:
    AssignmentStmtContext(StmtContext *ctx);

    LValContext *lVal();
    antlr4::tree::TerminalNode *Assign();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpContext* exp();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> Lbrkt();
    antlr4::tree::TerminalNode* Lbrkt(size_t i);
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbrkt();
    antlr4::tree::TerminalNode* Rbrkt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LValContext* lVal();

  class  RValContext : public antlr4::ParserRuleContext {
  public:
    RValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> Lbrkt();
    antlr4::tree::TerminalNode* Lbrkt(size_t i);
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbrkt();
    antlr4::tree::TerminalNode* Rbrkt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RValContext* rVal();

  class  PrimExpContext : public antlr4::ParserRuleContext {
  public:
    PrimExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimExpContext() = default;
    void copyFrom(PrimExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrimRvalExpContext : public PrimExpContext {
  public:
    PrimRvalExpContext(PrimExpContext *ctx);

    RValContext *rVal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimConstExpContext : public PrimExpContext {
  public:
    PrimConstExpContext(PrimExpContext *ctx);

    NumberContext *number();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimParenExpContext : public PrimExpContext {
  public:
    PrimParenExpContext(PrimExpContext *ctx);

    antlr4::tree::TerminalNode *Lparen();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Rparen();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimExpContext* primExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntLiteral();
    antlr4::tree::TerminalNode *FloatLiteral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryFuncCallExpContext : public UnaryExpContext {
  public:
    UnaryFuncCallExpContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Lparen();
    antlr4::tree::TerminalNode *Rparen();
    FuncRparamListContext *funcRparamList();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryOpExpContext : public UnaryExpContext {
  public:
    UnaryOpExpContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryToPrimExpContext : public UnaryExpContext {
  public:
    UnaryToPrimExpContext(UnaryExpContext *ctx);

    PrimExpContext *primExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryExpContext* unaryExp();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Addition();
    antlr4::tree::TerminalNode *Minus();
    antlr4::tree::TerminalNode *Exclamation();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryOpContext* unaryOp();

  class  FuncRparamListContext : public antlr4::ParserRuleContext {
  public:
    FuncRparamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncRparamContext *> funcRparam();
    FuncRparamContext* funcRparam(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncRparamListContext* funcRparamList();

  class  FuncRparamContext : public antlr4::ParserRuleContext {
  public:
    FuncRparamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FuncRparamContext() = default;
    void copyFrom(FuncRparamContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringAsRparamContext : public FuncRparamContext {
  public:
    StringAsRparamContext(FuncRparamContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpAsRparamContext : public FuncRparamContext {
  public:
    ExpAsRparamContext(FuncRparamContext *ctx);

    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncRparamContext* funcRparam();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MulExpContext() = default;
    void copyFrom(MulExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulTwoExpContext : public MulExpContext {
  public:
    MulTwoExpContext(MulExpContext *ctx);

    MulExpContext *mulExp();
    UnaryExpContext *unaryExp();
    antlr4::tree::TerminalNode *Multiplication();
    antlr4::tree::TerminalNode *Division();
    antlr4::tree::TerminalNode *Modulo();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulToUnaryExpContext : public MulExpContext {
  public:
    MulToUnaryExpContext(MulExpContext *ctx);

    UnaryExpContext *unaryExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AddExpContext() = default;
    void copyFrom(AddExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddToMulExpContext : public AddExpContext {
  public:
    AddToMulExpContext(AddExpContext *ctx);

    MulExpContext *mulExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddTwoExpContext : public AddExpContext {
  public:
    AddTwoExpContext(AddExpContext *ctx);

    AddExpContext *addExp();
    MulExpContext *mulExp();
    antlr4::tree::TerminalNode *Addition();
    antlr4::tree::TerminalNode *Minus();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelExpContext() = default;
    void copyFrom(RelExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelToAddExpContext : public RelExpContext {
  public:
    RelToAddExpContext(RelExpContext *ctx);

    AddExpContext *addExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelTwoExpContext : public RelExpContext {
  public:
    RelTwoExpContext(RelExpContext *ctx);

    RelExpContext *relExp();
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EqExpContext() = default;
    void copyFrom(EqExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EqTwoExpContext : public EqExpContext {
  public:
    EqTwoExpContext(EqExpContext *ctx);

    EqExpContext *eqExp();
    RelExpContext *relExp();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqToRelExpContext : public EqExpContext {
  public:
    EqToRelExpContext(EqExpContext *ctx);

    RelExpContext *relExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LAndExpContext() = default;
    void copyFrom(LAndExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LAndToEqExpContext : public LAndExpContext {
  public:
    LAndToEqExpContext(LAndExpContext *ctx);

    EqExpContext *eqExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LAndTwoExpContext : public LAndExpContext {
  public:
    LAndTwoExpContext(LAndExpContext *ctx);

    LAndExpContext *lAndExp();
    antlr4::tree::TerminalNode *LAND();
    EqExpContext *eqExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LOrExpContext() = default;
    void copyFrom(LOrExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LOrToLandExpContext : public LOrExpContext {
  public:
    LOrToLandExpContext(LOrExpContext *ctx);

    LAndExpContext *lAndExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LOrTwoExpContext : public LOrExpContext {
  public:
    LOrTwoExpContext(LOrExpContext *ctx);

    LOrExpContext *lOrExp();
    antlr4::tree::TerminalNode *LOR();
    LAndExpContext *lAndExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstExpContext* constExp();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool relExpSempred(RelExpContext *_localctx, size_t predicateIndex);
  bool eqExpSempred(EqExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace front
