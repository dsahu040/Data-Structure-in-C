#include<stdio.h>
#include<stdlib.h>

int* array_dynm() {
    int arr1[] = {7,11,47,26,62,45, 73};
    int *ptr = malloc(sizeof(int)*7);

//    for(int i = 0; i < 7; i++) {
//        *(ptr+i) = arr1[i];
//    }
    // alternate solution to above for loop
    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;
    ptr[3] = 4;
    ptr[4] = 5;
    ptr[5] = 6;
    ptr[6] = 7;
    return ptr;
}

int array_static(){
    int arr[] = {7,11,47,26,62,45};
    return &arr;
}

void print_array(int *ptr) {
     for(int i = 0; i < 7; i++) {
        printf("\n%d", *(ptr+i));
    }
    return;
}

int main(void) {
    int *ptr_da = NULL;
    ptr_da = array_dynm();
    print_array(ptr_da);

    int *arr;
    arr = array_static();
    printf("\nstatic array value = %d", *(arr));
    return 0;
}
