#include "../include/lexer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** tokenize(char* input, int* ntokens){
    char** tokens = malloc(64 * sizeof(char*));
    int pos = 0;
    char* token = strtok(input, " \t\n");
    while(token!= NULL){
        tokens[pos++] = token;
        token = strtok(NULL, " \t\n");
    }
    tokens[pos] = NULL;
    *ntokens = pos;

    return tokens;
}