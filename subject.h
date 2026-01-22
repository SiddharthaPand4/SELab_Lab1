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

/*
 Input:
   - name       : Subject name
   - minorMarks : Marks in minor exam
   - majorMarks : Marks in major exam

 Pre-conditions:
   - Marks must be within defined limits

 Logic:
   - Allocate memory for Subject
   - Compute totalMarks

 Output:
   - Returns pointer to newly created Subject
*/
Subject *addSubject(char *name, int minorMarks, int majorMarks);

#endif