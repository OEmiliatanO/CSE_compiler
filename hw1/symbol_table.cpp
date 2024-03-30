#include "symbol_table.h"
#include <unordered_set>
#include <string>
#include <iostream>

std::unordered_set<std::string> table;

void insert(const char * _token)
{
    table.emplace(_token);
}

void show_symbol_table()
{
    std::cout << "symbol table:" << std::endl;
    for (const auto &token : table)
        std::cout << token << std::endl;
}
