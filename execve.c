/*
 * File: execve.c
 * Auth: Alfredo Kambasha
 */

#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _execve - executes a program specified by @to_execute
 * @to_execute: the path of the program to execute.
 *
 * Description: this function takes a string parameter passed from
 *		prompt.c, then checks if it exists and executes.
 * Return: 0 on success or specified error messages on failure.
 */
int _execve(char *to_execute)
{
	pid_t pid;
	int status;
	char *argv[] = {"placeholder", NULL};

	argv[0] = to_execute;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL))
		{
			perror("./hsh");
			return (1);
		}
	}
	else
		waitpid(pid, &status, 0);

	return (0);
}
