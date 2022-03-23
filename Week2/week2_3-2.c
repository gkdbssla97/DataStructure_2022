//
// Created by 하윤 on 2022/03/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000000001

int* prefixAverage1(int *arr, int n);
int* prefixAverage2(int *arr, int n);
int main(void) {
    int n;
    scanf("%d", &n);
    getchar();
///////////////////////////////////////////
    double start, end, result;
///////////////////////////////////////////
    srand(time(NULL));
    int *arr = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 10000 + 1;
    start = (double)clock() / CLOCKS_PER_SEC;
    prefixAverage1(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    result = (double) (end - start);
    printf("%lfms\n", result);

    start = (double)clock() / CLOCKS_PER_SEC;
    prefixAverage2(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    result = (double) (end - start);
    printf("%lfms\n", result);


    free(arr);

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
