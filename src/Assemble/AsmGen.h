#pragma once

#include <memory>
#include <string>
#include <sstream>

#include "IR/ControlFlow.h"

namespace asmgen
{
  class AsmGenerator
  {
  public:
    AsmGenerator(std::shared_ptr<ir::CompUnit> comp_unit) : comp_unit_(comp_unit){};
    ~AsmGenerator() = default;




    void genCompUnit(std::shared_ptr<ir::CompUnit> node);
    std::string globalStaticValue(std::shared_ptr<ir::StaticValue> node);
    std::string memStaticValue(std::shared_ptr<ir::StaticValue> node);


    void generate();

    void construct();

    std::string exportToString();

    void exportToFile(std::string path);
  protected:
    std::shared_ptr<ir::CompUnit> comp_unit_;
    std::stringstream s_;
    std::stringstream data_;
    std::stringstream bss_;
    std::stringstream text_;
  };
}