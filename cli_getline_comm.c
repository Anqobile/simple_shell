#include "shell.h"

/**
 * _getline_command -  GEts inputs in one line
 * Return: The input.
 */

char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t char_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2); /* blinking command prompt input prompt*/

	if (getline(&lineptr, &char_user, stdin) == -1)
	{
		free(lineptr); /* frees buffer after reading line */
		return (NULL);
	}

	return (lineptr);
}
