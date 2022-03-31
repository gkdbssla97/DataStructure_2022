//
// Created by 하윤 on 2022/03/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, M, arr[100][100];
    scanf("%d %d", &N, &M);
    getchar();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
    int a = 1, p_i = 0, p_j = 0, x, y;
    arr[p_i][p_j] = a;
    while (a <= N * M) {
        // 오른쪽으로 이동
        if(p_j + 1 < M && arr[p_i][p_j + 1] == 0) {
            p_j++;
            arr[p_i][p_j] = ++a;
            //printf("if %d\n", p_j);
        }
        else {
            p_i++;
            arr[p_i][p_j] = ++a;
            //printf("else %d %d\n", p_i, p_j);
        }
        x = p_i;
        y = p_j;
        //printf("x:%d y:%d\n", x, y);
        while (y > 0 && x + 1 < N && (arr[x + 1][y - 1] == 0)) {
            x++;
            y--;
            arr[x][y] = ++a;
            //printf("arr[%d][%d] = %d\n", x, y, arr[x][y]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", arr[i][j]);
        } printf("\n");
    }

    return 0;
}