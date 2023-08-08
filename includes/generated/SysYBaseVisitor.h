
// Generated from SysY.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "SysYVisitor.h"


namespace front {

/**
 * This class provides an empty implementation of SysYVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysYBaseVisitor : public SysYVisitor {
public:

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(SysYParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarConstInitVal(SysYParser::ScalarConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListConstInitVal(SysYParser::ListConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnInitVarDef(SysYParser::UnInitVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitVarDef(SysYParser::InitVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarInitVal(SysYParser::ScalarInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListInitVal(SysYParser::ListInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFparamList(SysYParser::FuncFparamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFparam(SysYParser::FuncFparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(SysYParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentStmt(SysYParser::AssignmentStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpStmt(SysYParser::ExpStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStmt(SysYParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(SysYParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfElseStmt(SysYParser::IfElseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(SysYParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(SysYParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(SysYParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(SysYParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(SysYParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(SysYParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRVal(SysYParser::RValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimParenExp(SysYParser::PrimParenExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimRvalExp(SysYParser::PrimRvalExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimConstExp(SysYParser::PrimConstExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(SysYParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryToPrimExp(SysYParser::UnaryToPrimExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryFuncCallExp(SysYParser::UnaryFuncCallExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOpExp(SysYParser::UnaryOpExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRparamList(SysYParser::FuncRparamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpAsRparam(SysYParser::ExpAsRparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringAsRparam(SysYParser::StringAsRparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulTwoExp(SysYParser::MulTwoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulToUnaryExp(SysYParser::MulToUnaryExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddToMulExp(SysYParser::AddToMulExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddTwoExp(SysYParser::AddTwoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelToAddExp(SysYParser::RelToAddExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelTwoExp(SysYParser::RelTwoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqTwoExp(SysYParser::EqTwoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqToRelExp(SysYParser::EqToRelExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndToEqExp(SysYParser::LAndToEqExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndTwoExp(SysYParser::LAndTwoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrToLandExp(SysYParser::LOrToLandExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrTwoExp(SysYParser::LOrTwoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExp(SysYParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace front
