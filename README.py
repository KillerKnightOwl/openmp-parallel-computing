# OpenMP Parallel Computing in C

This project demonstrates parallel programming concepts using OpenMP.

## Programs
- Pi approximation using parallel reduction
- Trapezoidal rule for numerical integration
- Fibonacci (parallel experiment)

## Compile
gcc -fopenmp pi_parallel.c -o pi
gcc -fopenmp trap_5.c -o trap
gcc -fopenmp fibo.c -o fib

## Run
./pi 1000000 4
./trap 4
./fib 4

## Author
Jovany Trejo