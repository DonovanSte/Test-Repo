#ifndef MAIN_H
#define MAIN_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*FUNCTION PROTOTYPES*/
void type_prompt();
void read_command(char cmd[], char *par[]);

#endif
