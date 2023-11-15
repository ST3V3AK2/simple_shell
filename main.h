#ifndef SHELL_P
#define SHELL_P

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

/* print.c */
int _putchar(char c);
void _puts(char *str);

/* strings.c */
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strdcmp(char *str1, char *str2, char delim);

/* args.c */
int countarg(char *str, char *delim);
char *remove_newline(char *str);
char **getargs(char *str, char *delim, int n);
char **get_commands(int *n, int *no_args);

/* execute.c */
void print_envir(void);
char *get_env_var(char *str);
char *check_env(char *str, char *var_name);
void execute(char **argv);

/* frees.c */
void free_grid(char **grid, int height);

/* i-shell.c */
/* void i_shell(void); */
#endif
