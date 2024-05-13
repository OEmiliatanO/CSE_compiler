#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

#ifdef __cplusplus
extern "C"
{
#endif
    void push(const char * id);
    void pop(void);
    const char * top(void);
    int empty(void);
    void insert(const char * _token, const char * type);
    int exists(const char * id);
    const char * lookup_type(const char * id);
    const char * cpretty(const char * rtype);
    void show_symbol_table(void);
#ifdef __cplusplus
}
#endif

#endif
