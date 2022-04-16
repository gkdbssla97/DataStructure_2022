//
// Created by 하윤 on 2022/04/16.
//

#include <stdio.h>
#include <stdlib.h>

int mostOnes(int arr[][100], int n);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    int arr[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", mostOnes(arr, N));
    return 0;
}
int mostOnes(int arr[][100], int n) {
    int i = 0, j = 0, row = 0;
    while (i < n && j < n) {
        if (arr[i][j] == 0)
            i++;
        else {
            row = i;
            j++;
        }
    } return row;
}
/*
 * Alg mostOnes(A, n)
 *  i<-j<-row<-0
 *      while((i < n) & (j < n))
 *          if(A[i,j] = 0)
 *              i <- i + 1
 *          else
 *              row <- i
 *              j <- j + 1
 *      return row
 */