#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "AsmGen.h"
#include "IR/BasicBlock.h"
#include "IR/ControlFlow.h"

namespace asmgen
{
    std::string AsmGenerator::exportToString()
    {
        return s_.str();
    }

    void AsmGenerator::exportToFile(std::string path)
    {
        std::ofstream outfile;
        outfile.open(path, std::ios::out | std::ios::trunc);
        outfile << s_.str();
        outfile.close();
    }
}