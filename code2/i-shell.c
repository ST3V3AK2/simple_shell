#include "main.h"

/**
 * i_shell -runs shell interactive mode
 *
 * Return: void
 */

void i_shell(void)
{
	char **argv1, **temp, *q = "exit", *d = " ";
	char *var_name = "PATH", *buffer = "", *temp_buf = NULL, *delim = "\n";
	size_t size = 0, r;
	int no_args, n = 0, a = 0, status, i;
	pid_t pid;

	no_args = countarg(buffer, "\n");
	printf("%d\n", no_args);
	if (no_args < 1)
	{
		free(buffer);
		exit(0);
	}

	/*
	while (n > 0)
	{
		n = getline(&temp_buf, &size, stdin);

		argv1 = getargs(buffer, delim, no_args);
		if (argv1 == NULL)
		{
			free(buffer);
			exit(0);
		}

		r = _strdcmp(argv1[0], q, '\0');
		if (r == 1)
			exit(0);

		for (i = 0; i < no_args; i++)
		{
			a = countarg(argv1[i], " ");
			printf("argv1: %s\n", argv1[i]);
			if (a < 1)
				break;

			temp = getargs(argv1[i], d, a);
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
				free_grid(argv1, no_args);
			}
		}
	}
	*/
	exit(0);
}
