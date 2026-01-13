#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char *studentId;
    char *name;
    int minorMarks[5];
    int majorMarks[5];
    int total;
    char *grade;
    float cgpa;
} Student;

Student *initializeStudent(char *id, char *name, int marks);
void updateStudentsGrades(Student *student);
void tabulateClassResults(Student *student);

#endif