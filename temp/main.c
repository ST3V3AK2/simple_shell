#include "main.h"

/**
 * main - Run shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char **argv, *delim = " ";
	char *var_name = "PATH", *msg = ":) ";
	int status, no_args, n = 0, from_pipe = 0, r;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			_puts(msg);

		argv = get_commands(&n, &no_args, delim);
		if (n == 99)
			exit(0);
		if (n == 1)
			continue;

		argv[0] = check_env(argv[0], var_name);
		if (argv[0] == NULL)
		{
			perror("./shellhere");
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execute(argv);
			exit(0);
		}
		else
		{
			wait(&status);
			free_grid(argv, no_args);
		}
	}
	return (0);
}
