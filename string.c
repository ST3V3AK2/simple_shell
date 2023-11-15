#include "main.h"

/**
 * _strlen - computes the length of a string
 * @str: poinnter to string
 *
 * Return: on success, number of charcters in the string
 * on error, 0.
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		continue;

	return (i);
}

/**
 * _strdup - creates a duplicate of input string
 * @str: input string
 *
 * Return: on success, pointer to duplicate string
 * on error, NULL
 */

char *_strdup(char *str)
{
	char *dup;
	int i, n;

	if (str == NULL)
		return (NULL);

	n = _strlen(str);
	dup = malloc(n + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		dup[i] = str[i];

	dup[n] = '\0';
	return (dup);
}

/**
 * _strcat - concatenates two strings and returns a pointer to new string
 * @dest: first string
 * @src: second string
 *
 * Return: on success, pointer to dest
 * on error, NULL
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	if (src == NULL)
	{
		if (dest == NULL)
			return (NULL);
		return (dest);
	}
	for (i = 0; dest[i] != '\0'; i++)
		continue;

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strdcmp - compares two strings till the first occurence of a delimiter
 * @str1: first string
 * @str2: second string
 * @delim: delimeter
 *
 * Return: on success, 1
 * on error, -1
 */

int _strdcmp(char *str1, char *str2, char delim)
{
	int i;

	if (str1 == NULL && str2 == NULL)
		return (1);

	for (i = 0; str1[i] != delim && str2[i] != delim; i++)
	{
		if (str1[i] != str2[i])
			return (-1);

		if (str1[i] == '\0' || str2[i] == '\0')
			return (-1);
	}
	return (1);
}
