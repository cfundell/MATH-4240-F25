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

mpirun -np 2 ./main.exe > output2.txt
mpirun -np 4 ./main.exe > output4.txt
mpirun -np 18 ./main.exe > output16.txt
mpirun -np 36 ./main.exe > output36.txt