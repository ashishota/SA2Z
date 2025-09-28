#include <stdio.h>

int main() {
    int val = 10;
    int* ptr = &val;
    int* ptr1 = ptr;

    printf("%d ", *ptr == *ptr1);
    printf("%d ", ptr == ptr1);
    printf("%d ", &ptr == &ptr1);

    return 0;
}
