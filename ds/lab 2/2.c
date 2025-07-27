/*
Write a recursive C program to implement Selection Sort using pointers.
    •   The recursive function should sort the array using the Selection Sort algorithm.
    •   Access and manipulate the array elements using pointers (i.e., avoid using arr[i] style directly).
    •   The program should read the array from the user in the main function, call the recursive sorting 
        function, and display the sorted array.
*/

#include<stdio.h>

int Sort(int* arr, int* end);
int swap(int *a, int *b);


void main()
{
    int l;
    printf("Enter length of the array to be sorted:\n");
    scanf("%d", &l);

    int a[l];
    int* end = a+l; //pointer to the end of the array

    //input
    printf("Enter the elements of the array:\n");
    for(int i = 0; i<l; i++) scanf("%d", a+i); 

    Sort(a, end);

    //displaying array
    printf("[");
    for(int i = 0; i<l; i++) printf("%d ", *(a+i));   
    printf("]"); 
}

int Sort(int* start, int* end){
    
    if(start==end) return 0; //BASE CONDITION: checks if subarray is empty

    int *ptr = start+1; //iterator starting at second position to avoid unneccessary comparison
    int *minimum = start;  //initialzing minimum var

    while(ptr!=end){ //checks if pointer is at the end of the array
        if(*ptr<*minimum) minimum = ptr;
        ptr++;
    }

    if(*minimum!=*start) swap(start, minimum); //performs swap IF minimum element found is less than 1st element in subarray

    Sort(start+1, end); //recursive sort: chooses a subarray with 1 less element from start
}

int swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
}