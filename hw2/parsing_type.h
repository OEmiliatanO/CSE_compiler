#ifndef __PARSING_TYPE_H__
#define __PARSING_TYPE_H__

const int UD_TYPE = -1;
const int INT_TYPE = 0; // i
const int CHAR_TYPE = 1; // c
const int FLOAT_TYPE = 2; // f
const int STRING_TYPE = 3; // s
const int IDENTITY_TYPE = 4;
const int ARRAY_TYPE = 5; // if 1 dimension, a1T, where T is the type; if 2 dimension, a2T.
                          // it can be a2a2T, the parsing procedure will reduce it to a4T.
const int PROCEDURE_TYPE = 6; // p
const int FUNCTION_TYPE = 7; // n

extern const char* rev_type[6];

#endif
