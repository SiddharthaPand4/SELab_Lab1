#include "parser.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include "subject.h"

Student *parseInputFile(char *filename)
{
    FILE *fp = fopen(filename, "r");

    if (!fp)
    {
        fprintf(stderr, "Could not open the input file: %s.\n", filename);
        exit(1);
    }

    char line[1024];

    Student *head, *tail;
    head = tail = NULL;

    while (fgets(line, sizeof(line), fp))
    {
        char name[128], studentId[16];
        if (sscanf(line, " %15[^,] , %127[^\n]", studentId, name) == 2)
        {
            Student *student = addStudent(head, studentId, name);
            if (head == NULL)
            {
                head = tail = student;
            }
            else
            {
                tail->next = student;
                tail = student;
            }

            int subject_i = 0;

            while (subject_i < NUM_SUBJECTS && fgets(line, sizeof(line), fp))
            {
                char *subjectName = "Sub";
                int minorMarks, majorMarks;
                if (sscanf(line, "%d, %d", &minorMarks, &majorMarks) == 2)
                {
                    Subject *newSubject = addSubject(subjectName, minorMarks, majorMarks);
                    student->subjects[subject_i++] = newSubject;
                }
                else
                {
                    fprintf(stderr, "Could not parse marks line: %s\n", line);
                    exit(1);
                }
            }
        }
        else
        {
            fprintf(stderr, "Could not parse student line: %s\n", line);
            fprintf(stderr, "Could not parse student: %s %s\n", name, studentId);
            exit(1);
        }
    }

    return head;
}