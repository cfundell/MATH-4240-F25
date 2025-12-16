#/home/cfundell/ISU-HPC-F25/MATH-4240-F25/HW11/Makefile
CC = mpicc
FFLAGS = -O3 -Wall -std=c99
LFLAGS = 
OBJECTS = matrix.o \
random_mat.o \
main_MPI.o


main.exe: $(OBJECTS) 
	$(CC) $(LFLAGS) $(OBJECTS) -lm -o main.exe
	
%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:	
	rm -f $(OBJECTS) *.exe *.data