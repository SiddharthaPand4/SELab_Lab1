CC = gcc
CFLAGS = -Wall
TARGET=MI12

all: $(TARGET)

$(TARGET): main.o parser.o student.o subject.o tabular_report.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o parser.o student.o subject.o tabular_report.o

main.o: main.c parser.h student.h tabular_report.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c parser.h student.h
	$(CC) $(CFLAGS) -c parser.c

student.o: student.c student.h subject.h
	$(CC) $(CFLAGS) -c student.c

tabular_report.o: tabular_report.c tabular_report.h student.h
	$(CC) $(CFLAGS) -c tabular_report.c

subject.o: subject.c subject.h
	$(CC) $(CFLAGS) -c subject.c

clean:
	rm -f *.o $(TARGET)