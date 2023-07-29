#include "shell.h"

/**
 * _getline_command -  GEts inputs in one line
 * Return: The input.
 */

char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t char_user = 0;
	char *hash_pos; /*added after 29 july*/

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2); /* blinking command prompt input prompt*/

	if (getline(&lineptr, &char_user, stdin) == -1)
	{
		free(lineptr); /* frees buffer after reading line */
		return (NULL);
	}
	/*added after 29 july*/
	hash_pos = (char*)strchr(lineptr, '#');
	if (hash_pos != NULL)
	{
		*hash_pos = '\0';
	}
	return (lineptr);
}
