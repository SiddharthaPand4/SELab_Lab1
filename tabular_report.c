#include "tabular_report.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeClassAverage(TabularReport *report, Student *head)
{
    if (head == NULL)
        return;

    float sum = 0.0f;
    int count = 0;

    Student *curr = head;
    while (curr != NULL)
    {
        sum += curr->percentage;
        count++;
        curr = curr->next;
    }

    report->classAveragePct = (count == 0) ? 0.0f : (sum / count);
}

void computeHighestPercentage(TabularReport *report, Student *head)
{
    if (head == NULL)
        return;

    float max = head->percentage;

    Student *curr = head;
    curr = curr->next;

    while (curr != NULL)
    {
        if (curr->percentage > max)
            max = curr->percentage;
        curr = curr->next;
    }

    report->highestPct = max;
}

void computeLowestPercentage(TabularReport *report, Student *head)
{
    if (head == NULL)
        return;

    float min = head->percentage;
    Student *curr = head;

    curr = curr->next;

    while (curr != NULL)
    {
        if (curr->percentage < min)
            min = curr->percentage;
        curr = curr->next;
    }

    report->lowestPct = min;
}

void computeGradeDistribution(TabularReport *report, Student *head)
{
    report->gradeO = 0;
    report->gradeAPlus = 0;
    report->gradeA = 0;
    report->gradeBPlus = 0;
    report->gradeB = 0;
    report->gradeC = 0;
    report->gradeD = 0;
    report->gradeF = 0;

    Student *curr = head;

    while (curr != NULL)
    {
        if (curr->grade == NULL)
        {
            fprintf(stderr, "%s %d\n", curr->name, curr->total);
            curr = curr->next;
            continue;
        }
        if (strcmp(curr->grade, "O") == 0)
            report->gradeO++;
        else if (strcmp(curr->grade, "A+") == 0)
            report->gradeAPlus++;
        else if (strcmp(curr->grade, "A") == 0)
            report->gradeA++;
        else if (strcmp(curr->grade, "B+") == 0)
            report->gradeBPlus++;
        else if (strcmp(curr->grade, "B") == 0)
            report->gradeB++;
        else if (strcmp(curr->grade, "C") == 0)
            report->gradeC++;
        else if (strcmp(curr->grade, "D") == 0)
            report->gradeD++;
        else if (strcmp(curr->grade, "F") == 0)
            report->gradeF++;

        curr = curr->next;
    }
}

void generateClassReport(Student *head, TabularReport *tabularReport)
{
    if (head == NULL)
    {
        fprintf(stderr, "No students to make report of.\n");
        return;
    }
    fprintf(stderr, "Generating CLass Avgs\n");
    computeClassAverage(tabularReport, head);
    fprintf(stderr, "Generating CLass High\n");
    computeHighestPercentage(tabularReport, head);
    fprintf(stderr, "Generating CLass Low\n");
    computeLowestPercentage(tabularReport, head);
    fprintf(stderr, "Generating CLass Grade Counts\n");
    computeGradeDistribution(tabularReport, head);
}

void writeClassReportToFile(TabularReport *r, FILE *fp)
{
    fprintf(fp, "========== CLASS PERFORMANCE REPORT ==========\n");
    fprintf(fp, "Class Average %%        : %.2f\n", r->classAveragePct);
    fprintf(fp, "Highest Percentage    : %.2f\n", r->highestPct);
    fprintf(fp, "Lowest Percentage     : %.2f\n", r->lowestPct);

    fprintf(fp, "\nGrade Distribution\n");
    fprintf(fp, "---------------------------------------------\n");
    fprintf(fp, "O  : %d\n", r->gradeO);
    fprintf(fp, "A+ : %d\n", r->gradeAPlus);
    fprintf(fp, "A  : %d\n", r->gradeA);
    fprintf(fp, "B+  : %d\n", r->gradeBPlus);
    fprintf(fp, "B  : %d\n", r->gradeB);
    fprintf(fp, "C  : %d\n", r->gradeC);
    fprintf(fp, "D  : %d\n", r->gradeD);
    fprintf(fp, "F  : %d\n", r->gradeF);
    fprintf(fp, "=============================================\n");
}

void writeStudentRecordsToFile(Student *head, FILE *fp)
{
    fprintf(fp, "\n================ STUDENT RECORDS ================\n");
    fprintf(fp, "%-12s %-20s %-8s %-12s %-6s\n",
            "StudentID", "Name", "Total", "Percentage", "Grade");
    fprintf(fp, "-------------------------------------------------\n");

    Student *curr = head;
    while (curr != NULL)
    {
        fprintf(fp, "%-12s %-20s %-8d %-12.2f %-6s\n",
                curr->studentId,
                curr->name,
                curr->total,
                curr->percentage,
                curr->grade);

        curr = curr->next;
    }

    fprintf(fp, "=================================================\n");
}

void tabulateClassResults(Student *head, char *filename)
{
    if (head == NULL || filename == NULL)
    {
        fprintf(stderr, "Invalid input to tabulateClassResults\n");
        return;
    }

    TabularReport *report = (TabularReport *)malloc(sizeof(TabularReport));
    fprintf(stderr, "Generating CLass Stats\n");
    generateClassReport(head, report);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to write to output file: %s\n", filename);
        exit(1);
    }

    fprintf(stderr, "Writing Student Records\n");
    writeStudentRecordsToFile(head, fp);

    fprintf(stderr, "Writing Class Stats\n");
    writeClassReportToFile(report, fp);

    fclose(fp);
    free(report);
}
