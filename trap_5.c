#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double Trap(double a, double b, int n, int thread_count);  
double f(double x);

int main(int argc, char* argv[]) {

    double global_result = 0.0;
    double a, b;
    int n;
    int thread_count;  

    if (argc < 2) {     
        printf("Usage: %s <thread_count>\n", argv[0]);
        return 1;
    }

    thread_count = strtol(argv[1], NULL, 10);   

    printf("Enter starting point (a), ending point (b), and number of trapezoids (n): ");
    scanf("%lf %lf %d", &a, &b, &n);

    global_result = Trap(a, b, n, thread_count);  

    printf("With n=%d trapezoids, the estimated area under the curve from %f to %f is:\n", n, a, b);
    printf("%f\n", global_result);

    return 0;
}

double Trap(double a, double b, int n, int thread_count) {  
    double h, x, approx;
    int i;
    int my_rank;

    h = (b - a) / n;

    approx = f(a) + f(b);
    approx = approx / 2.0;

#pragma omp parallel for num_threads(thread_count) reduction(+:approx) private(x, my_rank)   
    for (i = 1; i <= n - 1; i++) {
        my_rank = omp_get_thread_num();
        x = a + i * h;
        printf("Thread %d of %d has calculated x: %f\n", my_rank, thread_count, x);
        approx += f(x);
    }

    approx = approx * h;

    return approx;
}

double f(double x) {
    return x * x;
}
