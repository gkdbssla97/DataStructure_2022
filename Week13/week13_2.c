//
// Created by 하윤 on 2022/05/30.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct bTreeNode {
    element data;
    element id;
    struct bTreeNode * left;
    struct bTreeNode * right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
element GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, element data, element id);
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
void InorderTraverse(BTreeNode * bt);
void FindNode(BTreeNode * bt, element id);
void DeleteTree(BTreeNode * bt);

BTreeNode * findNode;
int sum = 0;

int main(void) {
    BTreeNode * F1 = MakeBTreeNode(); // rootNode
    BTreeNode * F2 = MakeBTreeNode();
    BTreeNode * F3 = MakeBTreeNode();
    BTreeNode * F4 = MakeBTreeNode();
    BTreeNode * F5 = MakeBTreeNode();
    BTreeNode * F6 = MakeBTreeNode();
    BTreeNode * F7 = MakeBTreeNode();
    BTreeNode * F8 = MakeBTreeNode();

    SetData(F1, 20, 1);
    SetData(F2, 30, 2);
    SetData(F3, 50, 3);
    SetData(F4, 70, 4);
    SetData(F5, 90, 5);
    SetData(F6, 120, 6);
    SetData(F7, 130, 7);
    SetData(F8, 80, 8);

    MakeLeftSubTree(F1, F2);
    MakeRightSubTree(F1, F3);
    MakeLeftSubTree(F2, F4);
    MakeRightSubTree(F2, F5);
    MakeRightSubTree(F3, F6);
    MakeLeftSubTree(F6, F7);
    MakeRightSubTree(F6, F8);

    element cmd, N;

    scanf("%d", &N);
    getchar();

    if (N <= 8 && N >= 1) {
        FindNode(F1, N);
        InorderTraverse(findNode);
        printf("%d\n", sum);
    }
    else
        printf("-1\n");
    DeleteTree(F1); // 동적할당 메모리 해제

    return 0;
}

BTreeNode* MakeBTreeNode(void) {
    BTreeNode * node = (BTreeNode *) malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}
element GetData(BTreeNode * bt) {
    return bt->data;
}
void SetData(BTreeNode * bt, element data, element id) {
    bt->data = data;
    bt->id = id;
}
BTreeNode * GetLeftSubTree(BTreeNode * bt) {
    return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt) {
    return bt->right;
}
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
    if(main->left != NULL)
        free(main->left);
    main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
    if(main->right != NULL)
        free(main->right);
    main->right = sub;
}
void InorderTraverse(BTreeNode * bt) {
    if(bt == NULL)
        return;
    InorderTraverse(bt->left);
    //printf(" %d", bt->data);
    sum += bt->data;
    InorderTraverse(bt->right);
}
void FindNode(BTreeNode * bt, element id) {
    if(bt == NULL)
        return;
    if(bt->id == id)
        findNode = bt;

    FindNode(bt->left, id);
    FindNode(bt->right, id);
}
void DeleteTree(BTreeNode * bt) {
    if(bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    //printf("del: %d\n", bt->data);
    free(bt);
}
