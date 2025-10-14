#/home/cfundell/ISU-HPC-F25/MATH-4240-F25/HW11/Makefile
CC = gcc
FFLAGS = -O3 -Wall
LFFLAG = 
OBJECTS = matrix.o \
FindZero.o \
GetShift.o \
Hessenberg.o \
QRA.o \
QRdecomp.o \
trimatrix.o \
main.o

.PHONY: clean help

main.exe: $(OBJECTS)
	$(CC) $(FFLAGS) $(OBJECTS) -lm -o main.exe

clean:
	rm -f $(OBJECTS) main.exe