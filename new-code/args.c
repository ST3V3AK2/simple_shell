#include "main.h"

/**
 * countarg - counts the umber of arguments seperated by a delimeter
 * @str: input string
 * @delim: delimeter character
 *
 * Return: on success, number of arguments
 * on error, 0
 */

int countarg(char *str, char *delim)
{
        int i, j = 0;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (str[i] == *delim)
                        j++;
        }
        return (++j);
}

/**
 * remove_newline - removes the new line character from the end of a string
 * @str: input string
 *
 * Return: pointer to string
 */

char *remove_newline(char *str)
{
        int i;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (str[i] == '\n' && str[i + 1] == '\0')
                        str[i] = '\0';
        }
        return (str);
}

/**
 * getargs - gets argumments from a string
 * @str: input string
 * @delim: delimeter character
 * @n: number of arguments
 *
 * Return: 2-D array of strings
 */

char **getargs(char *str, char *delim, int n)
{
        char **av, *temp;
        int i, j = 0;

        av = malloc(sizeof(char *) * n);
        if (av == NULL)
                return (NULL);

        str = remove_newline(str);
        if (str == NULL)
                return (NULL);
        for (i = 0; i < n; i++, str = NULL)
        {
                temp = strtok(str, delim);
                if ((temp == NULL) && (i < n - 1))
                {
                        continue;
                }
                else
                {
                        if (temp == NULL)
                        {
                                av[j] = NULL;
                                return (av);
                        }
                        av[j] = _strdup(temp);
                        j++;
                }
        }
        av[j] = NULL;
        free(str);
        return (av);
}

/**
 * get_commands - gets input commands from stdin
 * @n: store the type of output
 * @no_args: stroes the number of arguments in the 2-D array
 *
 * Return: on success, 2-D grid of inpt commands
 * on error, NULL
 */

char **get_commands(int *n, int *no_args)
{
        char **argv, *quit = "exit";
        char *buffer = NULL, *delim = " ";
        ssize_t r;
        size_t size = 0;

        r = getline(&buffer, &size, stdin);
        if (r < 0)
        {
                _puts("\n");
                free(buffer);
                exit(0);
        }

        if (buffer[0] == '\n')
        {
                *n = 1;
                return (NULL);
        }

        *no_args = countarg(buffer, " ");
        if (*no_args < 1)
        {
                free(buffer);
                return (NULL);
        }

        argv = getargs(buffer, delim, *no_args);
        if (argv == NULL)
        {
                free(buffer);
                return (NULL);
        }

        r = _strdcmp(argv[0], quit, '\0');
        if (r == 1)
		*n = 99;

	return (argv);
}
