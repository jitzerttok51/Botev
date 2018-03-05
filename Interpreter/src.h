//
// Created by nikiavatar98 on 3/5/2018.
//
#ifndef src_h
#define src_h

#include <stdio.h>

typedef struct {
    FILE* file;
    int line, col;
    int eof, error;
}Src;

Src* openSrc(const char* filename);
char next(Src* src);
char peek(Src* src);
int getLine(Src* src);
int getCol(Src* src);
int isEOF(Src* src);
int isError(Src* src);
void closeSrc(Src* src);
void printError(Src* src, const char* msg);

#endif