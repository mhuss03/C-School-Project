#ifndef _GRADE_H_
#define _GRADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct GradeNode { 
    int student_id; 
    char subject[50]; 
    int grade; 
    struct GradeNode *next; // Next grade 
} GradeNode;

void add_grade(GradeNode **head, int student_id, const char *subject, int grade);
GradeNode* find_grade(GradeNode *head, int student_id, const char *subject);
// void print_grade_for_student(GradeNode *head, int student_id, const char *subject);

#endif // _GRADE_H_