#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu();
int get_valid_int(char *prompt);
void get_valid_string(char *prompt, char *buffer, int max_length);
void get_valid_subject_string(char *prompt, char *buffer, int max_length);

#endif // _CLI_H_