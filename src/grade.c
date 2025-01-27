#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grade.h"

void add_grade(GradeNode **head, int student_id, const char *subject, int grade) {
    GradeNode *new_grade = (GradeNode *)malloc(sizeof(GradeNode));

    new_grade->student_id = student_id;
    strcpy(new_grade->subject, subject);
    new_grade->grade = grade;
    new_grade->next = NULL;

    if (*head == NULL) {
        *head = new_grade;
        return;
    }

    GradeNode *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_grade;
}

GradeNode* find_grade(GradeNode *head, int student_id, const char *subject) {
    GradeNode *current = head;
    while (current!= NULL) {
        if (current->student_id == student_id && strcmp(current->subject, subject) == 0) {
            return current; // Found the grade
        }
        current = current->next;
    }
    return NULL; // Grade not found
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