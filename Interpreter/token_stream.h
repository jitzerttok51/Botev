//
// Created by nikiavatar98 on 3/5/2018.
//
#ifndef token_stream_h
#define token_stream_h

#include "src.h"
#define STR_SIZE 255

typedef enum{
    string, number, punc, kw, op, var
}Type;

typedef struct{
    Type  type;
    char* value;
}Token;

void skip_comment(Src* src);
Token* read_string(Src* src);
Token* read_number(Src* src);
void freeToken(Token* token);
#endif