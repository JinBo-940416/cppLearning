#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14

struct circle{
    float radius;
    int x_coor;
    int y_coor;
};

int main(){

    long a = 15;
    size_t char_size = sizeof(char);
    size_t a_size = sizeof a; 

    printf("size of a char is : %lu \n", char_size);
    printf("size of a is : %lu \n", a_size);

    return 0;
}