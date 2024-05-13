#include "symbol_table.h"
#include "parsing_type.h"
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <iostream>

std::map<std::string, std::string> table;
std::stack<std::string> stk;

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

void insert(const char * _token, const char * type)
{
    table.emplace(_token, type);
}

int exists(const char * id)
{
    return table.find(id) != table.end();
}

const char* lookup_type(const char * id)
{
    if (table.find(id) != table.end())
        return table[id].c_str();
    return "UNDEFINED";
}

std::string pretty(std::string rtype)
{
    if (rtype == "i")
        return "integer";

    if (rtype == "f")
        return "float";
    
    if (rtype == "s")
        return "string";
    
    if (rtype == "c")
        return "char";

    if (rtype[0] == 'a')
        return "array of " + pretty(rtype.substr(rtype.size() - 1));

    if (rtype == "p")
        return "procedure";
    
    if (rtype[0] == 'n')
        return "function that returns " + pretty(rtype.substr(1));

    return "undefined type";
}

const char * cpretty(const char * rtype)
{
    static char res[100];

    if (rtype[0] == 'i')
        return "integer";

    if (rtype[0] == 'f')
        return "float";
    
    if (rtype[0] == 's')
        return "string";
    
    if (rtype[0] == 'c')
        return "char";

    if (rtype[0] == 'a')
    {
        strcpy(res, "array of ");
        strcat(res, cpretty(rtype+strlen(rtype)-1));
        return res;
    }

    if (rtype == "p")
        return "procedure";

    if (rtype[0] == 'n')
    {
        strcpy(res, "function that returns ");
        strcat(res, cpretty(rtype+1));
        return res;
    }

    return "undefined type";
}

void show_symbol_table()
{
    std::cout << "===== symbol table =====" << std::endl;
    for (const auto &it : table)
        std::cout << it.first << ": " << pretty(it.second) << std::endl;
}
