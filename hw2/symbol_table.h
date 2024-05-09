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
    void insert(const char * _token, int type);
    int exists(const char * id);
    int lookup_type(const char * id);
    void show_symbol_table(void);
#ifdef __cplusplus
}
#endif

#endif
