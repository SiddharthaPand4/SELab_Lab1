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

void tabulateClassResults(Student *head, char *filename);

#endif
