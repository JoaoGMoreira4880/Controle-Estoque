#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    float f = 1.5f;
    printf("1: antes do isfinite\n"); fflush(stdout);
    int r = isfinite(f);
    printf("2: isfinite devolveu %d\n", r); fflush(stdout);
    char *fim;
    float g = strtof("29.90", &fim);
    printf("3: strtof devolveu %f\n", g); fflush(stdout);
    return 0;
}