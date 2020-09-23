#include<stdio.h>
#include<string.h>

int get_counter() {
    static int val = 0;
    return val++;
}

int main(void) {

    int a=0;
    a = get_counter();
    a = get_counter();
    a = get_counter();
    printf("\n%d\n", a);

    char *name = {"Deep"};
    char *name1 = name;
    name = strcat(name, name1);
    printf("\n%s", name);

    return 0;
}
