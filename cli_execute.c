#include "shell.h"

int cli_cd(char **args);
int cli_help(char **args);
int cli_exit(char **args);
int cli_ctrld(char **args);

/*
 * List of builtin commands, and their corresponding functions.
 */
char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&cli_cd, &cli_help, &cli_exit, &cli_ctrld};

/**
 * cli_num_builtins - size of builtin functions
 * Return: size (buffer)
 */

int cli_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/* Implementation of Builtin functions. */

/**
 * cli_cd - builtin func to change direectories
 * @args: List of tokenized args.  args[0] is: "cd".  args[1] is: directory.
 * Return: 1 on success
 */

int cli_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cli: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * cli_help - prints the help page for the shell
 * @args: List of args.
 * Return: Always returns 1.
 */

int cli_help(char **args)
{
	int x;

	printf("Oscar Bedat and Andres Henderson\n");
	printf("If you need help, call 1-800-help\n");
	(void)args;
	for (x = 0; x < cli_num_builtins(); x++)
	{
		printf("  %s\n", builtin_str[x]);
	}

	return (1);
}

/**
 * cli_exit - builtin to exit/quit the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution and 1 oer -1 error command.
 */

int cli_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * cli_ctrld - builtin to handle "^D" call (control + D).
 * @args: List of args.
 * Return: Always returns 0, to terminate execution. 1 to continue (error)
 */

int cli_ctrld(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *_fork_fun - tool that creates a fork.
 *@arg: Command and values path.
 *@av: contains name of our program.
 *@env: Environment (interactive or non-interactive)
 *@lineptr: Command line for the user.
 *@np: Process ID.
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{

	pid_t child;
	int status, x = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (x = 0; x < cli_num_builtins(); x++)
	{
		if (_strcmp(arg[0], builtin_str[x]) == 0)
			return (builtin_func[x](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
