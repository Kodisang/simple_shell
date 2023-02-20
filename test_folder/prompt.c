#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/* calls _execve passing input from stdin*/
char *prompt(void)
{
	char *buffer;
	size_t bufsize = 1024;
	ssize_t nread;

	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		exit(1);

	write(1, "$ ", 2);
	nread = getline(&buffer, &bufsize, stdin);

	if (nread == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	_execve(buffer);
	write(1, "\n", 1);

	return (0);
}
