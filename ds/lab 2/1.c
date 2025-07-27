/*
Q) Write a small function to find the smallest element in an array using pointers.
In the main function, create a dynamically allocated array, read the values from the
keyboard, and pass the array to the function.
Display the result (smallest element) in the main function.
*/

#include <stdio.h>
#include <stdlib.h>

int findMin(int* arr, int* end);

int main(){

    int n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int)); //dynamic allocation of memomory for array with malloc
    int *end = arr+n;  //pointer to the end of the array (address to the cell after the last cell of array)

    printf("Enter the array elements:\n");

    int *inPtr = arr;  //pointer for iteration

    while(inPtr!=end){ //checks if pointer is outside array
        scanf("%d", inPtr);
        inPtr++;  //moving the pointer to next cell
    } 

    int minimum = findMin(arr, end);

    printf("Minimum element: %d\n", minimum);

    return 0;
}

int findMin(int* arr, int* end){
    int m = *arr; //initializing minimum var
    arr++; //moving to next cell to avoid unnecessary comparison

    while(arr!=end){
        if(m>*arr) m = *arr;
        arr++;
    }

    return m;
}