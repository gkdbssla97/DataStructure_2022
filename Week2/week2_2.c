//
// Created by 하윤 on 2022/03/16.
//

#include <stdio.h>

int mostOnes(int arr[][100], int n);
int main(void) {
    int n, arr[100][100];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", mostOnes(arr, n));
    return 0;
}
int mostOnes(int arr[][100], int n) {
    int tmp = 0, raw = 0, col = 0;
    for(int j = 0; j < n; j++) {
        while(arr[j][tmp] != 0)
            tmp++;
        if(tmp > col) {
            col = tmp;
            raw = j;
        }
    }

    return raw;
}
/*1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0*/
