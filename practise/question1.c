#include<stdio.h>

 int sum(int x) {
    printf("x is %d ", x);
        x++;
    }

void main() {
    int x = 97;
    int y = sizeof(x++);
    printf("x is %d ", x);
    printf("y is %d", y);

    return 0;
}
