#include "sort.h"

int main() {
    printf("Enter a length of array: ");
    float x;
    int length = 0;
    if (scanf("%f", &x) && x == (int)x) {
        length = (int)x;
    }
    if (length) {
        int* array1 = malloc(length * sizeof(int));
        int* array2 = malloc(length * sizeof(int));
        int* array3 = malloc(length * sizeof(int));
        int* array4 = malloc(length * sizeof(int));
        if (read_array(array1, array2, array3, array4, length)) {
            printf("Sorting by choice\n");
            sort(array1, length, choice_sort_array);
            printf("Bubble sorting\n");
            sort(array2, length, buble_sort_array);
            printf("Quick sorting\n");
            sort(array3, length, fast_sort_array);
            printf("Sorting by heaps\n");
            sort(array4, length, heap_sort_array);
        } else {
            printf("Error in input");
        }
        free(array1);
        free(array2);
        free(array3);
        free(array4);
    }
    else {
        printf("Error in input");
    }
    return 0;
}