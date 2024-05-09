#include "symbol_table.h"
#include <map>
#include <stack>
#include <string>
#include <iostream>

std::map<std::string, int> table;
std::stack<std::string> stk;

const int UD_TYPE = -1;
const int INT_TYPE = 0;
const int CHAR_TYPE = 1;
const int FLOAT_TYPE = 2;
const int STRING_TYPE = 3;
const int IDENTITY_TYPE = 4;
const int ARRAY_TYPE = 5;

void push(const char * id)
{
    stk.push(id);
}

void pop()
{
    stk.pop();
}

const char * top()
{
    return stk.top().c_str();
}

int empty()
{
    return (int)stk.empty();
}

void insert(const char * _token, int type)
{
    table.emplace(_token, type);
}

int exists(const char * id)
{
    return table.find(id) != table.end();
}

int lookup_type(const char * id)
{
    return table[id];
}

void show_symbol_table()
{
    std::cout << "symbol table:" << std::endl;
    for (const auto &it : table)
        std::cout << it.first << ": " << it.second << std::endl;
}
