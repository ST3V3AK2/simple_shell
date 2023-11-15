#include "main.h"

/**
 * main - Run shell
 *
 * Return: Always 0.
 */

int main(void)
{
        char **argv;
        char *var_name = "PATH", *msg = ":) ";
        int status, no_args, n = 0, from_pipe = 0;
        pid_t pid;

        while (1)
        {
                if (isatty(STDIN_FILENO) != 0)
                        _puts(msg);
                else
			from_pipe = 1;

                argv = get_commands(&n, &no_args);
                if (n == 1)
                {
                        n = 0;
                        continue;
                }

                if (n == 99)
                {
                        n = 0;
                        exit(0);
                }

                argv[0] = check_env(argv[0], var_name);
                if (argv[0] == NULL)
                {
                        perror("./shell");
                        continue;
                }
                pid = fork();
                if (pid == 0)
                {
                        execute(argv);
                        exit(0);
			sleep(3);
		}
		else
		{
			wait(&status);
			free_grid(argv, no_args);
			if (from_pipe == 1)
				exit(0);
		}
	}
	return(0);
}
