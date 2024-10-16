#include <stdio.h>
#include <stdint.h>

int main() {
    float num;
    printf("Enter a decimal number: ");
    scanf("%f", &num);

    union {
        float f;
        uint32_t i;
    } u = {num};

    // Extract the sign, exponent, and mantissa based on IEEE 754 format
    uint32_t sign = (u.i >> 31) & 1;
    uint32_t exp = (u.i >> 23) & 0xFF;
    uint32_t mantissa = u.i & 0x7FFFFF;

    printf("Sign: %u\nExponent: %u (in decimal)\nMantissa: ", sign, exp);
    for (int i = 22; i >= 0; i--)
        printf("%d", (mantissa >> i) & 1);
    printf("\n");
    return 0;
}
