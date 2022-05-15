//
// Created by 하윤 on 2022/05/15.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(char elem);
char pop();
char topPos();
int isEmpty();
int isChar(char elem);
int priority(char op);

char stack[100];
int s_size = 0; // 스택 크기

int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    char val, str[101];
    for (int i = 0; i < N; i++) {
        gets(str);

        for (char *p = str; *p != 0; p++) {
            if (isChar(*p))
                printf("%c", *p);
            else if (*p == '(')
                push(*p);
            else if (*p == ')') {
                while (topPos() != '(') {
                    val = pop();
                    if (val == 'p') val = '+';
                    else if (val == 'm') val = '-';
                    printf("%c", val);
                } pop();
            }
            else {
                if(*p == '+' && !isChar(*(p-1)) && isChar(*(p+1)) && *(p-1) != ')')
                    *p = 'p';
                else if(*p == '-' && !isChar(*(p-1)) && isChar(*(p+1)) && *(p-1) != ')')
                    *p = 'm';
                while(!isEmpty() && (priority(*p) <= priority(topPos()))) {
                    val = pop();
                    if(val == 'p') val = '+';
                    else if(val == 'm') val = '-';
                    printf("%c", val);
                }
                if (*p == '&' || * p == '|') {
                    push(*p);
                    p++;
                } push(*p);
            }
        }
        while (!isEmpty()) {
            val = pop();
            if (val == 'p') val = '+';
            else if (val == 'm') val = '-';
            printf("%c", val);
        }
    }

    return 0;
}

void push(char elem) {
    stack[s_size++] = elem;
}
char pop() {
    char ch = stack[--s_size];
    return ch;
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
    if (elem >= 'A' && elem <= 'Z')
        return 1;
    return 0;
}
int priority(char op) {
    switch (op) {
        case '(':
            return 0;
        case '|':
            return 1;
        case '&':
            return 2;
        case '<': case'>':
            return 3;
        case '+': case '-':
            return 4;
        case '*': case '/':
            return 5;
        case '!': case 'p': case 'm':
            return 6;
    }
}