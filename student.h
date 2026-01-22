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

/*
Input:
   - head: Head of the current student linked list
   - id  : Student id
   - name: Student name

Pre-conditions:
   - id must be alphanumeric and name must only be letters.

Logic:
   - Allocate memory for a new Student
   - Initialize fields
   - Set next pointer to NULL

Output:
   - Returns pointer to newly created Student
 */
Student *addStudent(Student *head, char *id, char *name);

/*
Input:
   - student: Head of the student linked list

 Pre-conditions:
   - Subject marks must already be there

 Logic:
   - For each student:
       - Compute subject totals
       - Compute aggregate total and percentage
       - Assign grade based on score

 Output:
   - NA (Updates in-place)
*/
void updateStudentsGrades(Student *student);

#endif