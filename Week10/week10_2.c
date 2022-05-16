//
// Created by 하윤 on 2022/05/15.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(int elem);
int pop();
char topPos();
int isEmpty();
int isChar(char elem);
int calc(char op, int num1, int num2);
int CtoD(char op);
char stack[100];
int s_size = 0; // 스택 크기

int main(void) {
    int N, opr1, opr2, result;
    scanf("%d", &N);
    getchar();

    char val, str[101];
    for (int i = 0; i < N; i++) {
        gets(str);

        for (char *p = str; *p != 0; p++) {
            if (isChar(*p))
                push(CtoD(*p));
            else {
                opr1 = pop();
                opr2 = pop();
                result = calc(*p, opr2, opr1);
                //printf("opr1:%d opr2:%d\n", opr1, opr2);
                //printf("result:%d\n", result);
                push(result);
            }
        } printf("%d\n", result);
    }

    return 0;
}
void push(int elem) {
    stack[s_size++] = elem;
}
int pop() {
    return stack[--s_size];
}
char topPos() {
    return stack[s_size - 1];
}
int isEmpty() {
    if (s_size == 0)
        return 1;
    return 0;
}
int isChar(char elem) {
    if (elem >= '0' && elem <= '9')
        return 1;
    return 0;
}

int calc(char op, int num1, int num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;

    }
}
int CtoD(char op) {
    return op - '0';
}
/*
 * 53*2+63+2*+
234*+
72/3-42*+21*-
923*1+2*+

 */