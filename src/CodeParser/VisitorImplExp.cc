#include <vector>
#include <iostream>

#include "VisitorImpl.h"
#include "Utils/Utils.h"
#include "IR/Operators.h"
namespace front
{

    std::any VisitorImpl::visitExp(SysYParser::ExpContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->addExp()->accept(this));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitLVal(SysYParser::LValContext *context)
    {
        try
        {
            auto ident = context->Identifier()->getSymbol()->getText();
            auto osymbol = ctx_.symbolTable->getSymbol(ident, true);
            if (!osymbol.has_value())
            {
                throw std::runtime_error("Symbol not found");
            }
            auto symbol = osymbol.value();
            auto symuser = symbol->get();
            if (symuser->isConst())
            {
                throw std::runtime_error("ConstAllocate cannot be a lVal");
            }

            if (!symuser->getType()->isArray())
            {
                // single no subscription lval
                return std::dynamic_pointer_cast<ir::User>(symuser);
            }
            else
            {
                // array ele with subscription lval
                auto users = std::vector<std::shared_ptr<ir::User>>();
                for (auto exp : context->exp())
                {
                    auto user = std::any_cast<std::shared_ptr<ir::User>>(exp->accept(this));
                    users.push_back(user);
                }

                // TODO add getelemntptr and loads
                return 0;
            }
            throw std::runtime_error("Unknown symbol type");
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitLVal:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitRVal(SysYParser::RValContext *context)
    {
        try
        {
            auto ident = context->Identifier()->getSymbol()->getText();
            auto osymbol = ctx_.symbolTable->getSymbol(ident, true);
            if (!osymbol.has_value())
            {
                throw std::runtime_error("Symbol not found");
            }
            auto symbol = osymbol.value();
            auto symuser = symbol->get();

            if (ctx_.symbolTable->getCurrentScope()->isGlobal())
            {
                if (!symuser->getType()->isArray())
                {
                    // single no subscription lval
                    return std::dynamic_pointer_cast<ir::User>(symuser);
                }
                else
                {
                    // array ele with subscription lval
                    auto users = std::vector<std::shared_ptr<ir::User>>();
                    for (auto exp : context->exp())
                    {
                        auto user = std::any_cast<std::shared_ptr<ir::User>>(exp->accept(this));
                        users.push_back(user);
                    }
                    bool isStatic = true;

                    if (symuser->isStaticValue())
                    {
                        auto const_identifier = std::dynamic_pointer_cast<ir::StaticValue>(symuser);
                        // Check is full const LVal
                        for (auto user : users)
                        {
                            if (!user->isStaticValue())
                            {
                                isStatic = false;
                            }
                        }

                        if (isStatic)
                        {
                            auto subs = std::vector<size_t>();
                            for (auto user : users)
                            {
                                auto subsconsts = std::dynamic_pointer_cast<ir::StaticValue>(user);
                                if (subsconsts->isInt())
                                {
                                    subs.push_back(subsconsts->getInt());
                                }
                                else
                                {
                                    throw std::runtime_error("Array index must be int");
                                }
                            }
                            auto static_value = const_identifier->at(subs);
                            return std::dynamic_pointer_cast<ir::User>(static_value);
                        }
                    }
                    else
                    {
                        throw std::runtime_error("Global RVal must be a const.");
                    }
                }
            }
            else
            {
                if (!symuser->getType()->isArray())
                {
                    // single no subscription lval
                    auto load = std::make_shared<ir::Load>(symuser, ctx_.newVRegName());
                    ctx_.currentBasicBlock->addInstruction(load);
                    return std::dynamic_pointer_cast<ir::User>(load);
                }
                else
                {
                    // array ele with subscription lval
                    auto users = std::vector<std::shared_ptr<ir::User>>();
                    for (auto exp : context->exp())
                    {
                        auto user = std::any_cast<std::shared_ptr<ir::User>>(exp->accept(this));
                        users.push_back(user);
                    }
                    bool isStatic = true;

                    if (symuser->isStaticValue())
                    {
                        auto const_identifier = std::dynamic_pointer_cast<ir::StaticValue>(symuser);
                        // Check is full const LVal
                        for (auto user : users)
                        {
                            if (!user->isStaticValue())
                            {
                                isStatic = false;
                            }
                        }

                        if (isStatic)
                        {
                            auto subs = std::vector<size_t>();
                            for (auto user : users)
                            {
                                auto subsconsts = std::dynamic_pointer_cast<ir::StaticValue>(user);
                                if (subsconsts->isInt())
                                {
                                    subs.push_back(subsconsts->getInt());
                                }
                                else
                                {
                                    throw std::runtime_error("Array index must be int");
                                }
                            }
                            auto static_value = const_identifier->at(subs);
                            return std::dynamic_pointer_cast<ir::User>(static_value);
                        }
                    }
                    else
                    {
                        auto getelementptr = std::make_shared<ir::GetElementPtr>(symuser, symuser->getType(), users, ctx_.newVRegName());
                        ctx_.currentBasicBlock->addInstruction(getelementptr);
                        auto load = std::make_shared<ir::Load>(getelementptr, ctx_.newVRegName());
                        ctx_.currentBasicBlock->addInstruction(load);
                        return std::dynamic_pointer_cast<ir::User>(load);
                    }
                }
            }

            throw std::runtime_error("Unknown symbol type");
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitRVal:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitPrimParenExp(SysYParser::PrimParenExpContext *context)
    {
        try
        {
            return context->exp()->accept(this);
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitPrimParenExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitPrimRvalExp(SysYParser::PrimRvalExpContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->rVal()->accept(this));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitPrimRvalExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitPrimConstExp(SysYParser::PrimConstExpContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->number()->accept(this));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitPrimConstExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitNumber(SysYParser::NumberContext *context)
    {
        try
        {
            if (context->IntLiteral())
            {
                auto i = utils::ParseInt32(context->getText());
                auto p = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Int", i);
                return std::dynamic_pointer_cast<ir::User>(p);
            }
            else if (context->FloatLiteral())
            {
                auto i = utils::ParseFloat32(context->getText());
                auto p = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32), "Float", i);
                return std::dynamic_pointer_cast<ir::User>(p);
            }
            throw std::runtime_error("Unknown number type");
            return 0;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitNumber:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitUnaryToPrimExp(SysYParser::UnaryToPrimExpContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->primExp()->accept(this));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitUnaryToPrimExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitUnaryOpExp(SysYParser::UnaryOpExpContext *context)
    {
        try
        {
            auto unaryOp = std::any_cast<char>(context->unaryOp()->accept(this));
            auto right = std::any_cast<std::shared_ptr<ir::User>>(context->unaryExp()->accept(this));
            if (right->isStaticValue())
            {
                auto right_static = std::dynamic_pointer_cast<ir::StaticValue>(right);
                switch (unaryOp)
                {
                case '+':
                {
                    if (right->getType()->isPrimitive())
                    {
                        auto prim_type = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                        if (prim_type->isInt())
                        {
                            return std::dynamic_pointer_cast<ir::User>(right_static);
                        }
                        else if (prim_type->isFloat())
                        {
                            return std::dynamic_pointer_cast<ir::User>(right_static);
                        }
                    }
                    throw std::runtime_error("Add: Invalid operand types");
                    break;
                }
                case '-':
                {
                    if (right->getType()->isPrimitive())
                    {
                        auto prim_type = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());

                        if (prim_type->isInt())
                        {
                            right_static->setStaticValue(-right_static->getInt());
                            return std::dynamic_pointer_cast<ir::User>(right);
                        }
                        else if (prim_type->isFloat())
                        {
                            right_static->setStaticValue(-right_static->getFloat());
                            return std::dynamic_pointer_cast<ir::User>(right);
                        }
                    }
                    break;
                }
                case '!':
                {
                    break;
                }
                default:
                {
                    return right;
                    break;
                }
                }
            }
            else
            {
                switch (unaryOp)
                {
                case '+':
                {
                    if (right->getType()->isPrimitive())
                    {
                        auto prim_type = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                        if (prim_type->isInt())
                        {
                            auto left = std::make_shared<ir::StaticValue>("Int", int32_t(0));
                            auto add = std::make_shared<ir::Add>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(add);
                            return std::dynamic_pointer_cast<ir::User>(add);
                        }
                        else if (prim_type->isFloat())
                        {
                            auto left = std::make_shared<ir::StaticValue>("Float", float(0));
                            auto fadd = std::make_shared<ir::FAdd>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(fadd);
                            return std::dynamic_pointer_cast<ir::User>(fadd);
                        }
                    }
                    throw std::runtime_error("Add: Invalid operand types");
                    break;
                }
                case '-':
                {
                    if (right->getType()->isPrimitive())
                    {
                        auto prim_type = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                        if (prim_type->isInt())
                        {
                            auto left = std::make_shared<ir::StaticValue>("Int", int32_t(0));
                            auto sub = std::make_shared<ir::Sub>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(sub);
                            return std::dynamic_pointer_cast<ir::User>(sub);
                        }
                        else if (prim_type->isFloat())
                        {
                            auto left = std::make_shared<ir::StaticValue>("Float", float(0));
                            auto fsub = std::make_shared<ir::FSub>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(fsub);
                            return std::dynamic_pointer_cast<ir::User>(fsub);
                        }
                    }
                    throw std::runtime_error("Sub: Invalid operand types");
                    break;
                }
                case '!':
                {
                    if (right->getType()->isPrimitive())
                    {
                        auto prim_type = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                        if (prim_type->isInt())
                        {
                            auto left = std::make_shared<ir::StaticValue>("Int", int32_t(0));
                            auto sub = std::make_shared<ir::Sub>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(sub);
                            return std::dynamic_pointer_cast<ir::User>(sub);
                        }
                        else if (prim_type->isFloat())
                        {
                            auto left = std::make_shared<ir::StaticValue>("Float", float(0));
                            auto fsub = std::make_shared<ir::FSub>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(fsub);
                            return std::dynamic_pointer_cast<ir::User>(fsub);
                        }
                    }
                    throw std::runtime_error("Neg: Invalid operand types");
                    break;
                }
                default:
                {
                    return right;
                    break;
                }
                }
            }
            throw std::runtime_error("UnaryExp received a wrong value.");
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitUnaryOpExp:\n" + std::string(e.what()));
        }
    };
    std::any VisitorImpl::visitUnaryOp(SysYParser::UnaryOpContext *context)
    {
        try
        {
            if (context->Addition())
            {
                return '+';
            }
            else if (context->Minus())
            {
                return '-';
            }
            else if (context->Exclamation())
            {
                return '!';
            }
            return '\0';
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitUnaryOp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitMulTwoExp(SysYParser::MulTwoExpContext *context)
    {
        try
        {
            char op = '\0';
            if (context->Multiplication())
            {
                op = '*';
            }
            else if (context->Division())
            {
                op = '/';
            }
            else if (context->Modulo())
            {
                op = '%';
            }

            auto left = std::any_cast<std::shared_ptr<ir::User>>(context->mulExp()->accept(this));
            auto right = std::any_cast<std::shared_ptr<ir::User>>(context->unaryExp()->accept(this));
            if (left->isStaticValue() && right->isStaticValue())
            {
                auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                if (left_const->getType()->isPrimitive() && right_const->getType()->isPrimitive())
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left_const->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right_const->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        int32_t value = 0;
                        if (op == '*')
                        {
                            value = left_const->getInt() * right_const->getInt();
                        }
                        else if (op == '/')
                        {
                            value = left_const->getInt() / right_const->getInt();
                        }
                        else if (op == '%')
                        {
                            value = left_const->getInt() % right_const->getInt();
                        };
                        auto result = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Int", int32_t(value));
                        return std::dynamic_pointer_cast<ir::User>(result);
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        float value = 0;
                        if (op == '*')
                        {
                            value = left_const->getFloat() * right_const->getFloat();
                        }
                        else if (op == '/')
                        {
                            value = left_const->getFloat() / right_const->getFloat();
                        }
                        else if (op == '%')
                        {
                            throw std::runtime_error("Float is not support modulo");
                        };
                        auto result = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32), "Float", float(value));
                        return std::dynamic_pointer_cast<ir::User>(result);
                    }
                }
            }
            else
            {
                // TODO not static mul
                if (left->getType()->isPrimitive() && right->getType()->isPrimitive())
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        if (op == '*')
                        {
                            auto mul = std::make_shared<ir::Mul>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(mul);
                            return std::dynamic_pointer_cast<ir::User>(mul);
                        }
                        else if (op == '/')
                        {
                            auto div = std::make_shared<ir::SDiv>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(div);
                            return std::dynamic_pointer_cast<ir::User>(div);
                        }
                        else if (op == '%')
                        {
                            auto rem = std::make_shared<ir::SRem>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(rem);
                            return std::dynamic_pointer_cast<ir::User>(rem);
                        };
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        if (op == '*')
                        {
                            auto mul = std::make_shared<ir::FMul>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(mul);
                            return std::dynamic_pointer_cast<ir::User>(mul);
                        }
                        else if (op == '/')
                        {
                            auto div = std::make_shared<ir::FDiv>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(div);
                            return std::dynamic_pointer_cast<ir::User>(div);
                        }
                        else if (op == '%')
                        {
                            throw std::runtime_error("Cannot cal rem for float");
                        };
                    }
                }
            }

            throw std::runtime_error("Mul: Invalid operand types");
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitorMulTwoExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitMulToUnaryExp(SysYParser::MulToUnaryExpContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->unaryExp()->accept(this));
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitMulToUnaryExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitAddToMulExp(SysYParser::AddToMulExpContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->mulExp()->accept(this));
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitAddToMulExp:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitAddTwoExp(SysYParser::AddTwoExpContext *context)
    {
        try
        {
            char op = '\0';
            if (context->Addition())
            {
                op = '+';
            }
            else if (context->Minus())
            {
                op = '-';
            }

            auto left = std::any_cast<std::shared_ptr<ir::User>>(context->addExp()->accept(this));
            auto right = std::any_cast<std::shared_ptr<ir::User>>(context->mulExp()->accept(this));
            if (left->isStaticValue() && right->isStaticValue())
            {
                if (left->getType()->isPrimitive() && right->getType()->isPrimitive())
                {

                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    // Int32 add Int32
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                        auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                        auto left_val = left_const->getInt();
                        auto right_val = right_const->getInt();
                        auto add = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Int32), "Int", op == '+' ? left_val + right_val : left_val - right_val);
                        return std::dynamic_pointer_cast<ir::User>(add);
                        // Float32 add Float32
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        auto left_const = std::dynamic_pointer_cast<ir::StaticValue>(left);
                        auto right_const = std::dynamic_pointer_cast<ir::StaticValue>(right);
                        auto left_val = left_const->getFloat();
                        auto right_val = right_const->getFloat();
                        auto add = std::make_shared<ir::StaticValue>(ir::MakePrimitiveDataType(ir::PrimitiveDataType::TypeID::Float32), "Float", op == '+' ? left_val + right_val : left_val - right_val);
                        return std::dynamic_pointer_cast<ir::User>(add);
                    }
                }
            }
            else
            {
                if (left->getType()->isPrimitive() && right->getType()->isPrimitive())
                {
                    auto left_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(left->getType());
                    auto right_prim = std::dynamic_pointer_cast<ir::PrimitiveDataType>(right->getType());
                    if (left_prim->isInt() && right_prim->isInt())
                    {
                        switch (op)
                        {
                        case '+':
                        {
                            auto add = std::make_shared<ir::Add>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(add);
                            return std::dynamic_pointer_cast<ir::User>(add);
                        }
                        case '-':
                        {
                            auto sub = std::make_shared<ir::Sub>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(sub);
                            return std::dynamic_pointer_cast<ir::User>(sub);
                        }
                        default:
                            break;
                        }
                    }
                    else if (left_prim->isFloat() && right_prim->isFloat())
                    {
                        switch (op)
                        {
                        case '+':
                        {
                            auto fadd = std::make_shared<ir::FAdd>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(fadd);
                            return std::dynamic_pointer_cast<ir::User>(fadd);
                        }
                        case '-':
                        {
                            auto fsub = std::make_shared<ir::FSub>(left, right, ctx_.newVRegName());
                            ctx_.currentBasicBlock->addInstruction(fsub);
                            return std::dynamic_pointer_cast<ir::User>(fsub);
                        }
                        default:
                            break;
                        }
                    }
                    else
                    {
                        // TODO
                    }
                }
            }
            return 0;
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitAddTwoExp:\n" + std::string(e.what()));
        }
    };

    //* @return ir::StaticValue
    std::any VisitorImpl::visitConstExp(SysYParser::ConstExpContext *context)
    {
        try
        {
            auto constExp = std::any_cast<std::shared_ptr<ir::User>>(context->addExp()->accept(this));
            if (constExp->isStaticValue())
            {
                return std::dynamic_pointer_cast<ir::StaticValue>(constExp);
            }
            throw std::runtime_error("constExp is not result in a StaticValue");
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error in visitConstExp:\n" + std::string(e.what()));
        }
    };
}