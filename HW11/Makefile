#/home/cfundell/ISU-HPC-F25/MATH-4240-F25/HW11/Makefile
CC = gcc
FFLAGS = -O3 -Wall
LFFLAG = 
OBJECTS = linked_letters.o \
GenerateList.o \
GetKey.o \
SearchList.o \
Print.o 

main.exe: $(OBJECTS)
	$(CC) $(FFLAGS) $(OBJECTS) -lm -o linked_letters.exe

clean:
	rm -f $(OBJECTS) linked_letters.exe