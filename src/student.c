#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#define MAX_SUBJECTS 10

void add_student(StudentNode **head, int id, const char *name)
{
    StudentNode *new_student = (StudentNode *)malloc(sizeof(StudentNode));

    new_student->id = id;
    strcpy(new_student->name, name);
    new_student->num_subjects = 0;
    new_student->next = NULL;

    if (!new_student)
    {
        printf("Error: Out of memory\n");
        return;
    }

    if (*head == NULL)
    {
        *head = new_student;
        return;
    }

    StudentNode *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_student;
}

// Look at this
StudentNode *find_student_by_id(StudentNode *head, int id)
{
    StudentNode *current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current; // Found the student
        }
        current = current->next;
    }
    return NULL; // Student not found
}

StudentNode *find_student_by_name(StudentNode *head, const char *name)
{
    StudentNode *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current; // Found the student
        }
        current = current->next;
    }
    return NULL; // Student not found
}

void print_students(StudentNode *head)
{
    StudentNode *current = head;
    printf("\n");
    printf("Students:\n");
    printf("================================================\n");
    while (current != NULL)
    {
        printf("ID: %d\nName: %s\n", current->id, current->name);
        printf("Subjects: ");
        for (int i = 0; i < current->num_subjects; i++)
        {
            printf("%s ", current->subjects[i]);
        }
        printf("\n");
        printf("================================================\n");
        current = current->next;
    }
    printf("NULL\n"); // indicate the end of the list
    printf("\n");
}

void add_subject_to_student(StudentNode *student, const char *subject_name)
{
    if (student->num_subjects == MAX_SUBJECTS)
    {
        printf("Error: Student already has maximum number of subjects\n");
        return;
    }

    strcpy(student->subjects[student->num_subjects], subject_name);
    student->num_subjects++;

    printf("Subject added to %s: %s\n", student->name, subject_name);
}

// NEEDS DEBUGGING
// void students_by_subject(StudentNode *head, const char *subject)
// {
//     StudentNode *current = head;
//     int found = 0;
//     printf("\n");
//     printf("Students studying %s:\n", subject);
//     printf("================================================\n");
//     for (int i = 0; i < current->num_subjects; i++)
//     {
//         if (strcmp(current->subjects[i], subject) == 0)
//         {
//             printf("ID: %d\nName: %s\n", current->id, current->name);
//             found++;
//         }
//         current = current->next;
//     }
//     if (found == 0)
//     {
//         printf("No students found studying %s.\n", subject);
//     }
//     printf("================================================\n");
//     printf("\n");
// }
void students_by_subject(StudentNode *head, const char *subject)
{
    if (head == NULL)
    {
        printf("\nNo students available.\n");
        return;
    }

    StudentNode *current = head;
    int found = 0;

    printf("\n");
    printf("Students studying %s:\n", subject);
    printf("================================================\n");

    while (current != NULL)
    {
        for (int i = 0; i < current->num_subjects; i++)
        {
            if (strcmp(current->subjects[i], subject) == 0)
            {
                printf("ID: %d\nName: %s\n", current->id, current->name);
                found++;
                break;
            }
        }
        current = current->next;
    }

    if (found == 0)
    {
        printf("No students found studying %s.\n", subject);
    }

    printf("================================================\n");
    printf("\n");
}