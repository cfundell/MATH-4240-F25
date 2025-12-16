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

mpirun -np 1 ./main.exe 100 > test.txt



# ./main.exe > output.txt
