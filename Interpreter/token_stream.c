//
// Created by nikiavatar98 on 3/5/2018.
//

#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include "token_stream.h"
#define STR_SIZE 255
#define NUM_SIZE 32

void skip_comment(Src* src)
{
    char c;
    while ((c = next(src)) != '\n' && !src->eof);
}

Token* read_string(Src* src)
{
    char c;
    char* str;
    char* str2;
    int i = 0;
    int max = STR_SIZE;
    Token* token;

    // Removing the { " }
    c = next(src);

    // Creating the buffer
    str = (char*) calloc(max, sizeof(char));
    assert(str != NULL);

    // Storing the stream
    while ((c = next(src)) != '\"' && !src->eof)
    {
        if (i+1 >= max)
        {
            max *= 4;
            str2 = (char*) realloc(str ,max*sizeof(char));
            assert(str2 != NULL);
            str = str2;
        }
        str[i++] = c;
    }

    // Adding zero at the back
    str[i] = 0;

    // Creating the token
    token = (Token*)malloc(sizeof(Token));
    assert(token != NULL);
    token->type = string;
    token->value = str;

    return token;
}
Token* read_number(Src* src)
{
    Token* token;
    int dot = 0, c = 0, i = 0;
    char* num = 0;

    // Creating the buffer
    num = (char*) calloc(NUM_SIZE, sizeof(char));
    assert(num != NULL);

    // Storing the number
    while ((isdigit((c = next(src))) || c == '.' ) && !src->eof)
    {
        // Checking if its too big
        if (i >= NUM_SIZE)
        {
            // error
        }

        // Checking for a decimal point
        if (c == '.' && !dot)
        {
            dot = 1;
            num[i++] = '.';
            continue;
        }
        else if (c == '.' && dot)
        {
            break;
        }
        num[i++] = c;
    }

    num[i] = 0;

    // Creating the token
    token = (Token*)malloc(sizeof(Token));
    assert(token != NULL);
    token->type = number;
    token->value = num;

    return token;
}
void freeToken(Token* token)
{
    free(token->value);
    free(token);
}