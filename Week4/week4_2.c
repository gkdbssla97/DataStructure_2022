//
// Created by 하윤 on 2022/04/02.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, arr[100] = {NULL} , K, sequence[100] = {NULL};
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &K);
    getchar();
    for (int i = 0; i < K; i++)
        scanf("%d", &sequence[i]);

    // 3 8 0 9 3
    int p_end = arr[sequence[K - 2]], p_start = arr[sequence[0]];
    for (int i = K - 2; i > 0; i--) {
        arr[sequence[i]] = arr[sequence[i - 1]];
    }
    arr[sequence[0]] = p_end;

    for (int i = 0; i < N; i++)
        printf(" %d", arr[i]);

    return 0;
}
/*10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3
*/