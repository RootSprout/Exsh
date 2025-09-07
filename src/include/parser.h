#pragma once

typedef struct Command{
    char **argv;
    char *infile;
    char *outfile;
    int append;
    struct Command *next;
}Command;

Command *parse_tokens(char **tokens, int ntokens);
void free_cmd(Command *cmd);
