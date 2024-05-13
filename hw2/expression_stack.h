#ifndef __EXPRESSION_STACK_H__
#define __EXPRESSION_STACK_H__

#ifdef __cplusplus
extern "C"
{
#endif
    const int KIND_NUM = 0, KIND_OP = 1;
    const int EXP_UDF = -923;
    typedef struct node_t
    {
        int kind; // operator or identity
        char type[10]; // type of identity (int, float, ...)
    }node_t;

    void exp_push(int kind, const char* type);
    void exp_pop(void);
    node_t exp_top(void);
    int exp_empty(void);
#ifdef __cplusplus
}
#endif

#endif
