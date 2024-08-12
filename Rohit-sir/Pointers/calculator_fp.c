#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float div(int a, int b) {
    if (b != 0)
        return (float)a / b;
    else {
        printf("Error: Division by zero\n");
        return 0.0;
    }
}

void operateInt(int (*op)(int, int), int a, int b) {
    int result = op(a, b);
    printf("Result: %d\n", result);
}

void operateFloat(float (*op)(int, int), int a, int b) {
    float result = op(a, b);
    printf("Result: %.2f\n", result);
}

int main() {
    int a = 10, b = 5;

    operateInt(add, a, b);
    operateInt(sub, a, b);
    operateInt(mul, a, b);
    operateFloat(div, a, b);

    return 0;
}

