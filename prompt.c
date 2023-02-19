/*
 * File: prompt.c
 * Auth: Alfredo Kambasha
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *buffer_delim(char *buffer, long int len);

/**
 * prompt - brings up a prompt.
 * Description: upon bringing up a prompt, the function waits for
 *		the user to enter a string for processing by other
 *		functions.
 *
 * Return: 0 on success or specified error messages on failure.
 */
char *prompt(void)
{
	int status = 1;
	char *buffer;
	size_t bufsize = 1024;
	ssize_t nread;

	buffer = (char *)malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
		exit(1);

	write(1, "$ ", 2);
	nread = getline(&buffer, &bufsize, stdin);

	if (nread == -1)
		exit(1);

	else
	{
		buffer = buffer_delim(buffer, nread);
		status = _execve(buffer);
	}
	if (status == 0)
		prompt();

	return (0);
}

/**
 * buffer_delim - truncates the newline character from
 *		  the output of getline()
 * @buffer: the string to truncate.
 * @len: length of @buffer + newline character.
 *
 * Return: returns truncated @buffer without newline character.
 */
char *buffer_delim(char *buffer, long int len)
{
	int i;
	char *buf_delim;

	buf_delim = malloc(sizeof(char) * len - 1);
	if (buf_delim == NULL)
		exit(1);

	for (i = 0; i < len - 1; i++)
		buf_delim[i] = buffer[i];

	return (buf_delim);
}
