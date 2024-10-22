#!/bin/bash
#
#SBATCH --job-name=Jacobi2D_serial
#SBATCH --output=./Jacobi2D_serial.txt
#
#SBATCH --cpus-per-task=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --nodes=1
#SBATCH --partition=COMP1680-dev
for i in {100..200}; do
  ./jacobi $i $i .0001
done
