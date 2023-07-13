#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <stack>
#include <optional>

#include "IR/MemoryAccess.h"

namespace front
{
  class SymbolTable;
  class Scope
  {
  public:
    explicit Scope(const std::string &name, std::shared_ptr<SymbolTable> symbolTable, std::shared_ptr<Scope> parent)
        : name_(name), symbolTable_(symbolTable), parent_(parent){};
    explicit Scope(const std::string &name, std::shared_ptr<SymbolTable> symbolTable)
        : Scope(name, symbolTable, nullptr){};

    std::shared_ptr<SymbolTable> getSymbolTable() { return symbolTable_; };

    std::shared_ptr<Scope> getParent() { return parent_; };
    void setParent(std::shared_ptr<Scope> parent) { parent_ = parent; };

    void setGlobal() { is_global_ = true; };
    bool isGlobal() { return is_global_; };

    void addSymbol(const std::string &name, const std::shared_ptr<ir::Allocate> &symbol)
    {
      symbols_.insert({name, symbol});
    };

    bool deleteSymbol(const std::string &name)
    {
      return symbols_.erase(name);
    };

    std::optional<std::reference_wrapper<std::shared_ptr<ir::Allocate>>> getSymbol(const std::string name)
    {
      auto current = symbols_.find(name);
      if (current != symbols_.end())
        return current->second; // return value
      return std::nullopt;
    };

  protected:
    std::string name_;
    std::shared_ptr<SymbolTable> symbolTable_;
    std::shared_ptr<Scope> parent_;
    std::unordered_map<std::string, std::shared_ptr<ir::Allocate>> symbols_;
    bool is_global_ = false;
  };

  class SymbolTable
  {
  public:
    SymbolTable() = default;
    ~SymbolTable() = default;

    std::shared_ptr<SymbolTable> get()
    {
      return std::shared_ptr<SymbolTable>(this);
    };

    void addSymbolToCurrentScope(const std::string &name, const std::shared_ptr<ir::Allocate> &symbol);

    void addSymbolToGlobalScope(const std::string &name, const std::shared_ptr<ir::Allocate> &symbol);

    bool deleteSymbol(const std::string &name, bool recursive);

    std::optional<std::reference_wrapper<std::shared_ptr<ir::Allocate>>> getSymbol(const std::string &name, bool recursive);

    void pushScope(const std::string &name);

    void popScope();

    std::shared_ptr<Scope> getCurrentScope();
  protected:
    std::stack<std::shared_ptr<Scope>> scopes_;
  };

}