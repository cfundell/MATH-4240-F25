#!/bin/bash
#
## Run with 
##      sbatch job_script

#SBATCH --time=00:10:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=36
##SBATCH --partition=instruction

# RUN CODE

module purge
module load intel

# mpirun -np 1 ./main.exe 10 > N_10.txt
# mpirun -np 2 ./main.exe 10 >> N_10.txt
# mpirun -np 4 ./main.exe 10 >> N_10.txt
# mpirun -np 8 ./main.exe 10 >> N_10.txt

# mpirun -np 1 ./main.exe 50 > N_50.txt
# mpirun -np 2 ./main.exe 50 >> N_50.txt
# mpirun -np 4 ./main.exe 50 >> N_50.txt
# mpirun -np 8 ./main.exe 50 >> N_50.txt
# mpirun -np 16 ./main.exe 50 >> N_50.txt
# mpirun -np 32 ./main.exe 50 >> N_50.txt

# mpirun -np 1 ./main.exe 500 > N_500.txt
# mpirun -np 2 ./main.exe 500 >> N_500.txt
# mpirun -np 4 ./main.exe 500 >> N_500.txt
# mpirun -np 8 ./main.exe 500 >> N_500.txt
# mpirun -np 16 ./main.exe 500 >> N_500.txt
# mpirun -np 32 ./main.exe 500 >> N_500.txt

# mpirun -np 1 ./main.exe 2500 > N_2500.txt
# mpirun -np 2 ./main.exe 2500 >> N_2500.txt
# mpirun -np 4 ./main.exe 2500 >> N_2500.txt
# mpirun -np 8 ./main.exe 2500 >> N_2500.txt
# mpirun -np 16 ./main.exe 2500 >> N_2500.txt
# mpirun -np 32 ./main.exe 2500 >> N_2500.txt

# mpirun -np 1 ./main.exe 5000 > N_5000.txt
# mpirun -np 2 ./main.exe 5000 >> N_5000.txt
# mpirun -np 4 ./main.exe 5000 >> N_5000.txt
# mpirun -np 8 ./main.exe 5000 >> N_5000.txt
# mpirun -np 16 ./main.exe 5000 >> N_5000.txt
# mpirun -np 32 ./main.exe 5000 >> N_5000.txt

# mpirun -np 1 ./main.exe 7500 > N_7500.txt
# mpirun -np 2 ./main.exe 7500 >> N_7500.txt
# mpirun -np 4 ./main.exe 7500 >> N_7500.txt
# mpirun -np 8 ./main.exe 7500 >> N_7500.txt
# mpirun -np 16 ./main.exe 7500 >> N_7500.txt
# mpirun -np 32 ./main.exe 7500 >> N_7500.txt

mpirun -np 1 ./main.exe 15000 > N_15000.txt
mpirun -np 2 ./main.exe 15000 >> N_15000.txt
mpirun -np 4 ./main.exe 15000 >> N_15000.txt
mpirun -np 8 ./main.exe 15000 >> N_15000.txt
mpirun -np 16 ./main.exe 15000 >> N_15000.txt
mpirun -np 32 ./main.exe 15000 >> N_15000.txt

mpirun -np 1 ./main.exe 10000 > N_10000.txt
mpirun -np 2 ./main.exe 10000 >> N_10000.txt
mpirun -np 4 ./main.exe 10000 >> N_10000.txt
mpirun -np 8 ./main.exe 10000 >> N_10000.txt
mpirun -np 16 ./main.exe 10000 >> N_10000.txt
mpirun -np 32 ./main.exe 10000 >> N_10000.txt

# mpirun -np 1 ./main.exe 20000 > N_20000.txt
# mpirun -np 2 ./main.exe 20000 >> N_20000.txt
# mpirun -np 4 ./main.exe 20000 >> N_20000.txt
# mpirun -np 8 ./main.exe 20000 >> N_20000.txt
# mpirun -np 16 ./main.exe 20000 >> N_20000.txt
# mpirun -np 32 ./main.exe 20000 >> N_20000.txt

# ./main.exe > output.txt
