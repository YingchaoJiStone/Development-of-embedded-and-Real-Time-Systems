// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 4
// Submission code: xxxxxx 

#include <stdio.h>
#include <stdlib.h>

int search_number(int number, int tab[], int size);

void sort (int number, int tab []);

void printArray(int tab[], int size);

int main(int argc, char *argv[]){

    if (argc != 2) {
        printf("Usage: %s <Integer Number>\n", argv[0]);
        return 0;
    }

    int num = atoi(argv[1]);
    if (num == 0) {
        printf("Invalid argument.\n");
        printf("Usage: %s <Integer Number>\n", argv[0]);
        return 0;
    }

    int test[] = {1,2,34,5,67,3,23,12,13,10};

    int testLength = sizeof(test) / sizeof(test[0]);

    int index = search_number(num, test, testLength);
    printf("Search result(index): %d\n", index);

    sort(testLength, test);

    printArray(test, testLength);

    return 0;
}

int search_number(int number, int tab[], int size){
    for (int i = 0; i < size; i++) {
        if (number == tab[i]) {
            return i;
        }
    }

    return -1;
}

void sort (int number, int tab[]){
    for(int i = 0; i < number; i ++){
        int minimumIndex = i;
        for(int j = i + 1; j < number; j ++ ){
            if (tab[j] < tab[minimumIndex]) {
                minimumIndex = j;
            }
        }
        int temp = tab[i];
        tab[i] = tab[minimumIndex];
        tab[minimumIndex] = temp;
    }
}

void printArray(int tab[], int size){
    printf("Sorted array: ");
    for(int i = 0; i < size; i ++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}
