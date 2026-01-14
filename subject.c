#include "subject.h"
#include <stdio.h>
#include <stdlib.h>

int validateMarks(int marks, int low, int high)
{
    return marks >= low && marks <= high;
}

Subject *addSubject(char *name, int minorMarks, int majorMarks)
{
    if (validateMarks(minorMarks, 0, MAX_MINOR_MARKS) &&
        validateMarks(minorMarks, 0, MAX_MAJOR_MARKS))
    {
        Subject *subject = (Subject *)malloc(sizeof(sizeof(Subject)));
        subject->name = name;
        subject->minorMarks = minorMarks;
        subject->majorMarks = majorMarks;
        subject->totalMarks = minorMarks + majorMarks;
        return subject;
    }
    else
    {
        fprintf(stderr, "Subject marks are not valid. %s %d %d\n", name, minorMarks, majorMarks);
        exit(1);
    }
    return NULL;
}