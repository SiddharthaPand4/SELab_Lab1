#ifndef TABULAR_REPORT_H
#define TABULAR_REPORT_H
#include "student.h"

typedef struct TabularReport
{
    float classAveragePct;
    float highestPct;
    float lowestPct;
    int gradeO;
    int gradeAPlus;
    int gradeA;
    int gradeB;
    int gradeBPlus;
    int gradeC;
    int gradeD;
    int gradeF;

} TabularReport;

/*
 Input:
   - head     : Head of the student linked list
   - filename : Output file path

 Pre-conditions:
   - Student grades and percentages must be computed

 Logic:
   - Traverse student list
   - Compute class statistics
   - Count students in each grade
   - Write tabular report and student-wise details to file

 Output:
   - Generates a formatted class report in the output file
*/
void tabulateClassResults(Student *head, char *filename);

#endif
