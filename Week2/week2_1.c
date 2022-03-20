//
// Created by 하윤 on 2022/03/16.
//

#include <stdio.h>

int modulo(int a, int b);
int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", modulo(a, b));

    return 0;
}
int modulo(int a, int b) {
    int result = a % b;
    return result;
}