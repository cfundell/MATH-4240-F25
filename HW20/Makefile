#/home/cfundell/ISU-HPC-F25/MATH-4240-F25/HW11/Makefile

CC = gcc
CFLAGS = -O3 -fopenmp -march=native     # compile flags
LDFLAGS = -fopenmp -lm                  # link flags (includes OpenMP + math lib)

OBJECTS = main.o
TARGET = main.exe

.PHONY: clean help

# Default target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

# Generic rule for compiling .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
