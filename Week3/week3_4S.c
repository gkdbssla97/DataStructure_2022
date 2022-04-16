//
// Created by 하윤 on 2022/04/16.
//

#include <stdio.h>
#include <stdlib.h>

int maxArray(int arr[], int N);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    } getchar();

    printf("%d\n", maxArray(arr, N));

    return 0;
}
int maxArray(int *arr, int N) {
    if(N == 0)
        return arr[N];
    else {
        int max = maxArray(arr, N - 1);
        printf("max:%d\n", max);
        arr[N] = max > arr[N] ? max : arr[N];
    }
    return arr[N];
}

/*
 * Alg maxArray(A, N)
 *  if(N = 0)
 *      return A[n]
 *  else
 *      max <- maxArray(A, N - 1)
 *      A[N] <- max > A[N] ? max : A[N]
 *  return A[N]
 */
