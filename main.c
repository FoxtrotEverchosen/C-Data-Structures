#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main(){

    vec v1;
    new_vec(&v1);

    append_vec(&v1, 1);
    append_vec(&v1, 2);
    append_vec(&v1, 3);
    append_vec(&v1, 4);
    append_vec(&v1, 5);

    int v1_size = get_vec_len(&v1);
    printf("Vector v1 got %d elements: \n", v1_size);

    printf("[");
    for(int i=0; i<v1_size; i++){
        printf("%d, ", v1.data[i]);
    }
    printf("]\n");
    printf("v1 capacity: %d\n", v1.capacity);
    printf("v1 item at index=3: %d\n", get_vec_item(&v1, 3));

    return 0;
}
