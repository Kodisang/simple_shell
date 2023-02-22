#include "shell.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char *line;
    char *argv[100];
    size_t len = 0;
    pid_t pid;
    int status;

    while (1) {
        printf("$ ");
        getline(&line, &len, stdin);

        int i = 0;
        argv[i] = strtok(line, " \n");

        while (argv[i] != NULL) {
            i++;
            argv[i] = strtok(NULL, " \n");
        }

        if (argv[0] == NULL) {
            continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            exit(0);
        }

        pid = fork();

        if (pid == 0) {
            if (execve(argv[0], argv, NULL) == -1) {
                perror(argv[0]);
            }

            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return (0);
}

