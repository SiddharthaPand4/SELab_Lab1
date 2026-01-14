#ifndef STUDENT_H
#define STUDENT_H

#include "subject.h"

#define NUM_SUBJECTS 5

typedef struct Student
{
    char *studentId;
    char *name;
    Subject *subjects[NUM_SUBJECTS];
    int total;
    char *grade;
    float percentage;
    struct Student *next;
} Student;

Student *addStudent(Student *head, char *id, char *name);
// void addMinorMarks(int *minorMarks);
// void addMajorMarks(int *majorMarks);
void updateStudentsGrades(Student *student);

#endif