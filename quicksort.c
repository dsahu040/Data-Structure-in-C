#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void print_array(int *ary, int size);
void quick_sort(int *ary, int p, int r);
int partition(int *ary, int r);

# define SIZE 20

int main(void) {
    int ary[SIZE] = {0};
    int i = 0;

    srand(time(NULL));
    for(i=0; i < SIZE; i++) {
        ary[i] = rand()%100;
    }

    print_array(ary, SIZE);


    return 0;
}

void print_array(int *ary, int size) {
    printf("\n-----------------------\n");
    for(int i =0; i < SIZE; i++) {
        printf("%3d ", ary[i]);
        if(i%(SIZE/4) == (SIZE/4)-1) {
        printf("\n");
        }
    }
    printf("\n");
}

void quick_sort(int *ary, int p, int r) {
    int q = 0;
    if(p<r) {
        q = partition(ary, p, r);
        quick_sort(ary, p, q-1);
        quick_sort(ary, q+1, r);
    }
    return;
}

int partition(int *ary, int p, int r) {
    int temp_index = -1;
    int temp_value = -1;
    int pivot = -1;
    int i = -1;
    int j = -1;


}
