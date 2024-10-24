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
gcc jacobi2.c -O0 -o jacobi0
gcc jacobi2.c -O -o jacobi1
gcc jacobi2.c -O2 -o jacobi2
gcc jacobi2.c -O3 -o jacobi3
for i in {100..1000}; do
  ./jacobi0 $i $i .0001
done
echo >>computationTime.csv
for i in {100..1000}; do
  ./jacobi1 $i $i .0001
done
echo >>computationTime.csv
for i in {100..1000}; do
  ./jacobi2 $i $i .0001
done
echo >>computationTime.csv
for i in {100..1000}; do
  ./jacobi3 $i $i .0001
done
