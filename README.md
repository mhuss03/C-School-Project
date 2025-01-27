# skates-schools-management-project

## **Brief**
This project is a command-line interface (CLI) program written in C, designed to manage a school system. It allows for managing students, teachers, subjects, and grades with additional querying capabilities.

### **Core Features**
- Add students and the subjects they study.
- Add teachers and the subject they teach (one subject per teacher).
- Assign grades to students per subject.
- Find students studying a specified subject.
- Find the teacher of a specified subject.
- Find the grades a specified student has achieved in a specified subject.

### **Bonus Features**
- Find which teachers teach a specified student.
- Find which students are taught by a specified teacher.
- Load student and teacher data from files at program startup.

---

### Build and Run
Build the Program:

```bash
make
```

Run the Program:

```bash
./program
```
Clean the Project:

```bash
make clean
```

## **Project Structure**

### **Header Files**
| File              | Description                                           |
|-------------------|-------------------------------------------------------|
| `student.h`       | Contains `StudentNode` struct and related functions.  |
| `teacher.h`       | Contains `TeacherNode` struct and related functions.  |
| `grade.h`         | Contains `GradeNode` struct and related functions.    |
| `cli.h`           | Functions for CLI-based user interaction.             |
| `file_handler.h`  | [Bonus] File loading and saving functions.            |

### **Source Files**
| File              | Description                                           |
|-------------------|-------------------------------------------------------|
| `main.c`          | Program entry point. Handles main menu and user input.|
| `student.c`       | Implementation of student-related functions.          |
| `teacher.c`       | Implementation of teacher-related functions.          |
| `grade.c`         | Implementation of grade-related functions.            |
| `cli.c`           | Implementation of CLI navigation and input validation.|
| `file_handler.c`  | [Bonus] Implementation of file I/O for data persistence.|

---

## **File Structure**

```
schools-management-project/
├── Makefile               # For building the project
├── main.c                 # Entry point for the program
├── include/               # Header files (data structures and function declarations)
│   ├── student.h          # Student-related structures and functions
│   ├── teacher.h          # Teacher-related structures and functions
│   ├── subject.h          # Subject-related structures and functions
│   ├── grade.h            # Grade-related structures and functions
│   ├── cli.h              # Command-line interface function declarations
│   ├── file_handler.h     # [Bonus] File handling function declarations
├── src/                   # Source files (implementation of functions)
│   ├── student.c          # Implementation of student functions
│   ├── teacher.c          # Implementation of teacher functions
│   ├── subject.c          # Implementation of subject functions
│   ├── grade.c            # Implementation of grade functions
│   ├── cli.c              # Implementation of CLI functions
│   ├── file_handler.c     # [Bonus] Implementation of file handling functions
├── data/                  # [Bonus] Folder for input/output data files
│   ├── students.txt       # [Bonus] Predefined or saved student data
│   ├── teachers.txt       # [Bonus] Predefined or saved teacher data
│   ├── grades.txt         # [Bonus] Predefined or saved grade data
└── README.md              # Documentation for the project
```

## **Makefile**
```makefile
CC = gcc
CFLAGS = -Wall -g
SOURCES = main.c src/student.c src/teacher.c src/grade.c src/cli.c
HEADERS = include/student.h include/teacher.h include/grade.h include/cli.h

all: program

program: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o program

clean:
	rm -f program
```

## Sprint Plan

### Sprint 1: Core Structures and Basic Operations
- Goal: Set up foundational data structures and basic CRUD operations.

- Create the file structure and write a Makefile.
- Define data structures for:
- StudentNode (linked list of students).
- TeacherNode (linked list of teachers).
- Implement basic functions:
- add_student, print_students.
- add_teacher, print_teachers.
- Test program flow in main.c.

### Sprint 2: Relationships and Advanced Features
- Goal: Implement subjects, grades, and their relationships.

- Add GradeNode for grade management.
- Implement functions:
- add_grade, print_grades_for_student.
- Query students by subject.
- Query teachers by subject.
- Test relationships:
- Assign grades to students for specific subjects.
- Assign teachers to subjects.

### Sprint 3: CLI and Queries
- Goal: Build the menu-driven CLI to integrate features.

- Design a menu with options for each feature:
    - Add Student.
    - Add Teacher.
    - Assign Grade.
    - Find Students by Subject.
    - Find Teacher by Subject.
    - Find Grades for Student.
- Connect menu options to core functions.
- Test end-to-end functionality.

### End Goals
- A fully functional CLI program where users can add, query, and manage students, teachers, grades, and subjects interactively.
- Bonus: Persistent storage of data via files.

