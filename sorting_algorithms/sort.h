#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_array(int* array1, int* array2, int* array3, int* array4, int length);
void choice_sort_array(int* array, int length);
void buble_sort_array(int* array, int length);
void fast_sort_array(int* array, int length);
void heap_sort_array(int* array, int length);
void init_heap(int* array, int length, int* help_array);
void up_min_hip(int* help_array, int len);
void print_array(int* array, int length);
void swap(int* a, int* b);
void sort(int* array, int length, void(*sort_alg)(int*, int));

#endif