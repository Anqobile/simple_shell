#include "shell.h"

/**
 * tokenize - tokenizes an input stirng
 * @lineptr: user input to e tokenized
 * Return: a ptr to arr of ptrs ith tokenized string
 */

char **tokenize(char *lineptr)
{
	char **user_comm = NULL;
	char *token = NULL;
	size_t x = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (x = 0; lineptr[x]; x++)
	{
		if (lineptr[x] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	user_comm = malloc(sizeof(char *) * (size + 2));
	if (user_comm == NULL)
		return (NULL);

	token = strtok(lineptr, " \n\t\r");

	for (x = 0; token != NULL; x++)
	{
		user_comm[x] = token;
		token = strtok(NULL, " \n\t\r");
	}
	user_comm[x] = NULL;
	return (user_comm);
}
