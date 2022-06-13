//
// Created by 하윤 on 2022/05/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct NODE {
    struct NODE * next;
    struct NODE * prev;
    element elem;
} NODE;

typedef struct dequeue {
    NODE * front;
    NODE * rear;
} Dequeue;

void initQueue(Dequeue *queue);
void add_front(Dequeue * queue, element data);
element delete_front(Dequeue * queue);
void add_rear(Dequeue * queue, element data);
element delete_rear(Dequeue * queue);
void print(Dequeue * queue);
void ExceptionError(int cmd);
int is_Empty(Dequeue * queue);
void freeNode(Dequeue *queue);

int CQueueSize = 0;

int main(void) {
    int n, data[1000];
    Dequeue queue;
    scanf("%d", &n);
    getchar();

    initQueue(&queue);
    char ch[3];
    element val;
    for (int i = 0; i < n; i++) {
        scanf("%s", ch);
        getchar();
        if (strcmp(ch, "AF") == 0) {
            scanf("%d", &val);
            getchar();
            add_front(&queue, val);
        } else if (strcmp(ch, "AR") == 0 ) {
            scanf("%d", &val);
            getchar();
            add_rear(&queue, val);
        } else if (strcmp(ch, "DF") == 0 ) {
            if(delete_front(&queue) == -1)
                return 0;
        } else if (strcmp(ch, "DR") == 0 ) {
            if(delete_rear(&queue) == -1)
                return 0;
        } else if (strncmp(ch, "P", 1) == 0) {
            print(&queue);
        } //getchar();
    }
    freeNode(&queue);

    return 0;
}

void initQueue(Dequeue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}
void add_front(Dequeue * queue, element data) {
    NODE * newNode = (NODE*) malloc(sizeof(NODE));
    newNode->elem = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(is_Empty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->front->prev = newNode;
        newNode->next = queue->front;
        queue->front = newNode;
    }
}
void add_rear(Dequeue * queue, element data) {
    NODE * newNode = (NODE*) malloc(sizeof(NODE));
    newNode->elem = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(is_Empty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        newNode->prev = queue->rear;
        queue->rear = newNode;
    }
}
element delete_front(Dequeue * queue) {
    element data;
    if(is_Empty(queue)) {
        int cmd = 2;
        ExceptionError(cmd);
        return -1; // 프로그램 종료
    }
    else {
        NODE * p = queue->front;
        data = p->elem;
        if(queue->front->next == NULL) {
            queue->front = NULL;
            queue->rear = NULL;
            free(p);
        }
        else { // node 2개 이상일 때
            queue->front = queue->front->next;
            queue->front->prev = NULL;
            free(p);
            //p = queue->front;
        }
    }
    return data;
}
element delete_rear(Dequeue * queue) {
    element data;
    if(is_Empty(queue)) {
        int cmd = 2;
        ExceptionError(cmd);
        return -1; // 프로그램 종료
    }
    else {
        NODE * p = queue->rear;
        data = p->elem;
        if(queue->rear->prev == NULL) {
            queue->front = NULL;
            queue->rear = NULL;
            free(p);
        }
        else { // node 2개 이상일 때
            queue->rear = queue->rear->prev;
            queue->rear->next = NULL;
            free(p);
            //p = queue->front;
        }
    }
    return data;
}
int is_Empty(Dequeue * queue) {
    if(queue->front == NULL && queue->rear == NULL)
        return TRUE;
    return FALSE;
}
void ExceptionError(int cmd) {
    if(cmd == 2)
        printf("underflow ");
}
void print(Dequeue *queue) {
    if (is_Empty(queue)) {
        printf("Empty queue\n");
        return;
    }
    NODE * p = queue->front;
    while(p != NULL) {
        printf(" %d", p->elem);
        p = p->next;
    } printf("\n");
}
void freeNode(Dequeue *queue) {
    NODE * tmp = queue->front;
    while (tmp != NULL) {
        queue->front = queue->front->next;
        free(tmp);
        tmp = queue->front;
    }
}