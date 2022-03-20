//
// Created by 하윤 on 2022/03/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10000000001

int* prefixAverage1(int *arr, int n);
int* prefixAverage2(int *arr, int n);
int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    int *arr = (int *) malloc(sizeof(int) * n);
    int *avg;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    avg = prefixAverage1(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", avg[i]);
    printf("\n");
    avg = prefixAverage2(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", avg[i]);

    free(arr);
    free(avg);

    return 0;
}
int* prefixAverage1(int *arr, int n){
    int *avg = (int *) malloc(sizeof(int) * n);
    //avg[0] = arr[0];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += arr[j];
            avg[i] = (int) ((sum / (double) (i + 1)) + 0.5);
        }
    }
    return avg;
}
int* prefixAverage2(int *arr, int n) {
    int sum = 0;
    int *avg = (int *) malloc(sizeof(int) * n);
    //avg[0] = arr[0];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        avg[i] = (int) ((sum / (double) (i + 1)) + 0.5);
        // printf("%lf ", avg[i]);
    }
    return avg;
}
