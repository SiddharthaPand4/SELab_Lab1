#include<stdio.h>
#include"parser.h"
#include"student.h"

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "The program expects two file input arguments :( and nothing else.");
        return 1;
    }

    char *inputFilename = argv[1];

    Student *studentHead = parseInputFile(inputFilename);
    updateStudentsGrades(studentHead);

    char *outputFilename = argv[2];

    tabulateClassResults(studentHead, outputFilename);

    return 0;
}