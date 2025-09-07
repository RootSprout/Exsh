#include "builtins.h"
#include "parser.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int handle_builtins(Command *cmd){
    if(cmd->argv[0] == NULL){
        return 0;
    }

    if(strcmp(cmd->argv[0], "cd") == 0){
        if(cmd->argv[1]){
            chdir(cmd->argv[1]);
        }else{
            chdir(getenv("HOME"));
        }
        return 1;
    }else if(strcmp(cmd->argv[0], "exit") == 0){
        exit(0);
    }

    return 0; //not builtin
}
