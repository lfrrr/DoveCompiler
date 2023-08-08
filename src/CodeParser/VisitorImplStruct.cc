#include <vector>

#include "VisitorImpl.h"

namespace front
{

    std::any VisitorImpl::visitBlock(SysYParser::BlockContext *context)
    {
        // This block is different from the BasicBlock in ControlFlow, this block is a scope
        ctx_.symbolTable->pushScope("block");
        for (auto blockItem : context->blockItem())
        {
            blockItem->accept(this);
        }
        return 0;
    };
    std::any VisitorImpl::visitBlockItem(SysYParser::BlockItemContext *context)
    {
        if (context->decl())
        {
            context->decl()->accept(this);
        }
        else if (context->stmt())
        {
            context->stmt()->accept(this);
        }
        return 0;
    };

    std::any VisitorImpl::visitAssignmentStmt(SysYParser::AssignmentStmtContext *context)
    {
        try
        {
            auto left = std::any_cast<std::shared_ptr<ir::User>>(context->lVal()->accept(this));
            auto right = std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
            auto store = std::make_shared<ir::Store>(right, left);
            ctx_.currentBasicBlock->addInstruction(store);
            return std::dynamic_pointer_cast<ir::User>(store);
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitAssignmentStmt:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitExpStmt(SysYParser::ExpStmtContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitExpStmt:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitBlockStmt(SysYParser::BlockStmtContext *context)
    {
        // Do nothing, just accept.
        context->block()->accept(this);
        return 0;
    };

    std::any VisitorImpl::visitCond(SysYParser::CondContext *context)
    {
        try
        {

            context->lOrExp()->accept(this);
            return 0;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitCond:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitIfStmt(SysYParser::IfStmtContext *context)
    {

        auto t_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_if_true_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto exit_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_if_exit_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto bb = std::make_shared<ir::BasicBlock>(t_jplabel, ir::BasicBlock::BlockType::IfTrue);
        auto exit_bb = std::make_shared<ir::BasicBlock>(exit_jplabel, ir::BasicBlock::BlockType::Default);
        auto t_label = std::make_shared<ir::Label>(t_jplabel);
        auto exit_label = std::make_shared<ir::Label>(exit_jplabel);
        auto out_exit_bb = ctx_.exitBasicBlock;

        ctx_.trueTargetBBStack.push(bb);
        ctx_.falseTargetBBStack.push(exit_bb);

        ctx_.symbolTable->pushScope("if");
        context->cond()->accept(this);

        ctx_.currentFunction->addBasicBlock(bb);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = bb;
        ctx_.exitBasicBlock = exit_bb;
        context->stmt()->accept(this);
        ctx_.symbolTable->popScope();

        ctx_.currentFunction->addBasicBlock(exit_bb);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = exit_bb;
        ctx_.exitBasicBlock = out_exit_bb;

        ctx_.trueTargetBBStack.pop();
        ctx_.falseTargetBBStack.pop();
        return 0;
    };
    std::any VisitorImpl::visitIfElseStmt(SysYParser::IfElseStmtContext *context)
    {

        auto t_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_if_true_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto f_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_if_false_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto exit_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_if_exit_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto bbt = std::make_shared<ir::BasicBlock>(t_jplabel, ir::BasicBlock::BlockType::IfTrue);
        auto bbf = std::make_shared<ir::BasicBlock>(f_jplabel, ir::BasicBlock::BlockType::IfFalse);
        auto exit_bb = std::make_shared<ir::BasicBlock>(exit_jplabel, ir::BasicBlock::BlockType::Default);
        auto t_label = std::make_shared<ir::Label>(t_jplabel);
        auto f_label = std::make_shared<ir::Label>(f_jplabel);
        auto exit_label = std::make_shared<ir::Label>(exit_jplabel);
        auto out_exit_bb = ctx_.exitBasicBlock;

        ctx_.trueTargetBBStack.push(bbt);
        ctx_.falseTargetBBStack.push(bbf);

        ctx_.symbolTable->pushScope("if");
        context->cond()->accept(this);

        ctx_.currentFunction->addBasicBlock(bbt);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = bbt;
        ctx_.exitBasicBlock = exit_bb;
        if (context->stmt(0))
            context->stmt(0)->accept(this);
        auto br = std::make_shared<ir::Br>(exit_label, exit_label->getName());
        ctx_.currentBasicBlock->addInstruction(br);
        ctx_.symbolTable->popScope();

        ctx_.symbolTable->pushScope("else");
        ctx_.currentFunction->addBasicBlock(bbf);
        ctx_.currentBasicBlock = bbf;
        ctx_.exitBasicBlock = exit_bb;
        if (context->stmt(1))
            context->stmt(1)->accept(this);
        ctx_.symbolTable->popScope();

        ctx_.currentFunction->addBasicBlock(exit_bb);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = exit_bb;
        ctx_.exitBasicBlock = out_exit_bb;

        ctx_.trueTargetBBStack.pop();
        ctx_.falseTargetBBStack.pop();
        return 0;
    };
    std::any VisitorImpl::visitWhileStmt(SysYParser::WhileStmtContext *context)
    {
        auto entry_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_while_entry_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto body_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_while_body_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto exit_jplabel = std::make_shared<ir::JPLabel>("_" + ctx_.currentFunction->getName() + "_while_exit_" + std::to_string(ctx_.basicBlockCounter.next()));
        auto entry_bb = std::make_shared<ir::BasicBlock>(entry_jplabel, ir::BlockType::WhileEntry);
        auto body_bb = std::make_shared<ir::BasicBlock>(body_jplabel, ir::BlockType::WhileBody);
        auto exit_bb = std::make_shared<ir::BasicBlock>(exit_jplabel, ir::BlockType::Default);
        auto entry_label = std::make_shared<ir::Label>(entry_jplabel);
        auto body_label = std::make_shared<ir::Label>(body_jplabel);
        auto exit_label = std::make_shared<ir::Label>(exit_jplabel);
        auto out_exit_bb = ctx_.exitBasicBlock;

        ctx_.breakBBStack.push(exit_bb);
        ctx_.continueBBStack.push(entry_bb);

        ctx_.trueTargetBBStack.push(entry_bb);
        ctx_.falseTargetBBStack.push(exit_bb);

        ctx_.symbolTable->pushScope("while");
        ctx_.currentFunction->addBasicBlock(entry_bb);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = entry_bb;
        ctx_.exitBasicBlock = exit_bb;
        context->cond()->accept(this);

        ctx_.currentFunction->addBasicBlock(body_bb);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = body_bb;
        ctx_.exitBasicBlock = exit_bb;
        context->stmt()->accept(this);
        auto br = std::make_shared<ir::Br>(entry_label, entry_label->getName());
        ctx_.currentBasicBlock->addInstruction(br);

        ctx_.symbolTable->popScope();

        ctx_.currentFunction->addBasicBlock(exit_bb);
        ctx_.entryBasicBlock = ctx_.currentBasicBlock;
        ctx_.currentBasicBlock = exit_bb;
        ctx_.exitBasicBlock = out_exit_bb;

        ctx_.trueTargetBBStack.pop();
        ctx_.falseTargetBBStack.pop();

        ctx_.breakBBStack.pop();
        ctx_.continueBBStack.pop();

        return 0;
    };

    std::any VisitorImpl::visitBreakStmt(SysYParser::BreakStmtContext *context)
    {
        auto label = std::make_shared<ir::Label>(ctx_.breakBBStack.top()->getJPLabel());
        auto br = std::make_shared<ir::Br>(label, label->getName());
        ctx_.currentBasicBlock->addInstruction(br);
        return std::dynamic_pointer_cast<ir::User>(br);
    };

    std::any VisitorImpl::visitContinueStmt(SysYParser::ContinueStmtContext *context)
    {
        auto label = std::make_shared<ir::Label>(ctx_.continueBBStack.top()->getJPLabel());
        auto br = std::make_shared<ir::Br>(label, label->getName());
        ctx_.currentBasicBlock->addInstruction(br);
        return std::dynamic_pointer_cast<ir::User>(br);
    };

    std::any VisitorImpl::visitReturnStmt(SysYParser::ReturnStmtContext *context)
    {
        auto user = std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
        auto ret = std::make_shared<ir::Return>(user, user->getName());
        ctx_.currentBasicBlock->addInstruction(ret);
        return std::dynamic_pointer_cast<ir::User>(ret);
    };

    std::any VisitorImpl::visitRelToAddExp(SysYParser::RelToAddExpContext *context)
    {
        try
        {
            auto user = std::any_cast<std::shared_ptr<ir::User>>(context->addExp()->accept(this));
            if (user->getType()->isPrimitive())
            {
                auto type = std::dynamic_pointer_cast<ir::PrimitiveDataType>(user->getType());
                if (type->isInt())
                {
                    return std::dynamic_pointer_cast<ir::User>(user);
                }
                else if (type->isFloat())
                {
                    // float to int
                    // auto fptosi = std::make_shared<ir::Fptosi>(user, user->getName());
                    // return std::dynamic_pointer_cast<ir::User>(user);
                    return 0;
                }
            }
            throw std::runtime_error("Rel must accept a Primitive Value");
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitRelToAddExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitRelTwoExp(SysYParser::RelTwoExpContext *context)
    {
        try
        {
            auto icmpid = ir::Icmp::IcmpId::LT;
            auto fcmpid = ir::Fcmp::FcmpId::LT;
            if (context->LT())
            {
                icmpid = ir::Icmp::IcmpId::LT;
                fcmpid = ir::Fcmp::FcmpId::LT;
            }
            else if (context->LE())
            {
                icmpid = ir::Icmp::IcmpId::LE;
                fcmpid = ir::Fcmp::FcmpId::LE;
            }
            else if (context->GT())
            {
                icmpid = ir::Icmp::IcmpId::GT;
                fcmpid = ir::Fcmp::FcmpId::GT;
            }
            else if (context->GE())
            {
                icmpid = ir::Icmp::IcmpId::GE;
                fcmpid = ir::Fcmp::FcmpId::GE;
            }

            auto left = std::any_cast<std::shared_ptr<ir::User>>(context->relExp()->accept(this));
            auto right = std::any_cast<std::shared_ptr<ir::User>>(context->addExp()->accept(this));
            if (left->isStaticValue() && right->isStaticValue())
            {
                if (left->getType()->isPrimitive() && right->getType()->isPrimitive())
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                        auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                        auto left_val = left_const->getInt();
                        auto right_val = right_const->getInt();
                        switch (icmpid)
                        {
                        case ir::Icmp::IcmpId::LT:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val < right_val);
                        case ir::Icmp::IcmpId::LE:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val <= right_val);
                        case ir::Icmp::IcmpId::GT:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val > right_val);
                        case ir::Icmp::IcmpId::GE:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val >= right_val);
                        default:
                            throw std::runtime_error("Error in visitRelTwoExp: icmpid not found");
                        }
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                        auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                        auto left_val = left_const->getFloat();
                        auto right_val = right_const->getFloat();
                        switch (fcmpid)
                        {
                        case ir::Fcmp::FcmpId::LT:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val < right_val);
                        case ir::Fcmp::FcmpId::LE:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val <= right_val);
                        case ir::Fcmp::FcmpId::GT:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val > right_val);
                        case ir::Fcmp::FcmpId::GE:
                            return std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Bool", left_val >= right_val);
                        default:
                            throw std::runtime_error("Error in visitRelTwoExp: fcmpid not found");
                        }
                    }
                }
                throw std::runtime_error("Error in visitRelTwoExp: left and right are not both int or float");
            }
            else
            {
                if (left->getType()->isPrimitive() && right->getType()->isPrimitive())
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        auto icmp = std::make_shared<ir::Icmp>(icmpid, left, right, ctx_.newVRegName());
                        ctx_.currentBasicBlock->addInstruction(icmp);
                        return std::dynamic_pointer_cast<ir::User>(icmp);
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        auto fcmp = std::make_shared<ir::Fcmp>(fcmpid, left, right, ctx_.newVRegName());
                        ctx_.currentBasicBlock->addInstruction(fcmp);
                        return std::dynamic_pointer_cast<ir::User>(fcmp);
                    }
                }
                throw std::runtime_error("Error in visitRelTwoExp: left and right are not both int or float");
            }
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitRelTwoExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitEqTwoExp(SysYParser::EqTwoExpContext *context)
    {
        try
        {
            auto left = std::any_cast<std::shared_ptr<ir::User>>(context->eqExp()->accept(this));
            auto right = std::any_cast<std::shared_ptr<ir::User>>(context->relExp()->accept(this));
            if (left->getType()->isPrimitive() && right->getType()->isPrimitive())
            {
                if (left->isStaticValue() && right->isStaticValue())
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                        auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                        auto left_val = left_const->getInt();
                        auto right_val = right_const->getInt();
                        auto result = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "eq", left_val == right_val);
                        return std::dynamic_pointer_cast<ir::User>(result);
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                        auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                        auto left_val = left_const->getFloat();
                        auto right_val = right_const->getFloat();
                        auto result = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "eq", left_val == right_val);
                        return std::dynamic_pointer_cast<ir::User>(result);
                    }
                }
                else
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        auto icmp = std::make_shared<ir::Icmp>(ir::Icmp::IcmpId::EQ, left, right, ctx_.newVRegName());
                        ctx_.currentBasicBlock->addInstruction(icmp);
                        return std::dynamic_pointer_cast<ir::User>(icmp);
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        auto fcmp = std::make_shared<ir::Fcmp>(ir::Fcmp::FcmpId::EQ, left, right, ctx_.newVRegName());
                        ctx_.currentBasicBlock->addInstruction(fcmp);
                        return std::dynamic_pointer_cast<ir::User>(fcmp);
                    }
                }
            }
            throw std::runtime_error("left and right are not both primitive");
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitEqTwoExp:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitEqToRelExp(SysYParser::EqToRelExpContext *context)
    {
        try
        {
            auto user = std::any_cast<std::shared_ptr<ir::User>>(context->relExp()->accept(this));
            // auto zero = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "zero", 0);
            // auto icmp = std::make_shared<ir::Icmp>(ir::Icmp::IcmpId::GT, user, zero, ctx_.newVRegName());
            // ctx_.currentBasicBlock->addInstruction(icmp);
            return std::dynamic_pointer_cast<ir::User>(user);
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitEqToRelExp:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitLAndToEqExp(SysYParser::LAndToEqExpContext *context)
    {
        try
        {
            auto t_bb = ctx_.trueTargetBBStack.top();
            auto f_bb = ctx_.falseTargetBBStack.top();
            auto t_label = std::make_shared<ir::Label>(t_bb->getJPLabel());
            auto f_label = std::make_shared<ir::Label>(f_bb->getJPLabel());

            auto user = std::any_cast<std::shared_ptr<ir::User>>(context->eqExp()->accept(this)); // Icmp, Fcmp or int StatciValue
            auto icmp = std::make_shared<ir::Icmp>(ir::Icmp::IcmpId::GT, user, std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "zero", 0), ctx_.newVRegName());
            auto br = std::make_shared<ir::Br>(icmp, t_label, f_label, t_label->getName());
            ctx_.currentBasicBlock->addInstruction(br);

            return 0;
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitLAndToEqExp:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitLAndTwoExp(SysYParser::LAndTwoExpContext *context)
    {
        try
        {
            auto t_bb = ctx_.trueTargetBBStack.top();
            auto f_bb = ctx_.falseTargetBBStack.top();
            auto t_label = std::make_shared<ir::Label>(t_bb->getJPLabel());
            auto f_label = std::make_shared<ir::Label>(f_bb->getJPLabel());
            auto bb = std::make_shared<ir::BasicBlock>("_" + ctx_.currentFunction->getName() + "_lAnd_exit_" + std::to_string(ctx_.basicBlockCounter.next()), ir::BasicBlock::BlockType::Default);

            ctx_.trueTargetBBStack.push(bb);
            context->lAndExp()->accept(this);
            ctx_.trueTargetBBStack.pop();

            ctx_.currentFunction->addBasicBlock(bb);
            ctx_.entryBasicBlock = ctx_.currentBasicBlock;
            ctx_.currentBasicBlock = bb;
            auto user = std::any_cast<std::shared_ptr<ir::User>>(context->eqExp()->accept(this)); // Icmp, Fcmp or int StatciValue
            auto icmp = std::make_shared<ir::Icmp>(ir::Icmp::IcmpId::GT, user, std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "zero", 0), ctx_.newVRegName());
            auto br = std::make_shared<ir::Br>(icmp, t_label, f_label, t_label->getName());
            ctx_.currentBasicBlock->addInstruction(br);

            return 0;
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitLAndTwoExp:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitLOrToLandExp(SysYParser::LOrToLandExpContext *context)
    {
        try
        {
            context->lAndExp()->accept(this);

            return 0;
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitLOrToLandExp:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitLOrTwoExp(SysYParser::LOrTwoExpContext *context)
    {
        try
        {
            auto bb = std::make_shared<ir::BasicBlock>("_" + ctx_.currentFunction->getName() + "_lOr_exit_" + std::to_string(ctx_.basicBlockCounter.next()), ir::BasicBlock::BlockType::Default);

            ctx_.falseTargetBBStack.push(bb);
            context->lOrExp()->accept(this);
            ctx_.falseTargetBBStack.pop();

            ctx_.currentFunction->addBasicBlock(bb);
            ctx_.entryBasicBlock = ctx_.currentBasicBlock;
            ctx_.currentBasicBlock = bb;
            context->lAndExp()->accept(this);

            return 0;
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitLOrTwoExp:\n" + std::string(e.what()));
        }
    };
}