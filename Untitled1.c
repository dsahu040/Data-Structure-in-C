#include<stdio.h>

int main(void) {
    int arr[] = {5,4,7,2,9,11,18};

    int *ptr_arr = &arr;
    for(int *walker = ptr_arr; walker < &arr[sizeof(arr)/sizeof(int)]; walker++) {
        printf("\n%d", *walker);
    }

    return 0;
}
