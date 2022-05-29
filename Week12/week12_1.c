//
// Created by 하윤 on 2022/05/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct bTreeNode {
    element data;
    struct bTreeNode * left;
    struct bTreeNode * right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
element GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, element data);
BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
void InorderTraverse(BTreeNode * bt);

int main(void) {
    BTreeNode * F1 = MakeBTreeNode();
    BTreeNode * F2 = MakeBTreeNode();
    BTreeNode * F3 = MakeBTreeNode();
    BTreeNode * F4 = MakeBTreeNode();
    BTreeNode * F5 = MakeBTreeNode();
    BTreeNode * F6 = MakeBTreeNode();
    BTreeNode * F7 = MakeBTreeNode();
    BTreeNode * F8 = MakeBTreeNode();

    SetData(F1, 20);
    SetData(F2, 30);
    SetData(F3, 50);
    SetData(F4, 70);
    SetData(F5, 90);
    SetData(F6, 120);
    SetData(F7, 130);
    SetData(F8, 80);

    MakeLeftSubTree(F1, F2);
    MakeRightSubTree(F1, F3);
    MakeLeftSubTree(F2, F4);
    MakeRightSubTree(F2, F5);
    MakeRightSubTree(F3, F6);
    MakeLeftSubTree(F6, F7);
    MakeRightSubTree(F6, F8);

    int N;

    scanf("%d", &N);
    getchar();

    switch (N) {
        case 1:
            InorderTraverse(F1);
            break;
        case 2:
            InorderTraverse(F2);
            break;
        case 3:
            InorderTraverse(F3);
            break;
        case 4:
            InorderTraverse(F4);
            break;
        case 5:
            InorderTraverse(F5);
            break;
        case 6:
            InorderTraverse(F6);
            break;
        case 7:
            InorderTraverse(F7);
            break;
        case 8:
            InorderTraverse(F8);
            break;
        default:
            printf("-1");
            break;
    } printf("\n");

    //InorderTraverse(F1);
    for(int i = 1; i < 9; i++) {
        char i = itoa(i);
        printf("i = %c\n")
        str = strcat(str, i);
        free(str);
    }
    free(F1);
    free(F2);


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
void SetData(BTreeNode * bt, element data) {
    bt->data = data;
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
    printf("%d ", GetData(bt));
    if (GetLeftSubTree(bt) != NULL)
        printf("%d ", GetData(GetLeftSubTree(bt)));
    if (GetRightSubTree(bt) != NULL)
        printf("%d ", GetData(GetRightSubTree(bt)));
}