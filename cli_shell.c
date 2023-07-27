#include "shell.h"

/**
 * main - Main shell loop functions
 * @ac: Counting of argumnents
 * @av: Arguments given
 * @env: Environment - ineteractive or non-interactive
 * Return: _exit = 0.
 */

int main(int ac, char **av, char **env)
{
	int pathID = 0, status = 0, is_path = 0;
	char *line = NULL, **commands = NULL; /**tokenized commands*/
	(void)ac;
	while (1) /* MAIN SHELL - loops until exit */
	{
		errno = 0;
		line = _getline_command(); /** reads user input*/
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			pathID++;
			commands = tokenize(line); /** tokenizes or parse user input*/
			if (!commands)
				free(line);
			if (!_strcmp(commands[0], "env"))
				_getenv(env);
			else
			{
				is_path = _values_path(&commands[0], env); /** tokenizes PATH inputted*/
				status = _fork_fun(commands, av, env, line, pathID, is_path);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands); /*free up memory when not in use*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1); /** outputs to standard output*/
			exit(status);
		}
		free(line);
	}
	return (status);
}
