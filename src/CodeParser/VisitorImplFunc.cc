#include <vector>

#include "VisitorImpl.h"

namespace front
{
    std::any VisitorImpl::visitFuncDef(SysYParser::FuncDefContext *context)
    {
        try
        {
            ctx_.vRegCounter = utils::Counter(0);
            auto typeID = std::any_cast<ir::PrimitiveDataType::TypeID>(context->funcType()->accept(this));
            std::string funcName = context->Identifier()->getSymbol()->getText();
            ctx_.currentFunction = std::make_shared<ir::Function>(ir::MakePrimitiveDataType(typeID), funcName);
            ctx_.symbolTable->pushScope("function");

            if (context->funcFparamList())
            {
                context->funcFparamList()->accept(this);
            }

            if (context->block())
            {
                // Add entry basic block to function
                auto entry_bb_name = "_" + funcName + "_entry";
                auto bb = std::make_shared<ir::BasicBlock>(entry_bb_name, ir::BasicBlock::BlockType::FunctionEntry);
                ctx_.currentBasicBlock = bb;
                ctx_.currentFunction->addBasicBlock(bb);

                context->block()->accept(this);
            }
            else
            {
                ctx_.currentFunction->setExtern(true);
            }

            ctx_.symbolTable->popScope();
            return ctx_.currentFunction;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitFuncDef:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitFuncType(SysYParser::FuncTypeContext *context)
    {
        auto typeID = ir::PrimitiveDataType::TypeID::Void;
        if (context->Void())
        {
            typeID = ir::PrimitiveDataType::TypeID::Void;
        }
        else if (context->Int())
        {
            typeID = ir::PrimitiveDataType::TypeID::Int32;
        }
        else if (context->Float())
        {
            typeID = ir::PrimitiveDataType::TypeID::Float32;
        }
        return typeID;
    };

    std::any VisitorImpl::visitFuncFparamList(SysYParser::FuncFparamListContext *context)
    {
        try
        {
            for (auto funcFparam : context->funcFparam())
            {
                funcFparam->accept(this);
            }
            return 0;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitFuncFparamList:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitFuncFparam(SysYParser::FuncFparamContext *context)
    {
        try
        {
            context->bType()->accept(this);
            std::string name = context->Identifier()->getSymbol()->getText();
            std::shared_ptr<ir::Type> a_type = ir::MakePrimitiveDataType(ctx_.currentDeclTypeId);

            if (context->constExp().size() > 0)
            {

                auto constExps = context->constExp();
                std::reverse(constExps.begin(), constExps.end());
                for (auto constExp : constExps)
                {
                    auto size_sv = std::any_cast<std::shared_ptr<ir::StaticValue>>(constExp->accept(this));
                    if (size_sv->isInt())
                    {
                        throw std::runtime_error("Error in visitFuncFparam: Array size must be int");
                    }
                    size_t size_val = size_sv->getInt();
                    a_type = ir::MakeArrayType(a_type, size_val);
                }
            }

            auto allocate = std::make_shared<ir::Allocate>(a_type, name);
            auto sym = std::make_shared<Symbol>(name, allocate);
            ctx_.symbolTable->addSymbolToCurrentScope(name, sym);
            ctx_.currentFunction->addArgument(allocate);
            return std::dynamic_pointer_cast<ir::User>(allocate);
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitFuncFparam:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitFuncRparamList(SysYParser::FuncRparamListContext *context)
    {
        try
        {
            std::vector<std::shared_ptr<ir::User>> rparams;
            for (auto rparam : context->funcRparam())
            {
                auto rparam_value = std::any_cast<std::shared_ptr<ir::User>>(rparam->accept(this));
                rparams.push_back(rparam_value);
            }
            return rparams;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitFuncRparamList:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitExpAsRparam(SysYParser::ExpAsRparamContext *context)
    {
        try
        {
            return std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitExpAsRparam:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitStringAsRparam(SysYParser::StringAsRparamContext *context)
    {
        try
        {
            std::string str = context->STRING()->getSymbol()->getText();
            str = str.substr(1, str.size() - 2);
            throw std::runtime_error("Error in visitStringAsRparam: String literal not supported");
            auto sv = std::make_shared<ir::StaticValue>("string", 1);
            return std::dynamic_pointer_cast<ir::User>(sv);
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitStringAsRparam:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitUnaryFuncCallExp(SysYParser::UnaryFuncCallExpContext *context)
    {
        try
        {
            std::string funcName = context->Identifier()->getText();
            std::vector<std::shared_ptr<ir::User>> params;
            if (context->funcRparamList())
            {
                params = std::any_cast<std::vector<std::shared_ptr<ir::User>>>(context->funcRparamList()->accept(this));
            }
            auto func = ctx_.compUnit->getFunction(funcName);
            auto call = std::make_shared<ir::Call>(func, params, ctx_.newVRegName());
            ctx_.currentBasicBlock->addInstruction(call);
            return std::dynamic_pointer_cast<ir::User>(call);
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitUnaryFuncCallExp:\n" + std::string(e.what()));
        }
    };

}