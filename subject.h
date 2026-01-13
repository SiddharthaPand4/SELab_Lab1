#ifndef SUBJECT_H
#define SUBJECT_H

typedef struct Subject {
    int id;
    int minorMarks;
    int majorMarks;
} Subject;

Subject *addSubject(int minorMarks, int majorMarks);

#endif