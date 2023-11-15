#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _getline - clone getline
 * @lineptr: pointer to string gotte from stdin
 * @size: pointer to the size of lineptr
 * @file: file pointer to string
 *
 * Return: number of characters read
 */

ssize_t _getline(char **lineptr, size_t *size, FILE *stream)
{
	char buffer[1024];
	int len = 1024;
	ssize_t n = 0;
	int fd, i;

	fd = fileno(stream);
	n = read(fd, buffer, len);
	if (n >= 1024)
		return (n);
	
	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\n')
			break;
	}

	*lineptr = malloc(sizeof(char) * i);
	*lineptr = strcpy(*lineptr, buffer);
	*size = strlen(*lineptr);
	return (i);
}

/**
 * main - get PID
 * @ac: number of arguments passed to main
 * @av: list of input argumnts
 *
 * Return: Always 0.
 */

int main(int ac, char *av[])
{
	(void) ac;
	(void) av;
	char *buffer = NULL;
	size_t size = 0;
	/*ssize_t n;*/

	printf("$ ");

	/*_getline(&buffer, &size, stdin);*/
	printf("$ \n");
	printf("%ld\n", size);
	/*if (n != 0)
		break;*/
	printf("%s", buffer);
	free(buffer);
	return (0);
}
