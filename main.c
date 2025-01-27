#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "include/student.h"
#include "include/teacher.h"
#include "include/cli.h"

int main()
{
    StudentNode *student_list = NULL;
    TeacherNode *teacher_list = NULL;

    int user_choice;
    int running = 1;
    // char running = 1;

    while (running)
    {
        display_menu();
        // scanf("%d", &user_choice);
        user_choice = get_valid_int("Enter your choice: ");

        switch (user_choice)
        {
        case 1:
        { // Add student
            int id;
            char name[50];
            char subjects[200]; // Buffer to hold comma-separated subjects
            // scanf("%d", &id);
            id = get_valid_int("Enter Student ID: ");

            get_valid_string("Enter Student Name: ", name, sizeof(name));

            add_student(&student_list, id, name); // Add the student
            StudentNode *new_student = find_student_by_id(student_list, id);
            printf("Student added successfully.\n");

            get_valid_subject_string("Enter the subjects they study (separated by commas): ", subjects, sizeof(subjects));

            // Old
            // printf("Enter the subjects they study (separated by commas): ");
            // scanf(" %[^\n]", subjects); // Read the entire line of subjects

            // Parse the comma-separated list of subjects
            char *token = strtok(subjects, ",");
            while (token != NULL)
            {
                // Trim leading and trailing spaces
                while (*token == ' ')
                    token++;
                char *end = token + strlen(token) - 1;
                while (end > token && *end == ' ')
                    end--;
                *(end + 1) = '\0';

                // Add the subject to the student
                add_subject_to_student(new_student, token);

                // Move to the next token
                token = strtok(NULL, ",");
            }

            printf("Subjects added successfully.\n");
            break;
        }
        case 2:
        {
            // Add teacher
            int id;
            char name[50];
            char subject[50];
            // old
            // printf("Enter Teacher ID: ");
            //  scanf("%d", &id);
            //  printf("\nEnter Teacher Name: ");
            //  scanf(" %[^\n]", name); // Read a string with spaces
            //  printf("\nEnter Teacher Subject: ");
            //  scanf(" %[^\n]", subject); // Read a string with spaces
            //  printf("\n");
            id = get_valid_int("Enter Teacher ID: ");

            get_valid_string("Enter Teacher Name: ", name, sizeof(name));
            get_valid_string("Enter Teacher Subject: ", subject, sizeof(subject));

            add_teacher(&teacher_list, id, name, subject);
            printf("Teacher added successfully.\n");
            break;
        }
        case 3:
            // Print students
            print_students(student_list);
            break;
        case 4:
            // Print teachers
            print_teachers(teacher_list);
            break;
        case 5:
        {
            // Add subject to student
            int student_id;
            char subject_name[50];

            // printf("Enter Student ID: ");
            // scanf("%d", &student_id);
            student_id = get_valid_int("Enter Student ID: ");

            // printf("\nEnter Subject Name: ");
            // scanf(" %[^\n]", subject_name); // Read a string with spaces
            get_valid_string("Enter Subject Name: ", subject_name, sizeof(subject_name));

            StudentNode *student = find_student_by_id(student_list, student_id);
            if (student != NULL)
            {
                add_subject_to_student(student, subject_name);
                printf("Subject added successfully.\n");
            }
            else
            {
                printf("Student not found.\n");
            }
            break;
        }
        case 6:
        {
            // Find students by Subject
            char subject_name[50];

            // printf("Enter Subject Name: ");
            // scanf(" %[^\n]", subject_name); // Read a string with spaces
            get_valid_string("Enter Subject Name: ", subject_name, sizeof(subject_name));

            if (student_list == NULL)
            {
                printf("No students available.\n");
                break;
            }

            students_by_subject(student_list, subject_name);
            break;
        }
        case 7:
            // Exit program
            printf("Goodbye!\n");
            running = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    // // Initialize empty student and teacher lists
    // StudentNode *student_list = NULL;
    // TeacherNode *teacher_list = NULL;

    // // Add students
    // add_student(&student_list, 1, "Alice");
    // add_student(&student_list, 2, "Bob");
    // add_student(&student_list, 3, "Charlie");

    // add_teacher(&teacher_list, 1, "Mr Gilbert", "English");
    // add_teacher(&teacher_list, 2, "Mr Jones", "Science");
    // add_teacher(&teacher_list, 3, "Mrs Smith", "Maths");

    // // Print students and teachers
    // print_students(student_list);
    // print_teachers(teacher_list);

    // StudentNode *student = find_student_by_id(student_list, 1);

    // add_subject_to_student(student, "Maths");
    // printf("\n");

    // StudentNode *student2 = find_student_by_name(student_list, "Bob");

    // add_subject_to_student(student2, "Science");
    // printf("\n");

    // print_students(student_list);

    return 0;
}