#include "shell.h"

/**
 * _getenv - prnts environment to standard output
 * @env: enviroment (interactive or non-interactive mode)
 */

void _getenv(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
