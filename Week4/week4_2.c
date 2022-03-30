//
// Created by 하윤 on 2022/03/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, arr[100] = {NULL}, K, swit[100] = {NULL};
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &K);
    getchar();
    for (int i = 0; i < K; i++)
        scanf("%d", &swit[i]);

    int i, tmp1 = arr[swit[0]], tmp2;
    for (i = K - 1; i >= 0; i--) {
        arr[swit[i]] = arr[swit[i - 1]];
    }
    for (int i = 0; i < N; i++)
        printf(" %d", arr[i]);

    return 0;
}
/*10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3
*/
