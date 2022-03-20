//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>
void swap(int *arr1, int *arr2);
int main(void) {
    int N, arr[51], a, b;
    scanf("%d", &N);
    getchar();
    for(int i = 0 ;i < N; i++)
        scanf("%d", &arr[i]);
    getchar();
    scanf("%d %d", &a, &b);
    getchar();

    swap(&arr[a], &arr[b]);
    for(int i = 0; i < N; i++)
        printf(" %d", arr[i]);
    return 0;
}
void swap(int *arr1, int *arr2) {
    int tmp = *arr1;
    *arr1 = *arr2;
    *arr2 = tmp;

}


