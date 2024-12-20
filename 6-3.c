#include <stdio.h>
#include <stdint.h>

void printIEEE754(float number) {
    uint32_t *bits = (uint32_t *)&number;

    uint32_t sign = (*bits >> 31) & 1;

    uint32_t exponent = (*bits >> 23) & 0xFF;

    uint32_t mantissa = *bits & 0x7FFFFF;

    printf("Sign: %u\n", sign);

    printf("Exponent: ");
    for (int i = 7; i >= 0; --i) {
        printf("%u", (exponent >> i) & 1);
    }
    printf("\n");

    printf("Mantissa: ");
    for (int i = 22; i >= 0; --i) {
        printf("%u", (mantissa >> i) & 1);
    }
    printf("\n");
}

int main() {
    float input;

    scanf("%f", &input);

    printIEEE754(input);

    return 0;
}
