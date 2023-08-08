#pragma once

#include <cstdint>

namespace utils
{
  class Counter
  {
  public:
    Counter() : Counter(0){};
    Counter(int32_t init) : counter_(init){};
    int32_t next();
    int32_t get();

  protected:
    int32_t counter_;
  };
} // namespace 
