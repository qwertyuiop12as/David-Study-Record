#include <stdio.h>

void printArray(int *arrayPointer, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arrayPointer[i]);

    arrayPointer[0] = -1;
    printf("\n");
    return;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}, len = 5;

    printArray(arr, len);
    printf("%d\n", arr[0]);
    return 0;
}
