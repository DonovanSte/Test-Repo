#ifndef MAIN_H
#define MAIN_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/*FUNCTION PROTOTYPES*/
void execmd(char **argv);
char *get_location(char *command);
void print_prompt(char *prompt);
int execute_command(char **argv);
int tokenize_line(char *lineptr, char ***argv);
char *read_line(size_t *n);
void process_input(char *prompt);
void process_command(char *lineptr);

#endif
