//
// Created by 하윤 on 2022/03/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, arr[100][100];
    scanf("%d", &N);
    getchar();
    int val = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] = val++;
        }
    }
    for(int i = 1; i < N; i += 2) {
        int tmp;
        for(int j = 0; j < N / 2; j++) {
            tmp = arr[i][j];
            arr[i][j] = arr[i][N - j - 1];
            arr[i][N - j - 1] = tmp;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf(" %d", arr[i][j]);
        } printf("\n");
    }

    return 0;
}
/*10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3
*/