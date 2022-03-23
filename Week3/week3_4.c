//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>

int recursive(int *arr, int n);
int main(void) {
    int N, arr[20] = {NULL};
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", recursive(arr, N));
}
int recursive(int *arr, int n) {
    if (n == 0)
        return arr[0];
    int max = recursive(arr, n - 1);
    arr[n] = max < arr[n] ? arr[n] : max;
    return arr[n];
}
