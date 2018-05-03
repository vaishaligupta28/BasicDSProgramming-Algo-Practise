// C program to understand difference between
// pointer to an integer and pointer to an
// array of integers.
#include<stdio.h>

int main()
{
    // Pointer to an integer

    int *p;//since it is a pointer, whatever u assign to it, it points to that value

    //Pointer to an array of 5 integers
    int (*ptr)[5];
    int arr[5] = {1, 2, 3, 4, 5};

    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = &arr;

    printf("p= %d, ptr = %d\n", p, ptr);
    printf("On dereferencing...\n");
    printf("p = %d, ptr = %d\n", *p, *ptr);//*arr === arr[0],  *(arr+1) == arr[1]

    p++;//base type of p is int... so it will be shifted by just 4 bytes
    ptr++;//base type of ptr is entire array, it will be shifted by entire arrays i.e 20 bytes

    printf("\np= %d, ptr = %d\n", p, ptr);
    printf("On dereferencing...\n");
    printf("p = %d, ptr = %d\n\n", *p, *ptr);

    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(void *));
    printf("%d\n", sizeof(int *));

    return 0;
}
