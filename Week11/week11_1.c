//
// Created by 하윤 on 2022/05/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct circleQueue {
    int rear;
    int front;
    element * data;
} CQueue;

void initQueue(CQueue *queue, int num);
void enqueue(CQueue * queue, element data);
element dequeue(CQueue * queue);
void Print(CQueue * queue);
void ExceptionError(int cmd);
int is_Full(CQueue * queue);
int is_Empty(CQueue * queue);

int CQueueSize = 0;

int main(void) {
    int n, data[1000];
    CQueue queue;
    scanf("%d", &CQueueSize);
    scanf("%d", &n);
    getchar();

    initQueue(&queue, CQueueSize);
    char ch;
    element val;
    for (int i = 0; i < n; i++) {
        scanf("%c", &ch);
        if (ch == 'I') {
            scanf("%d", &val);
            enqueue(&queue, val);
        } else if (ch == 'D') {
            if(dequeue(&queue) == -1)
                return 0;
        } else if (ch == 'P') {
            Print(&queue);
        } getchar();
    }

    return 0;
}

void initQueue(CQueue *queue, int size) {
    queue->front = 0;
    queue->rear = 0;
    queue-> data = (element *) malloc(sizeof(element) * size);
    for(int i = 0; i < size; i++)
        queue->data[i] = 0;
}
void enqueue(CQueue * queue, element data) {
    int cmd;
    if(is_Full(queue)) {
        cmd = 1; // Overflow
        ExceptionError(cmd);
        Print(queue);
    }
    queue->rear = (queue->rear + 1) % CQueueSize;
    queue->data[queue->rear] = data;
    //printf("[data, rear]:[%d, %d]\n", data, queue->rear);

}
element dequeue(CQueue * queue) {
    if(is_Empty(queue)) {
        int cmd = 2;
        ExceptionError(cmd);
        return -1; // 프로그램 종료
    } else {
        queue->front = (queue->front + 1) % CQueueSize;
        queue->data[queue->front] = 0;
        return queue->data[queue->front - 1];
    }
}
int is_Empty(CQueue * queue) {
    if(queue->front == queue->rear)
        return TRUE;
    return FALSE;
}
int is_Full(CQueue * queue) {
    if((queue->rear + 1) % CQueueSize == queue->front)
        return TRUE;
    return FALSE;
}
void ExceptionError(int cmd) {
    if(cmd == 1)
        printf("overflow ");
    if(cmd == 2)
        printf("underflow ");
}
void Print(CQueue *queue) {
    int idx = 0;
    if (is_Empty(queue)) {
        printf("Empty queue\n");
        return;
    }
    do {
        printf("%d ", queue->data[idx]);
        idx++;
    } while (idx != CQueueSize);
    printf("\n");
}

