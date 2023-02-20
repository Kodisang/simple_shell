#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int _execve(char *to_execute)
{
	char *argv[] = {NULL};
	char *envp[] = {NULL};
	char *path = to_execute;
	int ret;

	argv[0] = to_execute;

	ret = execve(path, argv, envp);

	if (ret == -1)
	{
		perror("execve");
	}

	return 0;
}
/* @to_exec - the path to execute */
