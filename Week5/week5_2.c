//
// Created by 하윤 on 2022/04/13.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int coef; //계수
    int exp; //차수
    struct NODE * next;
}NODE;

typedef struct List{
    NODE *head;
    int cnt;
} LIST;

void init(LIST *list);
NODE * appendTerm(NODE * k, int c, int e);
NODE * addPoly(LIST *x, LIST *y);

int main(void) {
    LIST x, y, z;
    init(&x);
    init(&y);
    init(&z);

    NODE *cur = x.head;

    int N, coef, exp;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &coef, &exp);
        getchar();
        cur = appendTerm(cur ,coef, exp);
    }
    scanf("%d", &N);
    getchar();
    cur = y.head;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &coef, &exp);
        getchar();
        cur = appendTerm(cur ,coef, exp);
    }
    cur = addPoly(&x, &y);
    while(cur != NULL) {
        if (cur->coef != 0)
            printf(" %d %d", cur->coef, cur->exp);
        cur = cur->next;
    }

    return 0;
}
void init(LIST *list) {
    list->head = (NODE *) malloc(sizeof(NODE));
    list->head->next = NULL;
    list->cnt = 0;
}
NODE * appendTerm(NODE * k, int c, int e) {
    NODE *t = (NODE *) malloc(sizeof(NODE));
    t->coef = c;
    t->exp = e;
    t->next = NULL;
    k->next = t;
    k = t;
    return k;
}
NODE * addPoly(LIST *x, LIST *y) {
    NODE *result = (NODE *) malloc(sizeof(NODE));
    result->next = NULL;

    NODE *i = x->head->next;
    NODE *j = y->head->next;
    NODE *k = result;

    while((i != NULL) && (j != NULL)) {
        if(i->exp > j->exp) {
            k = appendTerm(k, i->coef, i->exp);
            i = i->next;
        }
        else if(i->exp < j->exp) {
            k = appendTerm(k, j->coef, j->exp);
            j = j->next;
        }
        else {
            int sum = i->coef + j->coef;
            if(sum != 0)
                k = appendTerm(k, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }
    while(i != NULL) {
        k = appendTerm(k, i->coef, i->exp);
        i = i->next;
    }
    while(j != NULL) {
        k = appendTerm(k, j->coef, j->exp);
        j = j->next;
    }

    return result;
}
