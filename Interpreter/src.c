//
// Created by nikiavatar98 on 3/5/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "src.h"

Src* openSrc(const char* filename)
{
    Src* src = (Src*)malloc(sizeof(Src));
    assert(src != NULL);

    src->file = fopen(filename, "rt");
    assert(src->file != NULL);

    src->line = 0; src->col = 0;
    src->error = 0; src->eof = 0;

    return src;
}

char next(Src* src)
{
    char c = fgetc(src->file);
    if (feof(src->file)) src->eof = 1;
    if (ferror(src->file)) src->error = 1;
    if (c == '\n')
    {
        src->line++;
        src->col = 0;
    }
    else src->col++;
    return c;
}

char peek(Src* src)
{
    char c = fgetc(src->file);
    fseek(src->file, -1L, SEEK_CUR);
    return c;
}

int getLine(Src* src)
{
    return src->line;
}

int getCol(Src* src)
{
    return src->col;
}

int isEOF(Src* src)
{
    return src->eof;
}

int isError(Src* src)
{
    return src->error;
}

void closeSrc(Src* src)
{
    fclose(src->file);
    free(src);
}

void printError(Src* src, const char* msg)
{
    fprintf(stderr, "[ERROR] {L:%d|C:%d}: %s\n", src->line, src->col, msg);
    system("pause");
}
