#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cli.h"

void display_menu()
{
    printf("\n--- School Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Add Teacher\n");
    printf("3. Print Students\n");
    printf("4. Print Teachers\n");
    printf("5. Add Subject to Student\n");
    printf("6. Find Students by Subject\n");
    printf("7. Add Grade to Student\n");
    printf("8. View Grades for a Student\n");
    printf("9. Find Teacher by Subject\n");
    printf("10. Exit\n");
    printf("--------------------------------\n");
}

void clear_input_buffer()
{
    while (getchar() != '\n')
        ;
}

int get_valid_int(char *prompt)
{
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input. Please enter a valid integer.\n");
            clear_input_buffer();
        }
        else
        {
            clear_input_buffer();
            return value;
        }
    }
}

void get_valid_string(char *prompt, char *buffer, int max_length)
{
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, max_length, stdin) == NULL)
        {
            printf("Error reading input. Please try again.\n");
        }
        else
        {
            size_t length = strlen(buffer);
            if (length > 0 && buffer[length - 1] == '\n')
            {
                buffer[length - 1] = '\0';
            }

            if (strlen(buffer) == 0)
            {
                printf("Input cannot be empty. Please try again.\n");
            }
            else
            {
                return;
            }
        }
    }
}

void get_valid_subject_string(char *prompt, char *buffer, int max_length)
{
    while (1)
    {
        get_valid_string(prompt, buffer, max_length);

        int valid = 1;
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (!isalpha(buffer[i]) && buffer[i] != ' ' && buffer[i] != ',')
            {
                valid = 0;
                break;
            }
        }

        if (valid)
        {
            return;
        }
        else
        {
            printf("Invalid characters in input. Please enter only letters, spaces, and commas.\n");
        }
    }
}