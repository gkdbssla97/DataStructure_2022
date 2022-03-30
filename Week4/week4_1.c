//
// Created by 하윤 on 2022/03/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, arr[100] = {NULL} , K, reverse[100] = {NULL};
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &K);
    getchar();
    for (int i = 0; i < 2 * K; i++)
        scanf("%d", &reverse[i]);

    for (int i = 0; i < 2 * K; i += 2) {
        //printf("i:%d\n", i);
        int tmp, cnt = 0;
        for(int j = reverse[i]; j <= (reverse[i] + reverse[i + 1]) / 2; j++) {
            // j = 3,4,5,6,7
            //printf("j:%d\n", j);
            tmp = arr[j];
            arr[j] = arr[reverse[i+1] - cnt];
            arr[reverse[i+1] - cnt] = tmp;
            cnt++;
        } //printf("cnt:%d\n", cnt);
    }
    for (int i = 0; i < N; i++)
        printf(" %d", arr[i]);

    return 0;
}
/*10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4
*/