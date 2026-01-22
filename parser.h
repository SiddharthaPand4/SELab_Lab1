#ifndef PARSER_H
#define PARSER_H
#include "student.h"

/*
 Input:
   - filename: Path to the input text file containing student records

 Pre-conditions:
   - The file must exist and be readable
   - File format must strictly follow:
       <student_id>, <student_name>
       <minor_marks>, <major_marks>

 Logic:
   - Open the input file
   - Read line by line
   - Parse student id and name
   - For each student, read NUM_SUBJECTS lines of marks
   - Create Student and Subject structures
   - Store students in a linked list.

 Output:
   - Returns pointer to the head of the linked list of Student records
   - Terminates program on parsing errors
 */

Student *parseInputFile(char *filename);

#endif