//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>

void recursive(int N);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    recursive(N);
}
void recursive(int N) {
    if (N < 10) {
        printf("%d\n", N);
    } else {
        recursive(N / 10);
        printf("%d\n", N % 10);
    }
}
