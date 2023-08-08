
// Generated from SysY.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"


namespace front {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SysYParser.
 */
class  SysYVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SysYParser.
   */
    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(SysYParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) = 0;

    virtual std::any visitBType(SysYParser::BTypeContext *context) = 0;

    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) = 0;

    virtual std::any visitScalarConstInitVal(SysYParser::ScalarConstInitValContext *context) = 0;

    virtual std::any visitListConstInitVal(SysYParser::ListConstInitValContext *context) = 0;

    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) = 0;

    virtual std::any visitUnInitVarDef(SysYParser::UnInitVarDefContext *context) = 0;

    virtual std::any visitInitVarDef(SysYParser::InitVarDefContext *context) = 0;

    virtual std::any visitScalarInitVal(SysYParser::ScalarInitValContext *context) = 0;

    virtual std::any visitListInitVal(SysYParser::ListInitValContext *context) = 0;

    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFparamList(SysYParser::FuncFparamListContext *context) = 0;

    virtual std::any visitFuncFparam(SysYParser::FuncFparamContext *context) = 0;

    virtual std::any visitBlock(SysYParser::BlockContext *context) = 0;

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context) = 0;

    virtual std::any visitAssignmentStmt(SysYParser::AssignmentStmtContext *context) = 0;

    virtual std::any visitExpStmt(SysYParser::ExpStmtContext *context) = 0;

    virtual std::any visitBlockStmt(SysYParser::BlockStmtContext *context) = 0;

    virtual std::any visitIfStmt(SysYParser::IfStmtContext *context) = 0;

    virtual std::any visitIfElseStmt(SysYParser::IfElseStmtContext *context) = 0;

    virtual std::any visitWhileStmt(SysYParser::WhileStmtContext *context) = 0;

    virtual std::any visitBreakStmt(SysYParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(SysYParser::ContinueStmtContext *context) = 0;

    virtual std::any visitReturnStmt(SysYParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExp(SysYParser::ExpContext *context) = 0;

    virtual std::any visitCond(SysYParser::CondContext *context) = 0;

    virtual std::any visitLVal(SysYParser::LValContext *context) = 0;

    virtual std::any visitRVal(SysYParser::RValContext *context) = 0;

    virtual std::any visitPrimParenExp(SysYParser::PrimParenExpContext *context) = 0;

    virtual std::any visitPrimRvalExp(SysYParser::PrimRvalExpContext *context) = 0;

    virtual std::any visitPrimConstExp(SysYParser::PrimConstExpContext *context) = 0;

    virtual std::any visitNumber(SysYParser::NumberContext *context) = 0;

    virtual std::any visitUnaryToPrimExp(SysYParser::UnaryToPrimExpContext *context) = 0;

    virtual std::any visitUnaryFuncCallExp(SysYParser::UnaryFuncCallExpContext *context) = 0;

    virtual std::any visitUnaryOpExp(SysYParser::UnaryOpExpContext *context) = 0;

    virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *context) = 0;

    virtual std::any visitFuncRparamList(SysYParser::FuncRparamListContext *context) = 0;

    virtual std::any visitExpAsRparam(SysYParser::ExpAsRparamContext *context) = 0;

    virtual std::any visitStringAsRparam(SysYParser::StringAsRparamContext *context) = 0;

    virtual std::any visitMulTwoExp(SysYParser::MulTwoExpContext *context) = 0;

    virtual std::any visitMulToUnaryExp(SysYParser::MulToUnaryExpContext *context) = 0;

    virtual std::any visitAddToMulExp(SysYParser::AddToMulExpContext *context) = 0;

    virtual std::any visitAddTwoExp(SysYParser::AddTwoExpContext *context) = 0;

    virtual std::any visitRelToAddExp(SysYParser::RelToAddExpContext *context) = 0;

    virtual std::any visitRelTwoExp(SysYParser::RelTwoExpContext *context) = 0;

    virtual std::any visitEqTwoExp(SysYParser::EqTwoExpContext *context) = 0;

    virtual std::any visitEqToRelExp(SysYParser::EqToRelExpContext *context) = 0;

    virtual std::any visitLAndToEqExp(SysYParser::LAndToEqExpContext *context) = 0;

    virtual std::any visitLAndTwoExp(SysYParser::LAndTwoExpContext *context) = 0;

    virtual std::any visitLOrToLandExp(SysYParser::LOrToLandExpContext *context) = 0;

    virtual std::any visitLOrTwoExp(SysYParser::LOrTwoExpContext *context) = 0;

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context) = 0;


};

}  // namespace front
