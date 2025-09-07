#include "../include/parser.h"
#include "../include/executor.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/builtins.h"
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

            if (curr->outfile) {
                int flags = O_WRONLY | O_CREAT;
                if (curr->append) flags |= O_APPEND;
                else flags |= O_TRUNC;
                int out = open(curr->outfile, flags, 0644);
                dup2(out, 1);
                close(out);
            }

            if (execvp(curr->argv[0], curr->argv) == -1) {
                perror("exec failed");
                exit(1);
            }

        }else {
            wait(NULL);
            if (fd_in != 0) close(fd_in);
            if (curr->next) {
                close(fd[1]);
                fd_in = fd[0];
            }
            curr = curr->next;
        }
    }
}