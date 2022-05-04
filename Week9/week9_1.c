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

void push(ADT *adt, char e);
char pop(ADT *adt);
void peek(ADT *adt);
void duplicate(ADT *adt);
void upRotate(ADT *adt, int n);
void downRotate(ADT *adt, int n);
void fullStackException();
void StackEmptyException();
void print(ADT *adt);

int main(void) {
    ADT adt;
    adt.top = 0;
    scanf("%d", &adt.stack_Size);
    getchar();
    adt.stack = (char *) malloc(sizeof(char) * adt.stack_Size);

    int command_cnt;
    scanf("%d", &command_cnt);
    getchar();

    char cmd[10], elem;
    for (int i = 0; i < command_cnt; i++) {
        gets(cmd);
        if (strncmp(cmd, "PUSH", 4) == 0) {
            push(&adt, cmd[5]);
        }
        else if (strncmp(cmd, "POP", 3) == 0) {
            if(adt.top == 0)
                StackEmptyException();
            else pop(&adt);
        }
        else if ((strncmp(cmd, "PEEK", 4) == 0)) {
            peek(&adt);
        }
        else if ((strncmp(cmd, "DUP", 3) == 0)) {
            duplicate(&adt);
        }
        else if ((strncmp(cmd, "UpR", 3) == 0)) {
            upRotate(&adt, cmd[4] - '0');
        }
        else if ((strncmp(cmd, "DownR", 5) == 0)) {
            downRotate(&adt, cmd[6] - '0');
        }
        else if ((strncmp(cmd, "PRINT", 5) == 0)) {
            print(&adt);
        } //printf("topPos = %d\n", adt.top);
    }
    free(adt.stack);

    return 0;
}
void push(ADT * adt, char e) {
    if (adt->stack_Size == adt->top) {
        fullStackException();
        return;
    }
    adt->stack[adt->top++] = e;
}
char pop(ADT * adt) {
    char elem = adt->stack[--(adt->top)];
    return elem;
}
void peek(ADT * adt) {
    if (adt->top == 0)
        StackEmptyException();
    printf("%c\n", adt->stack[adt->top - 1]);
}
void duplicate(ADT * adt) {
    if (adt->stack_Size == adt->top) {
        fullStackException();
        return;
    }
    char elem = pop(adt);
    push(adt, elem);
    push(adt, elem);
}
void upRotate(ADT * adt, int n) {
    if (n > adt->top)
        return;
    char elem = adt->stack[adt->top - 1];
    for (int i = 0; i < n - 1; i++) {
        adt->stack[adt->top - 1 - i] =
                adt->stack[adt->top - 2 - i];
    } adt->stack[adt->top - n] = elem;
}
void downRotate(ADT * adt, int n) {
    if (n > adt->top)
        return;
    char elem = adt->stack[adt->top - n];
    for (int i = adt->top - n; i < adt->top; i++) {
        adt->stack[i] = adt->stack[i + 1];
    } adt->stack[adt->top - 1] = elem;
}
void print(ADT * adt) {
    for (int i = adt->top - 1; i >= 0; i--) {
        printf("%c", adt->stack[i]);
    } printf("\n");
}
void fullStackException() {
    printf("Stack FULL\n");
}
void StackEmptyException(ADT * adt) {
    printf("Stack Empty\n");
}