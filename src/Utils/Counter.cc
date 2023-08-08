#include <cstdint>

#include "Counter.h"

namespace utils
{
    int32_t Counter::next()
    {
        return counter_++;
    }
    int32_t Counter::get()
    {
        return counter_;
    }
}