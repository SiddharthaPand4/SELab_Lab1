#ifndef STUDENT_H
#define STUDENT_H

#define NUM_SUBJECTS 5

typedef struct Student {
    char *studentId;
    char *name;
    Subject subjects[NUM_SUBJECTS];
    int total;
    char *grade;
    float cgpa;
    Student *next;
} Student;

Student *addStudent(char *id, char *name);
void addMinorMarks(int *minorMarks);
void addMajorMarks(int *majorMarks);
void updateStudentsGrades(Student *student);
void tabulateClassResults(Student *, char *filename);

#endif