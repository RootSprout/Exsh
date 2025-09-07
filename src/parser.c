#include "parser.h"
#include <stdlib.h>
#include <stdio.h>


Command *parse_tokens(char **tokens, int ntokens){
    Command *head = NULL;
    Command *curr = NULL;
    int i = 0;

    while(i< ntokens){
        Command *cmd = malloc(sizeof(Command));
        cmd->argv = malloc(64 * sizeof(char*));
        cmd->infile = NULL;
        cmd->outfile = NULL;
        cmd->append = 0;
        cmd->next = NULL;

        int argc = 0;
        while(i< ntokens && strcmp(tokens[i], "|") !=0){
            if(strcmp(tokens[i], ">") == 0){
                i++;
                cmd->outfile = tokens[i++];
            }else if(strcmp(tokens[i], ">>") == 0){
                i++;
                cmd->outfile = tokens[i++];
                cmd->append = 1;
            }else if(strcmp(tokens[i], "<") == 0){
                i++;
                cmd->infile = tokens[i++];
            }else{
                cmd->argv[argc++] = tokens[i++];
            }
        }


        cmd->argv[argc] = NULL;

        if(head == NULL){
            head = cmd;
        }else{
            curr->next = cmd;
            curr = cmd;
        }

        if (i < ntokens && strcmp(tokens[i], "|") == 0) i++;
    }

    return head;
}