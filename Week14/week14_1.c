//
// Created by 하윤 on 2022/06/08.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct bTreeNode {
    element id;
    struct bTreeNode * left;
    struct bTreeNode * right;
} BTreeNode;

BTreeNode* MakeBTreeNode(element elem);
void PreorderTraverse(BTreeNode * bt);
void DeleteTree(BTreeNode * bt);
void insertNode(int left, int right, element elem);
void findNode(BTreeNode *node, element elem);

BTreeNode* parent;
BTreeNode* root = NULL;

int main(void) {
    int num, N, left, right;
    scanf("%d", &num);
    //getchar();

    for(int i = 0; i < num; i++) {
        scanf("%d %d %d", &N, &left, &right);

        insertNode(left, right, N);
        //printf("findNode: %d left:%d right:%d\n", parent->id, parent->left->id, parent->right->id);
    } getchar();
    //PreorderTraverse(root);
    printf("\n");
    int travel;
    char str[101];
    scanf("%d", &travel);
    getchar();
    for(int i = 0; i < travel; i++) {
        gets(str);
        int len = strlen(str);
        printf(" %d", root->id);
        parent = root;
        for (int j = 0; j < len; j++) {
            if (str[j] == 'L') {
                printf(" %d", parent->left->id);
                parent = parent->left;
            } else if (str[j] == 'R') {
                printf(" %d", parent->right->id);
                parent = parent->right;
            }
        } printf("\n");
    }
    DeleteTree(root); // 동적할당 메모리 해제

    return 0;
}

BTreeNode* MakeBTreeNode(element elem) {
    BTreeNode * node = (BTreeNode *) malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->id = elem;
    return node;
}

void PreorderTraverse(BTreeNode * bt) {
    if(bt == NULL)
        return;
    printf(" %d", bt->id);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void insertNode(int left, int right, element elem) {
    if(root == NULL) {
        parent = MakeBTreeNode(elem);
        root = parent;
    }
    else
        findNode(root, elem);
    if(left != 0) {
        parent->left = MakeBTreeNode(left);
    }
    if(right != 0) {
        parent->right = MakeBTreeNode(right);
    }
}

void findNode(BTreeNode *node, element elem) {
    if(node == NULL)
        return;
    // node 아래 자식노드가 NULL일 경우 재귀탈출.
    if (node->id == elem)
        parent = node;
    findNode(node->left, elem);
    findNode(node->right, elem);
}

void DeleteTree(BTreeNode * bt) {
    if(bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    //printf("del: %d\n", bt->data);
    free(bt);
}
/**
*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR
*/