#include "main.h"

/**
 * _putchar - Prints characters
 * @c: characte
 *
 * Return: on success 1
 * on error -1
 */

int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: input string
 *
 * Return: void
 */

void _puts(char *str)
{
        int i;

        for (i = 0; str[i] != '\0'; i++)
                _putchar(str[i]);
}
