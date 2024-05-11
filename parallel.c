#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define num_points 100000000
#define num_threads 4

int main() {
    unsigned long in_cir = 0;

    double start_time = omp_get_wtime(); // Added to measure execution time

    #pragma omp parallel
    {
        int num_thr = omp_get_num_threads();
        unsigned long thread_counter = 0;
        unsigned int seed = omp_get_thread_num(); // Added to make rand thread-safe

        for (unsigned long i = 0; i < (int)num_points / num_thr; i++) {
            float x = (double)rand_r(&seed) / RAND_MAX - 0.5; // Made rand_r thread-safe
            float y = (double)rand_r(&seed) / RAND_MAX - 0.5; // Made rand_r thread-safe
            if (x * x + y * y <= 0.5 * 0.5) {
                thread_counter++;
            }
        }

        #pragma omp atomic // Changed to omp atomic for better performance
        in_cir += thread_counter;
    }

    double end_time = omp_get_wtime();
    printf("Pi %f %f\n", 4.0 * ((double)in_cir / num_points), end_time - start_time); // Corrected format specifiers

    return 0; // Added return statement
}
