#include "parser.h"
#include "executor.h"
#include <stdlib.h>
#include <stdio.h>
#include "builtins.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void execute_commands(Command *cmd){
    Command *curr = cmd;
    int fd_in = 0;
    while(curr){
        int fd[2];

        if(curr->next){
            pipe(fd);
        }

        if(handle_builtins(curr)){
            curr = curr->next;
            continue;
        }

        pid_t pid = fork();
        if (pid == 0){
            if (fd_in!=0) dup2(fd_in, 0);
            if (curr->next) dup2(fd[1],1);

            if(curr->infile){
                int in = open(curr->infile, O_RDONLY);
                dup2(in, 0);
                close(in);
            }

            

        }
    }
}