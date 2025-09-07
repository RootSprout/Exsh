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
    printf("Tokens:\n");
    for (int t = 0; t < ntokens; t++) {
        printf("  [%d] %s\n", t, tokens[t]);
    }

    return tokens;
}