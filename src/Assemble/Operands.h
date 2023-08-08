#include <cstdint>

namespace asmgen
{
    enum class OperandType
    {
        Error,
        VRegisterR,
        VRegisterS,
        Immediate,
        StackPointer,
        Label,
        None
    };

    class Operand
    {
    public:
        void setCount(int32_t count)
        {
            cnt = count;
        };

        int getCount() const
        {
            return cnt;
        };

        const int id;

        Operand();

        virtual OperandType getOpndType() const { return OperandType::Error; };

        virtual ~Operand() = default;

    protected:
        int cnt;
    };

    class VRegisterR : public Operand
    {
    public:
        VRegisterR(int32_t id) : Operand(), id(id){};

        OperandType getOpndType() const override { return OperandType::VRegisterR; };

        const int32_t id;
    };

    class VRegisterS : public Operand
    {
    public:
        VRegisterS(int32_t id) : Operand(), id(id){};

        OperandType getOpndType() const override { return OperandType::VRegisterS; };

        const int32_t id;
    };

    class Immediate : public Operand
    {
    public:
        Immediate(int32_t value, std::stringstream &bss) : Operand(), value(value), bss_(bss){};

        OperandType getOpndType() const override { return OperandType::Immediate; };

        std::string toString() const
        {
            if (value < 128 && value >= -128)
            {

                return "#" + std::to_string(value);
            }
            else
            {
                std::string str = "_const_imm_" + std::to_string(value);
                bss_ << str << ": .word " << value << std::endl;
                return "=" + str;
            }
        };

        const int32_t value;
        std::stringstream &bss_;
    };

    class StackPointer : public Operand
    {
    public:
        StackPointer() : Operand(){};

        OperandType getOpndType() const override { return OperandType::StackPointer; };
    };

}