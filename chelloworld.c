#include <stdio.h>

int main() {
    int a = 15;
    printf("hello world %d \n", a);

    int b = sizeof(int);
    int c = sizeof(double);
    int d = sizeof(float);

    printf("nuber of bytes for int: %d \n", b);
    printf("nuber of bytes for double: %d \n", c);
    printf("nuber of bytes for float: %d \n", d);
    return 14;
}