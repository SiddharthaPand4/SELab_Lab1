#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_MINOR_MARKS 40
#define MAX_MAJOR_MARKS 60

typedef struct Subject
{
    char *name;
    int minorMarks;
    int majorMarks;
    int totalMarks;
} Subject;

Subject *addSubject(char *name, int minorMarks, int majorMarks);

#endif