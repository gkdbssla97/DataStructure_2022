//
// Created by 하윤 on 2022/05/16.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Isdigit(char c);
void initQueue();
void Delete();
void Print();
void ExceptionError();

int main(void) {
    int q, n, data[1000];

    scanf("%d", &q);
    scanf("%d", &n);
    getchar();

    int* Queue = (int*) malloc(sizeof(int) * q);
    char ch;
    for (int i = 0; i < n; i++) {
        scanf("%c", &ch);
        if(c == 'I')
    }

    return 0;
}

void Isdigit(char c);
void initQueue();
void Delete();
void Print();
void ExceptionError();

void Isdigit(char c){
    if(c >= '1' && c <= '9')
        return 1;
    return 0;
}