//
// Created by 하윤 on 2022/04/27.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *next;
    int elem;
} NODE;

void init(NODE *node);
void addNode(NODE *node, int elem);
int subset(NODE *A, NODE *B);
void freeNode(NODE *node);
int main(void) {
    int A_size, B_size, val;
    NODE *A = (NODE *) malloc(sizeof(NODE));
    NODE *B = (NODE *) malloc(sizeof(NODE));
    init(A);
    init(B);
    scanf("%d", &A_size);
    getchar();
    for(int i = 0; i < A_size; i++) {
        scanf("%d", &val);
        addNode(A, val);
    } getchar();

    scanf("%d", &B_size);
    getchar();
    for(int i = 0; i < B_size; i++) {
        scanf("%d", &val);
        addNode(B, val);
    } getchar();

    int result = subset(A,B);
    printf("%d\n", result);

    freeNode(A);
    freeNode(B);

    return 0;
}
void init(NODE *node) {
    node->elem = NULL;
    node->next = NULL;
}
void addNode(NODE *node, int e) {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->elem = e;
    newNode->next = NULL;

    while(node->next != NULL)
        node = node->next;
    node->next = newNode;
}
int subset(NODE *A, NODE *B) {
    if (A == NULL)
        return 0;
    else {
        while (A != NULL) {
            if(B == NULL)
                return A->elem;
            else if (A->elem < B->elem)
                return A->elem;
            else if (A->elem > B->elem)
                B = B->next;
            else {
                A = A->next;
                B = B->next;
            }
        } return 0;
    }
}
void freeNode(NODE *node) {
    NODE * tmp = node;
    while (tmp != NULL) {
        node = node->next;
        free(tmp);
        tmp = node;
    }
}