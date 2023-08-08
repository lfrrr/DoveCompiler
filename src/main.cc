#include <iostream>
#include <sstream>

#include <antlr4-runtime.h>
#include <SysYLexer.h>
#include <SysYParser.h>

#include "main.h"

#include "Utils/Configure.h"
#include "Utils/CONSTANTS.h"
#include "CodeParser/VisitorImpl.h"
#include "Assemble/AsmGen.h"

int main(int argc, char *argv[])
{
    config::init(argc, argv);
    std::cout << config::get() << std::endl;

    auto sstream = std::stringstream();
    auto source = std::ifstream();
    source.open(config::get().src_file_path);
    sstream << CONSTANTS::kPrebuiltDecl << std::endl;
    sstream << source.rdbuf();

    antlr4::ANTLRInputStream input(sstream);
    front::SysYLexer m_lexer(&input);
    antlr4::CommonTokenStream tokens(&m_lexer);
    front::SysYParser m_parser(&tokens);
    // m_parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());
    front::SysYParser::CompUnitContext *root = m_parser.compUnit();

    //	front : ast => ir
    auto visitor = front::VisitorImpl();
    auto irp = std::any_cast<std::shared_ptr<ir::CompUnit>>(root->accept(&visitor));
    auto dh = ir::DumpHelper();
    irp->dump(dh);
    std::string output = dh.dump();
    std::cout << output << std::endl;

    // back
    auto asm_gen = asmgen::AsmGenerator(irp);
    asm_gen.generate();
    auto asm_code = asm_gen.exportToString();
    std::cout << asm_code << std::endl;
    asm_gen.exportToFile(config::get().dst_file_path);

    std::cout << "Bye" << std::endl;
    return 0;
}