//
// Created by 하윤 on 2022/05/04.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ADT {
    char *stack;
    int stack_Size;
    int top;
} ADT;

void push(ADT * adt, char c);
char pop(ADT * adt);

int main(void) {
    ADT adt;
    char bracket[1000];
    adt.top = 0;

    gets(bracket);
    int len = strlen(bracket);
    adt.stack = (char *) malloc(sizeof(char) * len);
    strcpy(adt.stack, bracket);
    //printf("%s\n", adt.stack);

    int cnt = 0, result = 1;
    for (int i = 0; i < len; i++) {
        if (adt.stack[i] == '[' || adt.stack[i] == '{' || adt.stack[i] == '(') {
            push(&adt, adt.stack[i]);
            cnt++;
        }
        else if (adt.stack[i] == ']') {
            if(pop(&adt) != '[')
                result = 0;
            cnt++;
        }
        else if (adt.stack[i] == '}') {
            if(pop(&adt) != '{')
                result = 0;
            cnt++;
        }
        else if (adt.stack[i] == ')') {
            if(pop(&adt) != '(')
                result = 0;
            cnt++;
        }
    }
    if (result == 1 && adt.top == 0)
        printf("OK_%d\n", cnt);
    else
        printf("Wrong_%d\n", cnt);

    free(adt.stack);

    return 0;
}
void push(ADT * adt, char c) {
    adt->stack[adt->top++] = c;
}
char pop(ADT * adt) {
    char elem = adt->stack[--adt->top];
    return elem;
}
