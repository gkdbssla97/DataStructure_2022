//
// Created by 하윤 on 2022/03/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, M, arr[100][100];
    scanf("%d %d", &N, &M);
    getchar();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
    int a = 1, i = 0, j = 0;
    arr[i][j] = a;
    // N 행, M 열
    while (a <= N*M) {
        // 오른쪽
        while(j + 1 < M && arr[i][j] == 0) {
            j++;
            arr[i][j] = a;
            a++;
        }// 아래
        while(i + 1 < N && arr[i][j] == 0) {
            i++;
            arr[i][j] = a;
            a++;
        }// 왼쪽
        while(j + 1 > 0 && arr[i][j] == 0) {
            j--;
            arr[i][j] = a;
            a++;
        }// 위
        while(i + 1 > 0 && arr[i][j] == 0) {
            i--;
            arr[i][j] = a;
            a++;
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