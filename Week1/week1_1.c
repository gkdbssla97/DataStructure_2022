//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>

int sum(int N);
int main(void) {
    int num;
    scanf("%d", &num);
    int result = 0;
    for(int i = 1; i <= num; i++) {
        result += sum(i);
    }
    printf("%d\n", result);

    return 0;
}

int sum(int N) {
    int sum = 0;
    for(int i = 1; i <= N; i++)
        sum += i;
    // printf("sum: %d\n", sum);
    return sum;
}


