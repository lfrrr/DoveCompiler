#include "VisitorImpl.h"

namespace front
{

    std::any VisitorImpl::visitVarDecl(SysYParser::VarDeclContext *context)
    {
        try
        {
            context->bType()->accept(this);
            auto allocates = std::vector<std::shared_ptr<ir::Allocate>>();
            for (auto varDef : context->varDef())
            {
                auto allocate = std::any_cast<std::shared_ptr<ir::Allocate>>(varDef->accept(this));
                allocates.push_back(allocate);
            }
            return allocates;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitVarDecl:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitUnInitVarDef(SysYParser::UnInitVarDefContext *context)
    {
        try
        {

            std::shared_ptr<ir::Allocate> allocate;
            std::string varName = context->Identifier()->getSymbol()->getText();
            std::shared_ptr<ir::Type> a_type = MakePrimitiveDataType(ctx_.currentDeclTypeId);

            if (context->constExp().size() > 0)
            {
                auto constExps = context->constExp();
                std::reverse(constExps.begin(), constExps.end());
                for (auto constExp : constExps)
                {
                    // idx requests a StaticValue
                    auto size_sv = std::any_cast<std::shared_ptr<ir::StaticValue>>(constExp->accept(this));
                    assert(size_sv->isInt());
                    size_t size_val = size_sv->getInt();
                    a_type = MakeArrayType(a_type, size_val);
                }
            }

            if (ctx_.symbolTable->getCurrentScope()->isGlobal())
            {
                // static init
                std::shared_ptr<ir::StaticValue> initVal = ir::MakeEmptyStaticValue(a_type, varName);
                allocate = std::make_shared<ir::Allocate>("%" + varName, false, initVal);
            }
            else
            {
                allocate = std::make_shared<ir::Allocate>(a_type, "%" + varName);
                ctx_.currentBasicBlock->addInstruction(allocate);
            }
            auto sym = std::make_shared<Symbol>(allocate->getName(), allocate);
            ctx_.symbolTable->addSymbolToCurrentScope(varName, sym);

            return allocate;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitUnInitVarDef:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitInitVarDef(SysYParser::InitVarDefContext *context)
    {
        try
        {
            std::shared_ptr<ir::Allocate> allocate;
            auto varName = context->Identifier()->getSymbol()->getText();
            std::shared_ptr<ir::Type> a_type = MakePrimitiveDataType(ctx_.currentDeclTypeId);

            if (context->constExp().size() > 0)
            {
                auto constExps = context->constExp();
                std::reverse(constExps.begin(), constExps.end());
                for (auto constExp : constExps)
                {
                    // idx requests a StaticValue
                    auto size_sv = std::any_cast<std::shared_ptr<ir::StaticValue>>(constExp->accept(this));
                    assert(size_sv->isInt());
                    size_t size_val = size_sv->getInt();
                    a_type = MakeArrayType(a_type, size_val);
                }
            }

            if (ctx_.symbolTable->getCurrentScope()->isGlobal())
            {
                // static init
                std::shared_ptr<ir::StaticValue> initVal = ir::MakeEmptyStaticValue(a_type, varName);

                ctx_.currentInitValue.push(initVal);
                context->initVal()->accept(this);
                ctx_.currentInitValue.pop();

                allocate = std::make_shared<ir::Allocate>("%" + varName, false, initVal);
            }
            else
            {
                allocate = std::make_shared<ir::Allocate>(a_type, "%" + varName);
                ctx_.currentAllocate = allocate;
                ctx_.currentBasicBlock->addInstruction(allocate);
                context->initVal()->accept(this);
            }

            auto sym = std::make_shared<Symbol>(allocate->getName(), allocate);
            ctx_.symbolTable->addSymbolToCurrentScope(varName, sym);

            return allocate;
        }
        catch (std::exception &e)
        {
            throw std::runtime_error("Error in visitInitVarDef:\n" + std::string(e.what()));
        }
    };

    std::any VisitorImpl::visitScalarInitVal(SysYParser::ScalarInitValContext *context)
    {
        if (ctx_.symbolTable->getCurrentScope()->isGlobal())
        {
            auto init_target = ctx_.currentInitValue.top();
            auto user = std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
            std::shared_ptr<ir::StaticValue> static_value;
            if (user->isStaticValue())
            {
                static_value = std::dynamic_pointer_cast<ir::StaticValue>(user);
            }
            else
            {
                throw std::runtime_error("Global decl of variable must be static");
            }

            if (init_target->getType()->isPrimitive() && static_value->getType()->isPrimitive())
            {
                if (std::dynamic_pointer_cast<ir::PrimitiveDataType>(init_target->getType())->getTypeId() == std::dynamic_pointer_cast<ir::PrimitiveDataType>(static_value->getType())->getTypeId())
                {
                    if (init_target->isInt())
                    {
                        init_target->setStaticValue(static_value->getInt());
                    }
                    else if (init_target->isFloat())
                    {
                        init_target->setStaticValue(static_value->getFloat());
                    }
                }
                return 0;
            }
            else if (init_target->isArray() && static_value->getType()->isPrimitive())
            {
                auto m_target = init_target;
                while (m_target->isArray())
                {
                    try
                    {
                        m_target = m_target->at(0);
                    }
                    catch (std::exception &e)
                    {
                        throw std::runtime_error("Empty target init array");
                    }
                }
                if (m_target->isInt())
                {
                    m_target->setStaticValue(static_value->getInt());
                }
                else if (m_target->isFloat())
                {
                    m_target->setStaticValue(static_value->getFloat());
                }
                return 0;
            }
            throw std::runtime_error("Global decl of variable must be static");
        }
        else
        {
            // no subs var
            if (!ctx_.isElement)
            {
                auto val = std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
                auto store = std::make_shared<ir::Store>(val, ctx_.currentAllocate);
                ctx_.currentBasicBlock->addInstruction(store);
                return std::dynamic_pointer_cast<ir::User>(store);
            }
            else // sub var
            {
                auto val = std::any_cast<std::shared_ptr<ir::User>>(context->exp()->accept(this));
                auto store = std::make_shared<ir::Store>(val, ctx_.currentElementPtr);
                ctx_.isElement = false;
                ctx_.currentBasicBlock->addInstruction(store);
                return std::dynamic_pointer_cast<ir::User>(store);
            }
            throw std::runtime_error("Init var has wrong format.");
        }
    };

    std::any VisitorImpl::visitListInitVal(SysYParser::ListInitValContext *context)
    {
        if (ctx_.symbolTable->getCurrentScope()->isGlobal())
        {
            auto init_target = ctx_.currentInitValue.top();
            if (init_target->isArray())
            {
                int i = 0;
                for (auto initVal : context->initVal())
                {
                    ctx_.isElement = true;
                    ctx_.currentInitValue.push(init_target->at(i));
                    initVal->accept(this);
                    ctx_.currentInitValue.pop();
                    i++;
                }
            }
            else
            {
                throw std::runtime_error("List init must for an array value.");
            }
            return 0;
        }
        else
        {
            // for(auto initVal : context->initVal())
            // {
            //     auto getElementPtr = std::make_shared<ir::GetElementPtr>(ctx_.currentAllocate,);
            //     ctx_.isElement = true;
            //     initVal->accept(this);
            // }
            return 0;
        }
        return 0;
    };
}