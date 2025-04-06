#include <stdio.h>
#include <stdint.h>


int32_t heron_area_squared(int32_t a,int32_t b,int32_t c){
    int32_t result, s;
    s = (a + b + c)/2;

    asm volatile(
        "sub t0, %1, %4\n\t"       
        "sub t1, %1, %5\n\t"       
        "sub t2, %1, %6\n\t"       
        "mul t3, %1, t0\n\t"       
        "mul t3, t3, t1\n\t"       
        "mul %0, t3, t2"           
        : "=r"(result)
        : "r"(s), "r"(a), "r"(b), "r"(c), "r"(a), "r"(b), "r"(c)
        : "t0", "t1", "t2", "t3"
    );
    return result; 
}

int main(){
    int a = 3, b = 4, c = 5;
    int32_t area_squared = heron_area_squared(a, b, c);
    printf("Heron Area^2: %d\n", area_squared);
    return 0;
}
