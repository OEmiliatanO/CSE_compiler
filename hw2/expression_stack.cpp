#include "expression_stack.h"
#include <cstdlib>
#include <cstring>
#include <stack>

std::stack<node_t> exp_stk;

void exp_push(int kind, const char * type)
{
    node_t node;
    node.kind = kind;
    strcpy(node.type, type);
    exp_stk.emplace(node);
}

void exp_pop()
{
    exp_stk.pop();
}
node_t exp_top()
{
    return exp_stk.top();
}
int exp_empty()
{
    return (int)exp_stk.empty();
}
