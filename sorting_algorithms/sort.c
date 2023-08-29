#include "sort.h"

int read_array(int* array1, int* array2, int* array3, int* array4, int length) {
    printf("Enter an array: ");
    float x;
    int f = 1;
        for (int i = 0; i < length; i++) {
            if (scanf("%f", &x) && x == (int)x) {
                array1[i] = (int)x;
                array2[i] = (int)x;
                array3[i] = (int)x;
                array4[i] = (int)x;
            } else {
                f = 0;
                break;
            }
        }
    return f;
}

void choice_sort_array(int* array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j > i; j--) {
            if (array[j] < array[i]) {
                swap(array + i, array + j);
            }
        }
    }
}

void buble_sort_array(int* array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = length - 2; j >= i; j--) {
            if (array[j] > array[j + 1]) {
                swap(array + j, array + j + 1);
            }
        }
    }
}

void fast_sort_array(int* array, int length) {
    int i = 0;
    int j = length - 1;
    int middle = array[length / 2];
    while (i < j) {
        while (array[i] < middle) {
            i++;
        }
        while (array[j] > middle) {
            j--;
        }
        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if (j > 0) {
        fast_sort_array((array + j), length - j);
    }
    if (i < length) {
        fast_sort_array(array, i);
    }
}

void heap_sort_array(int* array, int length) {
    int* help_array = malloc((length + 1) * sizeof(int));
    init_heap(array, length, help_array);
    array[0] = help_array[1];
    for (int i = 1; i < length; i++) {
        up_min_hip(help_array, length - i + 1);
        array[i] = help_array[1];
    }
    free(help_array);
}

void up_min_hip(int* help_array, int len) {
    int j = 1;
    help_array[j] = help_array[len];
    int child1 = help_array[j * 2], child2 = help_array[j * 2 + 1];
    while ((j * 2 <= len && help_array[j] > child1) || (j * 2 + 1 <= len && (help_array[j] > child2))) {
        if (help_array[j] > child1 && (j * 2 + 1 <= len && child2 > child1)) {
            swap(help_array + j, help_array + j * 2);
            j = j * 2;
        } else {
            swap(help_array + j, help_array + j * 2 + 1);
            j = j * 2 + 1;
        }
        child1 = help_array[j * 2];
        child2 = help_array[j * 2 + 1];
    }
}

void init_heap(int* array, int length, int* help_array) {
    help_array[0] = -1;
    help_array[1] = array[0];
    for (int i = 1; i < length; i++) {
        int parent = i + 1;
        int prev_parent = parent / 2;
        help_array[i + 1] = array[i];
        while (help_array[prev_parent] > help_array[parent]) {
            swap(help_array + prev_parent, help_array + parent);
            parent = prev_parent;
            prev_parent = parent / 2;
        }
    }
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void print_array(int* array, int length) {
    for (int* p = array; p - array < length; p++) {
        printf("%d", *p);
        if (p - array != length - 1) {
            printf(" ");
        }
    }
}

void sort(int* array, int length, void(*sort_alg)(int*, int)) {
    clock_t begin = clock();
    sort_alg(array, length);
    clock_t end = clock();
    printf("Sorted array: ");
    print_array(array, length);
    printf("\n");
    printf("It took %lf milliseconds to sort it by this algorithm\n", (double)(end - begin) / (CLOCKS_PER_SEC/1000));
}