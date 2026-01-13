#include"parser.h"
#include"student.h"
#include<stdio.h>
#include<stdlib.h>
#include"subject.h"


Student *parseInputFile(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        fprintf(stderr, "Could not open the input file: %s.\n", filename);
        exit(1);
    }

    char line[1024];

    Student *head, *tail;
    head = tail = NULL;
    
    while(fgets(line, sizeof(line), fp)) {
        char name[512], studentId[32];
        if (sscanf(line, "%s, %s", studentId, name) == 2) {
            Student *student = addStudent(studentId, name);
            if (head == NULL) {
                head = tail = student;
            } else {
                tail->next = student;
                tail = student;
            }
            Subject *subjects[NUM_SUBJECTS];
            int subject_i = 0;

            while(fgets(line, sizeof(line), fp)) {
                int minorMark, majorMark;
                if (sscanf(line, "%d, %d", minorMark, majorMark) == 2) {
                    // TODO
                } else {
                    fprintf(stderr, "Could not parse marks line: %s\n", line);
                    exit(1);
                }
            }

        } else {
            fprintf(stderr, "Could not parse student line: %s\n", line);
            exit(1);
        }
    }

    return head; 
}