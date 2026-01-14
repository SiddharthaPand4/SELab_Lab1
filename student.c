#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "student.h"

int validateStudentId(char *id)
{
    if (id == NULL || *id == '\0')
        return 0;

    for (int i = 0; id[i] != '\0'; i++)
    {
        if (!isalnum((unsigned char)id[i]))
            return 0;
    }
    return 1;
}

int validateName(char *name)
{
    if (name == NULL || *name == '\0')
        return 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

int checkDuplicate(Student *head, char *id)
{
    Student *current = head;
    while (current != NULL)
    {
        if (strcmp(current->studentId, id) == 0)
            return 0;
        current = current->next;
    }
    return 1;
}

Student *addStudent(Student *studentHead, char *id, char *name)
{
    if (!(validateStudentId(id) && checkDuplicate(studentHead, id)))
    {
        fprintf(stderr, "Student ID is not valid. %s\n", name);
        exit(1);
    }

    if (!validateName(name))
    {
        fprintf(stderr, "Student Name is not valid. %s\n", name);
        exit(1);
    }

    Student *student = (Student *)malloc(sizeof(Student));

    student->studentId = strdup(id);
    student->name = strdup(name);
    student->total = 0;
    student->percentage = 0.0f;
    student->grade = NULL;
    student->next = NULL;

    for (int i = 0; i < NUM_SUBJECTS; i++)
        student->subjects[i] = NULL;

    return student;
}

void updateStudentGrades(Student *student)
{
    if (student == NULL)
        return;

    int totalMarks = 0;

    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        Subject *sub = student->subjects[i];
        if (sub != NULL)
        {
            totalMarks += sub->totalMarks;
        }
    }

    student->total = totalMarks;

    float maxMarks = NUM_SUBJECTS * (MAX_MINOR_MARKS + MAX_MAJOR_MARKS);
    student->percentage = (totalMarks / maxMarks) * 100.0f;

    if (student->percentage >= 90.0)
        student->grade = "O";
    else if (student->percentage >= 85.0)
        student->grade = "A+";
    else if (student->percentage >= 75.0)
        student->grade = "A";
    else if (student->percentage >= 65.0)
        student->grade = "B+";
    else if (student->percentage >= 60.0)
        student->grade = "B";
    else if (student->percentage >= 55.0)
        student->grade = "C";
    else if (student->percentage >= 50.0)
        student->grade = "D";
    else
        student->grade = "F";
}

void updateStudentsGrades(Student *head)
{
    if (head == NULL)
    {
        return;
    }

    Student *curr = head;

    while (curr)
    {
        updateStudentGrades(curr);
        curr = curr->next;
    }
}
