#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "student.h"
#include "subject.h"
#include "parser.h"
#include "tabular_report.h"

void printTestResult(const char *testName, int condition)
{
    if (condition)
        printf("[PASS] %s\n", testName);
    else
        printf("[FAIL] %s\n", testName);
}

void test_addSubject()
{
    Subject *s = addSubject("Maths", 40, 60);

    assert(s != NULL);
    assert(strcmp(s->name, "Maths") == 0);
    assert(s->minorMarks == 40);
    assert(s->majorMarks == 60);
    assert(s->totalMarks == 100);

    printTestResult("addSubject(): valid marks", 1);
}

void test_addStudent()
{
    Student *head = NULL;
    Student *s1 = addStudent(head, "1", "Siddharth");

    assert(s1 != NULL);
    assert(strcmp(s1->studentId, "1") == 0);
    assert(strcmp(s1->name, "Siddharth") == 0);
    assert(s1->next == NULL);

    printTestResult("addStudent(): first student", 1);
}

void test_updateStudentsGrades()
{
    Student *s = addStudent(NULL, "1", "Test Student");

    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        s->subjects[i] = addSubject("Sub", 40, 60); // total = 100
    }

    updateStudentsGrades(s);

    assert(s->total == 500);
    assert(s->percentage == 100.0f);
    assert(strcmp(s->grade, "O") == 0);

    printTestResult("updateStudentsGrades(): grade O", 1);
}

void test_parseInputFile()
{
    Student *head = parseInputFile("sample_input.txt");

    assert(head != NULL);
    assert(strcmp(head->studentId, "1") == 0);
    assert(strcmp(head->name, "Siddharth Pandey") == 0);

    Student *second = head->next;
    assert(second != NULL);
    assert(strcmp(second->studentId, "2") == 0);

    printTestResult("parseInputFile(): valid input", 1);
}

void test_tabulateClassResults()
{
    Student *head = parseInputFile("sample_input.txt");
    updateStudentsGrades(head);

    tabulateClassResults(head, "test_output.txt");

    FILE *fp = fopen("test_output.txt", "r");
    assert(fp != NULL);

    fclose(fp);

    printTestResult("tabulateClassResults(): file generation", 1);
}

int main()
{
    printf(" Running Student System Test Cases \n\n");

    test_addSubject();
    test_addStudent();
    test_updateStudentsGrades();
    test_parseInputFile();
    test_tabulateClassResults();

    printf("\n All Tests Executed Successfully \n");
    return 0;
}
