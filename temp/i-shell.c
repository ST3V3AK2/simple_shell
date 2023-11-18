#include "main.h"

/**
 * i_shell -runs shell interactive mode
 *
 * Return: void
 */

void i_shell(void)
{
	char **temp, *q = "exit", *d = " ";
	char *var_name = "PATH", *buffer = NULL;
	size_t size = 0, r;
	int no_args, n = 0, a = 0, status, i;
	pid_t pid;

	while (1)
	{
		n = getline(&buffer, &size, stdin);
		if (n == -1)
			break;
		/*
		argv1 = getargs(buffer, delim, no_args);
		if (argv1 == NULL)
		{
			free(buffer);
			exit(0);
		}

		r = _strdcmp(argv1[0], q, '\0');
		if (r == 1)
			exit(0);
		*/

		a = countarg(buffer, d);
		if (a < 1)
			break;

		temp = getargs(buffer, d, a);
		if (temp == NULL)
			continue;

		temp[0] = check_env(temp[0], var_name);
		if (temp[0] == NULL)
		{
			perror("./shell");
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execute(temp);
			exit(0);
			sleep(3);
		}
		else
		{
			wait(&status);
			free_grid(temp, no_args);
		}
	}
	exit(0);
}
