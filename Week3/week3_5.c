//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive(int n, char A, char B, char C);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    recursive(N, 'A', 'B', 'C');
}
void recursive(int n, char A, char B, char C) {
    if (n == 1) {
        printf("%c %c\n", A, C);
        return;
    }
    recursive(n - 1, A, C, B);
    printf("%c %c\n", A, C);
    recursive(n - 1, B, A, C);
    return;
}
// SheIsAStudent