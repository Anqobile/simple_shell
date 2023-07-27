#include "shell.h"

/**
 * _get_path - get variable PATH (holds path to working dir).
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
	size_t index = 0, var = 0, countr = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH=", 5); index++)
		;
	if (env[index] == NULL)
		return (NULL);

	for (countr = 5; env[index][var]; var++, countr++)
		;
	path = malloc(sizeof(char) * (countr + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, countr = 0; env[index][var]; var++, countr++)
		path[countr] = env[index][var];

	path[countr] = '\0';
	return (path);
}
