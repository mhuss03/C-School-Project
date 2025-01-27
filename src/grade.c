#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grade.h"

void add_grade(GradeNode **head, int student_id, const char *subject, int grade)
{
    GradeNode *existing_grade = find_grade(*head, student_id, subject);
    if (existing_grade != NULL)
    {
        printf("Grade already exists for Student ID %d in subject '%s'.\n", student_id, subject);
        return;
    }

    GradeNode *new_grade = (GradeNode *)malloc(sizeof(GradeNode));

    new_grade->student_id = student_id;
    strcpy(new_grade->subject, subject);
    new_grade->grade = grade;
    new_grade->next = NULL;

    if (*head == NULL)
    {
        *head = new_grade;
        return;
    }

    GradeNode *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_grade;
    printf("Grade added successfully for Student ID %d in subject '%s'.\n", student_id, subject);
}

GradeNode *find_grade(GradeNode *head, int student_id, const char *subject)
{
    GradeNode *current = head;
    while (current != NULL)
    {
        if (current->student_id == student_id && strcmp(current->subject, subject) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// void print_grade_for_student(GradeNode *head, int student_id, const char *subject) {
//     GradeNode *current = head;
//     printf("\nGrades for subject '%s':\n", subject);
//     while (current!= NULL) {
//         if (strcmp(current->subject, subject) == 0) {
//             printf("Student ID: %d\tGrade: %d\n", current->student_id, current->grade);
//         }
//         current = current->next;
//     }
//     printf("\n"); // Print a newline to separate the grades for different subjects
// }
void print_grade_for_student(GradeNode *head, int student_id, const char *subject)
{
    GradeNode *current = head;
    int found = 0;

    printf("Grades for Student ID %d in Subject '%s':\n", student_id, subject);
    printf("===========================================\n");
    while (current != NULL)
    {
        if (current->student_id == student_id && strcmp(current->subject, subject) == 0)
        {
            printf("Subject: %s, Grade: %d\n", current->subject, current->grade);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("No grades found for Student ID %d in subject '%s'.\n", student_id, subject);
    }
    printf("===========================================\n");
}