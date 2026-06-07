#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    int i;

    for (i = 0; i < size; i++){
        if(arr[i] == key)
            return 1;
    }

    return 0;
}

int main () {
    int page_number[5] = {86,91,34,50,0};

    int key = 20;

    if(linearSearch(page_number, 5, key) == 1){
        printf("Search Found");
    }
    else{
        printf("Search Not Found");
    }

    return 0;
}