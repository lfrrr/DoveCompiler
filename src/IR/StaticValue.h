#pragma once

#include <memory>

#include "Type.h"
#include "User.h"

namespace ir
{
    class StaticValue : public User
    {
    public:
        explicit StaticValue(std::shared_ptr<Type> type, std::string name, int32_t val) : User(type, std::to_string(val)), is_int_(true), int_val_(val) { value_type_ = ValueType::StaticValue; }
        explicit StaticValue(std::shared_ptr<Type> type, std::string name, float val) : User(type, std::to_string(val)), is_float_(true), float_val_(val) { value_type_ = ValueType::StaticValue; }
        explicit StaticValue(std::string name, int32_t val) : User(MakePrimitiveDataType(PrimitiveDataType::TypeID::Int32), std::to_string(val)), is_int_(true), int_val_(val) { value_type_ = ValueType::StaticValue; }
        explicit StaticValue(std::string name, float val) : User(MakePrimitiveDataType(PrimitiveDataType::TypeID::Float32), std::to_string(val)), is_float_(true), float_val_(val) { value_type_ = ValueType::StaticValue; }
        explicit StaticValue(std::shared_ptr<Type> type, std::string name, std::vector<std::shared_ptr<StaticValue>> vals) : User(type, std::move(name)), is_array_(true), array_vals_(vals) { value_type_ = ValueType::StaticValue; }
        std::string dump(DumpHelper &helper) const override
        {
            std::string output = "";
            if (is_int_)
            {
                output += std::to_string(int_val_);
            }
            else if (is_float_)
            {
                output += std::to_string(float_val_);
            }
            else if (is_array_)
            {
                output += "[";
                for (size_t i = 0; i < array_vals_.size(); i++)
                {
                    output += array_vals_[i]->dump(helper) + ", ";
                }

                output += "]";
            }

            return output;
        }

        void setStaticValue(int32_t val)
        {
            setType(MakePrimitiveDataType(PrimitiveDataType::TypeID::Int32));
            int_val_ = val;
        }

        void setStaticValue(float val)
        {
            setType(MakePrimitiveDataType(PrimitiveDataType::TypeID::Float32));
            float_val_ = val;
        }

        void setStaticValue(bool val)
        {
            if (val)
            {
                setStaticValue(1);
            }
            else
            {
                setStaticValue(0);
            }
        }

        void setStaticValue(std::vector<std::shared_ptr<StaticValue>> vals)
        {
            array_vals_.clear();
            for (auto val : vals)
            {
                array_vals_.push_back(val);
            }
        }

        bool isInt() const
        {
            return type_->isPrimitive() && std::dynamic_pointer_cast<PrimitiveDataType>(type_)->isInt();
        }

        bool isFloat() const
        {
            return type_->isPrimitive() && std::dynamic_pointer_cast<PrimitiveDataType>(type_)->isFloat();
        }

        bool isArray() const
        {
            return type_->isArray();
        }

        int32_t getInt() const
        {
            if (isInt())
            {
                return int_val_;
            }
            throw std::runtime_error("StaticValue::getInt() is not supported for non-int type");
        }

        float getFloat() const
        {
            if (isFloat())
            {
                return float_val_;
            }
            throw std::runtime_error("StaticValue::getFloat() is not supported for non-float type");
        }

        std::shared_ptr<StaticValue> at(size_t idx) const
        {
            if (isArray())
            {
                // array_vals is 1-D format for n-d arr, so we need to convert idx to 1-D
                auto vals = std::vector<std::shared_ptr<StaticValue>>();
                auto ele_len = std::dynamic_pointer_cast<ArrayType>(getType())->getElementType()->count();
                for (size_t i = 0; i < ele_len; i++)
                {
                    vals.push_back(array_vals_[idx * ele_len + i]);
                }
                auto static_value = std::make_shared<StaticValue>(std::dynamic_pointer_cast<ArrayType>(getType())->getElementType(), getName(), vals);
                return static_value;
            }
            throw std::runtime_error("StaticValue::at(size_t idx) is not supported for non-array type");
        }

        size_t getLen() const
        {
            if (isArray())
            {
                return std::dynamic_pointer_cast<ArrayType>(getType())->getLen();
            }
            throw std::runtime_error("StaticValue::getLen() is not supported for non-array type");
        }

        std::shared_ptr<StaticValue> at(std::vector<size_t> idxs) const
        {
            if (isArray())
            {
                auto val = at(idxs[0]);
                if (val->isArray())
                {
                    return val->at(std::vector<size_t>(idxs.begin() + 1, idxs.end()));
                }
                else
                {
                    if (idxs.size() != 0)
                        throw std::runtime_error("StaticValue::at(std::vector<size_t> idxs) has more elements than array dimension");
                    return val;
                }
            }
            throw std::runtime_error("StaticValue::at(std::vector<size_t> idxs) is not supported for non-array type");
        }

        std::vector<std::shared_ptr<StaticValue>> getArray() const
        {
            std::vector<std::shared_ptr<StaticValue>> vals;
            if (isArray())
            {
                for (size_t i = 0; i < std::dynamic_pointer_cast<ArrayType>(getType())->getLen(); i++)
                {
                    vals.push_back(at(i));
                }
                return vals;
            }
            throw std::runtime_error("StaticValue::getArray() is not supported for non-array type");
        }

    protected:
        bool is_int_ = false;
        int32_t int_val_ = 0;
        bool is_float_ = false;
        float float_val_ = .0f;
        bool is_array_ = false;
        // array_vals is 1-D format for n-d arr
        std::vector<std::shared_ptr<StaticValue>> array_vals_ = std::vector<std::shared_ptr<StaticValue>>(0);
    };

    std::shared_ptr<StaticValue> MakeEmptyStaticValue(std::shared_ptr<Type> type, std::string name);
}