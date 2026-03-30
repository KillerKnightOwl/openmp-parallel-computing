#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  int thread_count = strtol(argv[1], NULL, 10);
  
  const int n = 40;
  int fibo[n];
  fibo[0] = fibo[1] = 1;
  
  
# pragma omp parallel for num_threads(thread_count)
  for (int i = 2; i < n; i++){
    fibo[i] = fibo [i-1] + fibo[i-1];
  }
  
  printf("The Fibonacci numbers are: \n");
  for (int i = 0; i < n; i++){
    printf("%d,", fibo[i]);
  }
  
  printf("End of program reached.\n");
  
  return 0;

}
