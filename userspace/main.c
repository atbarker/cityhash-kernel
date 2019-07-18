#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "city.h"

#define BUFFER_SIZE 4096

int main(){
    uint8_t *input = malloc(BUFFER_SIZE);
    struct timespec start, end;
    int i;
    for (i=0; i<BUFFER_SIZE; i++)
    {
        input[i]=(rand()%100)+1;
    }
    clock_gettime(CLOCK_MONOTONIC, &start);
    uint64_t output = CityHash64(input, BUFFER_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("result 0x%08lx generated in %ld ns\n", output, end.tv_nsec - start.tv_nsec);
    return 0;
}
