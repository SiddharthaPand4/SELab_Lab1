CC = gcc
CFLAGS = -Wall
TARGET=MI12

all: $(TARGET)

$(TARGET): main.o parser.o student.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o parser.o student.o

main.o: main.c parser.h student.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c parser.h student.h
	$(CC) $(CFLAGS) -c parser.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

#clean
clean:
	rm -f *.o $(TARGET)