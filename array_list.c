#include<stdio.h>
#include<stdlib.h>

void insert(int **array, int val, int index, int *size, int *capacity) {

    if(*size >= *capacity){
        *capacity = (*capacity) * 2;
        *array = realloc(*array, (*capacity) * sizeof(int));
        if(*array == NULL) {
            printf("Memory error \n");
            exit(-1);
        }
    }

    for(int i = *size; i>index; i--){
        (*array)[i] = (*array)[i-1];
    }
    (*array)[index] = val;
    (*size)++;
    return;
}



void print_array(int *array, int size) {

    for(int i=0; i<size; i++){
        printf("\n%d", array[i]);
    }
    return;
}

int main(void) {
    int *array = malloc(sizeof(int)*1);
    int size = 0;
    int capacity = 1;

    insert(&array, 3, 0, &size, &capacity);
    insert(&array, 5, 1, &size, &capacity);
    insert(&array, 9, 2, &size, &capacity);
    insert(&array, 2, 1, &size, &capacity);

    print_array(array, size);
}
