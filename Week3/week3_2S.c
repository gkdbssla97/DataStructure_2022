//
// Created by 하윤 on 2022/04/16.
//

#include <stdio.h>
#include <stdlib.h>

void rprintDigit(int N);
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    rprintDigit(N);

    return 0;
}
void rprintDigit(int N) {
    if (N < 10)
        printf("%d\n", N);
    else {
        rprintDigit(N / 10);
        printf("%d\n", N % 10);
    }
}

/*
 * Alg rPrintDigits(N)
 *  if(n < 10)
 *      write(n)
 *  else
 *      rPrintDigits(N/10)
 *         write(N%10)
 */
