#/home/cfundell/ISU-HPC-F25/MATH-4240-F25/HW11/Makefile
CC = gcc
FFLAGS = -O3 -Wall
LFFLAG = 
OBJECTS = Option.o \
Push.o \
Pop.o \
Peek.o \
DisplayStack.o \
GetStackSize.o \
DeleteStack.o \
DisplayOptions.o \
main.o

.PHONY: clean help

main.exe: $(OBJECTS)
	$(CC) $(FFLAGS) $(OBJECTS) -lm -o main.exe

clean:
	rm -f $(OBJECTS) main.exe