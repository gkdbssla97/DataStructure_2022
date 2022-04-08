//
// Created by 하윤 on 2022/04/07.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    char elem;
    struct NODE* prev;
    struct NODE* next;
} NODE;

typedef struct ADT{
    NODE *head;
    NODE *tail;
    int cnt;
} LinkedList;

typedef LinkedList List;

void InvalidError();
void init(List *list);
void add(List *list, int r, char e);
void addNodeBefore(NODE * p, char e);
char delete(List *list, int r);
char removeNode(NODE *p);
char get(List *list, int r);
void print(List *list);

int main(void) {
    int N, position;
    char cal, elem;
    scanf("%d", &N);
    getchar();

    List DList;
    init(&DList);
    for (int i = 0; i < N; i++) {
        //printf("N: %d\n", i);
        scanf("%c", &cal);
        if(cal == 'P') {
            print(&DList);
        }
        else if(cal == 'D') {
            scanf("%d", &position);
            //getchar();
            delete(&DList, position);
            //continue;
        }
        else if(cal == 'G') {
            scanf("%d", &position);
            //getchar();
            char c = get(&DList, position);
            if (c != '1')
                printf("%c\n", c);
            //continue;
        }
        else if(cal == 'A') {
            scanf("%d %c", &position, &elem);
            //getchar();
            add(&DList, position, elem);
            //continue;
        } getchar();
        //printf("node_cnt: %d\n", DList.cnt);
    }
    return 0;
}

void init(List *list) {
    list->head = (NODE *) malloc(sizeof(NODE));
    list->tail = (NODE *) malloc(sizeof(NODE));
    //list->head->elem = 0;
    //list->tail->elem = 0;
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->cnt = 0;
}
void addNodeBefore(NODE * p, char e) {
    NODE *q = (NODE *) malloc(sizeof(NODE));
    q->elem = e;
    q->prev = p->prev;
    q->next = p;
    (p->prev)->next = q;
    p->prev = q;
}
void add(List *list, int real_position, char e) {
    if(real_position < 1 || real_position > list->cnt + 1) {
        InvalidError();
        return;
    }
    else {
        NODE *q = list->head;
        for (int i = 0; i < real_position; i++) {
            q = q->next;
        }
        addNodeBefore(q, e);
        (list->cnt)++;
    }
}
char get(List *list, int r){
    //printf("r: %d list_cnt: %d\n", r, list->cnt);
    if(r < 1 || r > list->cnt) {
        InvalidError();
        return '1';
    }
    else {
        NODE *p = list->head;
        for (int i = 0; i < r; i++)
            p = p->next;
        return p->elem;
    }
}
char delete(List *list, int r) {
    if(r < 1 || r > list->cnt) {
        InvalidError();
        return '1';
    }
    else {
        NODE *p = list->head;
        for (int i = 1; i <= r; i++)
            p = p->next;
        char e = removeNode(p);
        removeNode(p);
        (list->cnt)--;
        return e;
    }
}
char removeNode(NODE *p) {
    char e = p->elem;
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    return e;
}
void print(List *list) {
    NODE *p;
    p = list->head->next;
    for(int i = 0; i < list->cnt; i++) {
        printf("%c", p->elem);
        p = p->next;
    } printf("\n");
}
void InvalidError() {
    printf("Invalid position\n");
}
/*
 * 5
A 1 S
A 2 t
A 3 r
A 3 a
P
 */

/*
 * 9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
 */