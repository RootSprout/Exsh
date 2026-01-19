#include "../include/builtins.h"
#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>
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
    }else if(strcmp(cmd->argv[0], "pwd") == 0){
        char cwd[1024];
        if(getcwd(cwd, sizeof(cwd)) != NULL){
            printf("%s\n", cwd);
        }else{
            perror("pwd error");
        }
        return 1;
    }else if(strcmp(cmd->argv[0], "echo") == 0){
        for(int i = 1; cmd->argv[i] != NULL; i++){
            printf("%s ", cmd->argv[i]);
        }
        printf("\n");
        return 1;
    }else if(strcmp(cmd->argv[0], "export") == 0){
        if(cmd->argv[1]){
            char *arg = cmd->argv[1];
            char *eq = strchr(arg, '=');
            if(eq){
                *eq = '\0';
                setenv(arg, eq + 1, 1);
            }else{
                setenv(arg, "", 1);
            }
        }
        return 1;
    }else if(strcmp(cmd->argv[0], "exit") == 0){
        exit(0);
    }
    return 0; //not builtin
}
