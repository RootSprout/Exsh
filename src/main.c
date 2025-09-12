#include <stdio.h>
#include <stdlib.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/executor.h"

int main() {
    char line[1024];

    while (1) {
        printf("Exsh$ ");
        if (!fgets(line, sizeof(line), stdin)) break;

        int ntokens;
        char **tokens = tokenize(line, &ntokens);
        if (ntokens == 0) continue;

        Command *cmds = parse_tokens(tokens, ntokens);
        execute_commands(cmds);
        free_cmd(cmds);
    }
    return EXIT_SUCCESS;
}
