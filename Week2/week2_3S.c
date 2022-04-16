//
// Created by 하윤 on 2022/04/16.
//

#include <stdio.h>
#include <stdlib.h>

int *prefixAverages2(int arr[], N);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    int X[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    } getchar();
    int *avg;
    avg = prefixAverages2(X, N);
    for (int i = 0; i < N; i++) {
        printf("%d ", avg[i]);
    }

    return 0;
}

int *prefixAverages2(int arr[], int N) {
    int sum = 0;
    int *avg = (int *)malloc(sizeof(int));
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        avg[i] = (int)(sum / (double)(i + 1) + 0.5);
    }
    return avg;
}

/*
 * Alg prefixAverages(X, N)
 *  sum <- 0
 *  for i <- 0 to N - 1
 *      sum <- sum + X[i]
 *      A[i] <- sum / (i + 1)
 *  return
 */