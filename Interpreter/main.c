#include <stdio.h>
#include "token_stream.h"
#include "src.h"

int main() {
    Token *token1, *token2, *token3;
    Src* src = openSrc("..//Resource//test.btv");
    token1 = read_number(src);
    token2 = read_number(src);
    token3 = read_number(src);
    freeToken(token1);
    freeToken(token2);
    freeToken(token3);
    closeSrc(src);
    return 0;
}