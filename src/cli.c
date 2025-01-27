#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("7. Exit\n");
    printf("--------------------------------\n");
    printf("Enter your choice: ");
}

int is_valid_int()
{
    int num;
    while (1)
    {
        if (scanf("%d", &num) != 1)
        {
            // clears input buffer. Otherwise, program will infinite loop
            while (getchar() != '\n')
                ;
            printf("Invalid choice. Please try again.\n");
        }
        else
        {
            return num;
        }
    }
}

int is_valid_name()
{

    return 1;
}
