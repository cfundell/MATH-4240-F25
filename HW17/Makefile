#/home/cfundell/ISU-HPC-F25/MATH-4240-F25/HW11/Makefile
CC = gcc
FFLAGS = -O3 -Wall -std=c99 -fopenmp
LFFLAG = -lgomp
OBJECTS = matrix.o \
main.o

.PHONY: clean help

main.exe: $(OBJECTS)
	$(CC) $(FFLAGS) $(OBJECTS) -lm -o main.exe

clean:
	rm -f $(OBJECTS) main.exe