//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int *arr1 = (int *) malloc(sizeof(int) * N);
    int *arr2 = (int *) malloc(sizeof(int) * N);
    int *arr3 = (int *) malloc(sizeof(int) * (N / 2));
    for(int i = 0; i < N; i++)
        scanf("%d", &arr1[i]);
    for(int j = 0; j < N; j++)
        scanf("%d", &arr2[j]);

    for(int k = 0; k < N; k++) {
        arr3[k] = arr1[k] + arr2[N - k - 1];
        printf(" %d", arr3[k]);
    }
//     for(int l = 0; l < N; l++)
//        printf(" %d ", arr3[l]);
    free(arr1);
    free(arr2);
}