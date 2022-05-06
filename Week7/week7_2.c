//
// Created by 하윤 on 2022/05/06.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *next;
    int elem;
} NODE;

void init_FirstNode(NODE *node);
void addNode(NODE *node, int elem);
NODE * union_(NODE *A, NODE *B);
NODE * intersect(NODE *A, NODE *B);
void print(NODE *C);
void freeNode(NODE *node);
int main(void) {
    int A_size, B_size, val;
    NODE *A = (NODE *) malloc(sizeof(NODE));
    NODE *B = (NODE *) malloc(sizeof(NODE));
    init_FirstNode(A);
    init_FirstNode(B);
    scanf("%d", &A_size);
    getchar();
    for(int i = 0; i < A_size; i++) {
        scanf("%d", &val);
        addNode(A, val);
    }

    scanf("%d", &B_size);
    getchar();
    for(int i = 0; i < B_size; i++) {
        scanf("%d", &val);
        addNode(B, val);
    }

    NODE *C = union_(A, B);
    NODE *D = intersect(A, B);

    print(C);
    print(D);

    freeNode(A);
    freeNode(B);
    freeNode(C);
    freeNode(D);

    return 0;
}
void init_FirstNode(NODE *node) {
    node->elem = 0;
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
NODE * union_(NODE *A, NODE *B) {
    NODE *A_u = A;
    NODE *B_u = B;

    NODE *C = (NODE *) malloc(sizeof(NODE));
    init_FirstNode(C);
    if((A_u->next == NULL) && (B_u->next == NULL))
        return C;
    else if(A_u->next == NULL) {
        freeNode(C);
        return B_u;
    }
    else if(B_u->next == NULL) {
        freeNode(C);
        return A_u;
    }
    else {
        A_u = A_u->next;
        B_u = B_u->next;

        while((A_u != NULL) && (B_u != NULL)) {
            if(A_u->elem < B_u->elem) {
                addNode(C, A_u->elem);
                A_u = A_u->next;
            }
            else if(A_u->elem > B_u->elem) {
                addNode(C, B_u->elem);
                B_u = B_u->next;
            }
            else {
                addNode(C, B_u->elem);
                A_u = A_u->next;
                B_u = B_u->next;
            }
        } while(A_u != NULL) {
            addNode(C, A_u->elem);
            A_u = A_u->next;
        } while(B_u != NULL) {
            addNode(C, B_u->elem);
            B_u = B_u->next;
        }
    } return C;
}
NODE * intersect(NODE *A, NODE *B) {
    NODE *A_u = A;
    NODE *B_u = B;

    NODE *C = (NODE *) malloc(sizeof(NODE));
    init_FirstNode(C);
    if((A_u->next == NULL) && (B_u->next == NULL))
        return C;
    else if(A_u->next == NULL) {
        return C;
    }
    else if(B_u->next == NULL) {
        return C;
    }
    else {
        A_u = A_u->next;
        B_u = B_u->next;
        while ((A_u != NULL) && (B_u != NULL)) {
            if (A_u->elem < B_u->elem) {
                A_u = A_u->next;
            } else if (A_u->elem > B_u->elem) {
                B_u = B_u->next;
            } else {
                addNode(C, B_u->elem);
                A_u = A_u->next;
                B_u = B_u->next;
            }
        }
    } return C;
}
void freeNode(NODE *node) {
    NODE * tmp = node;
    while (tmp != NULL) {
        node = node->next;
        free(tmp);
        tmp = node;
    }
}
void print(NODE * C) {
    NODE * result = C->next;
    if (result == NULL)
        printf(" 0\n");
    else {
        while (result != NULL) {
            printf(" %d", result->elem);
            result = result->next;
        } printf("\n");
    }
}