#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 12

static int cmpint(const void *p1, const void *p2) {
    return (*(int*)p1 - *(int*)p2);
}

static int cmpstring(const void *p1, const void *p2) {
    return strcmp((char *) p1, (char *) p2);
}

int main (void) {

    int* int_arr = (int*) malloc (sizeof(int) * ARR_LEN);
    char* char_arr = (char*) malloc (sizeof(char) * (ARR_LEN + 1));

    for(int i =ARR_LEN; i >0; i--) {

        int_arr[ARR_LEN-i] = i;
    }

    strcpy(char_arr, "hello_world!");

    printf("Before Sorting:\n");

    for(int i =0; i <ARR_LEN; i++) {
        printf("%d ", int_arr[i]);
    }

    printf("\n%s", char_arr);

    printf("\n\n");

    qsort(int_arr, ARR_LEN, sizeof(int), cmpint);
    qsort(char_arr, ARR_LEN, sizeof(char), cmpstring);

    printf("After Sorting: \n");

    for(int i =0; i <ARR_LEN; i++) { 
        printf("%d", int_arr[i]);
        if(i!=ARR_LEN-1) printf(" ");
    }

    printf("\n%s", char_arr);

    printf("\n");
}
