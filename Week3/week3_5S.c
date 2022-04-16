//
// Created by 하윤 on 2022/04/17.
//

#include <stdio.h>
#include <stdlib.h>

void hanoi(int N);
void rHanoi(int N, char A, char aux, char C);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    hanoi(N);

    return 0;
}

void hanoi(int N) {
    rHanoi(N, 'A', 'B', 'C');
}
void rHanoi(int N, char A, char B, char C) {
    if (N == 1) {
        printf("move:%c from:%c\n", A, C);
        return;
    }
    rHanoi(N - 1, A, C, B);
    printf("move:%c from:%c\n", A, C);
    rHanoi(N - 1, B, A, C);
}

/*
 * Alg rHanoi(N, from, aux, to)
 *  if(N = 1)
 *      write("move from", from, "to", to)
 *      return
 * rHanoi(n-1, from, to, aux)
 * write("move from", from, "to", to)
 * rHanoi(n-1, aux, from, to)
 * return
 */
