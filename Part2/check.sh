#!/bin/bash

gcc jacobi2.c -O0 -o jacobi0
gcc jacobi2.c -O -o jacobi1
gcc jacobi2.c -O2 -o jacobi2
gcc jacobi2.c -O3 -o jacobi3
gcc jacobi2d.c -o bench
./bench $1 $2 .0001
./jacobi0 $1 $2 .0001
python3 accuracy_check.py
./jacobi1 $1 $2 .0001
python3 accuracy_check.py
./jacobi2 $1 $2 .0001
python3 accuracy_check.py
./jacobi3 $1 $2 .0001
python3 accuracy_check.py
rm -rf jacobiResult.csv
rm -rf jacobi0 jacobi1 jacobi2 jacobi3 bench
