#include "main.h"

/**
 * execute - runs programs and commands from stdin
 * @argv: pointe to 2-D array of strings
 *
 * Return: void
 */

void execute(char **argv)
{
        int n;

        if (argv == NULL || argv[0] == NULL)
                return;

        n = execve(argv[0], argv, environ);
        if (n == 1)
        {
                perror("./shellhere");
                exit(100);
        }
}

/**
 * get_env_var - gets an enviromental variable from environ
 * @str: name of environment variable
 *
 * Return: on success, pointer to the a copy of the variable
 * on error, NULL
 */

char *get_env_var(char *str)
{
        int i, r;
        char *var, *d = "=";

        for (i = 0; environ[i] != NULL; i++)
        {
                r = _strdcmp(environ[i], str, *d);
                if (r == 1)
                        break;

                if (environ[i + 1] == NULL)
                        return (NULL);
        }

	var = _strdup(environ[i]);
	return (var);
}

/**
 * check_env - looks for the presence of a file in PATH
 * @str: name of executable
 * @var_name: name of enviromental variable
 *
 * Return: on success, absolute path for executable
 * on error, NULL
 */

char *check_env(char *str, char *var_name)
{
        struct stat st;
        char **path, *c = "/";
        char *temp, *delim = ":", *d = "=:";
        int j, n;

        if (str == NULL)
                return (NULL);

        if (stat(str, &st) == 0)
                return (str);

        temp = get_env_var(var_name);
        if (temp == NULL)
                return (NULL);

        n = countarg(temp, delim);
        path = getargs(temp, d, n + 1);
        for (j = 1; j < n + 1 && path[j] != NULL; j++)
        {
                path[j] = _strcat(path[j], c);
                path[j] = _strcat(path[j], str);
                if (path[j] == NULL)
                        return (NULL);

                if (stat(path[j], &st) == 0)
                        return (path[j]);
        }
        return (NULL);
}

/**
 * print_envir - prints all the enviromental variables
 *
 * Return: void.
 */

void print_envir(void)
{
        int i;

        for (i = 0; environ[i] != NULL; i++)
                _puts(environ[i]);
}
