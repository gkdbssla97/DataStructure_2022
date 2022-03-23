//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>

int recursive(int N);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    printf("%d\n", recursive(N));
}
int recursive(int N) {
    if (N / 10 == 0) {
        return N;
    } else {
        printf("%d\n", N % 10);
        return recursive(N /= 10);
    }
}
