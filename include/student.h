#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct StudentNode { 
    int id; 
    char name[50]; 
    char subjects[10][50]; // Fixed-size array for subject names 
    int num_subjects; // Number of subjects the student is enrolled in
    struct StudentNode *next; // Next student 
} StudentNode;


void add_student(StudentNode **head, int id, const char *name); 
StudentNode* find_student_by_id(StudentNode *head, int id);
StudentNode* find_student_by_name(StudentNode *head, const char *name); 
void add_subject_to_student(StudentNode *student, const char *subject_name); 
void print_students(StudentNode *head);
void students_by_subject(StudentNode *head, const char *subject);



#endif // _STUDENT_H_
