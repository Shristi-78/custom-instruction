#include <stdio.h>
#include <stdint.h>

// Heron's formula pseudo instruction: Area² = s * (s - a) * (s - b) * (s - c)
int32_t heron_area_squared(int32_t a, int32_t b, int32_t c) {
    int32_t result, s;

    // s = (a + b + c) / 2
    s = (a + b + c) / 2;

    asm volatile (
        "sub t0, %1, %4\n\t"       // t0 = s - a
        "sub t1, %1, %5\n\t"       // t1 = s - b
        "sub t2, %1, %6\n\t"       // t2 = s - c
        "mul t3, %1, t0\n\t"       // t3 = s * (s - a)
        "mul t3, t3, t1\n\t"       // t3 = t3 * (s - b)
        "mul %0, t3, t2"           // result = t3 * (s - c)
        : "=r"(result)
        : "r"(s), "r"(a), "r"(b), "r"(c), "r"(a), "r"(b), "r"(c)
        : "t0", "t1", "t2", "t3"
    );

    return result; // This is Area², not Area
}

int main() {
    int a = 3, b = 4, c = 5;
    int32_t area_squared = heron_area_squared(a, b, c);
    printf("Heron Area^2: %d\n", area_squared);
    return 0;
}
