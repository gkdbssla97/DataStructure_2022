//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>

int recursive(int a, int b);
int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    getchar();

    printf("%d\n",recursive(a, b));
}
int recursive(int a, int b) {
    int tmp;
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    return recursive(b, a % b);

}
