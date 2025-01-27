#ifndef _TEACHER_H_
#define _TEACHER_H_

typedef struct TeacherNode { 
    int id; 
    char name[50]; 
    char subject[50]; // The subject they teach struct 
    struct TeacherNode *next; // Next teacher 
} TeacherNode;

void add_teacher(TeacherNode **head, int id, const char *name, const char *subject); 
TeacherNode* find_teacher_by_id(TeacherNode *head, int id);
TeacherNode* find_teacher_by_name(TeacherNode *head, const char *name);
void print_teachers(TeacherNode *head);
void print_teacher_by_subject(TeacherNode *head, char *subject);



#endif // _TEACHER_H_