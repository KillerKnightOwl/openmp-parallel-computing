#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double sum = 0.0;
int n;

int main(int argc, char* argv[]){
  
  n = strtol(argv[1], NULL, 10);
  
  int thread_count = strtol(argv[2], NULL, 10);
  
  double factor = 1.0;
  
# pragma omp parallel for num_threads(thread_count) private(factor) reduction(+: sum)
  for (int i = 0; i < n; i++){
    if(i % 2 == 0) factor = 1.0;
    else factor = -1.0;
    sum += factor / (2 * i + 1);
  }
  
  double pi = 4.0 * sum;
  
  printf("The estimated value of pi is %f. \n", pi);
  
  return 0;
}
