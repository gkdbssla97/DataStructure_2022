//
// Created by 하윤 on 2022/04/16.
//

#include <stdio.h>
#include <stdlib.h>

int modulo(int a, int b);
int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    getchar();

    printf("%d\n", modulo(a, b));

    return 0;
}
int modulo(int a, int b) {
    if (a < b)
        return a;
    else
        return modulo(a-b, b);
}

/*
 * Alg modulo(a, b)
 *  if(a < b)
 *      return a;
 *  else
 *      return modulo(a-b, b)
 */
