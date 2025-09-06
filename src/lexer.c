#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

char** tokenize(char* input, int* ntokens){
    char** tokens = malloc(64 * sizeof(char*));
    int pos = 0;
    char* token = strok(input, " \t\n");
    while(token!= NULL){
        tokens[pos++] = token;
        token = strok(NULL, "\t\n");
    }
    tokens[pos] = NULL;
    *ntokens = pos;
    return tokens;
}