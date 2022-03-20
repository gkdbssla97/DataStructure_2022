//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>

void ABC(int *arr, int k);
int main(void) {
    int arr[10];
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    int k = 10;
    for(int i = 0; i < k; i++)
        ABC(arr, i);
    int j = 0;
    for(int *arr1 = arr; j < 10; j++, arr1++)
        printf( "%d ", *arr1);
}
void ABC(int *arr, int k) {
    int idx, max = -9999;
    int *arr1 = arr;
    for(int i = 0; i < k; i++)
        arr1++;
    for(int i = k; i < 10; i++, arr1++) {
        if(max < *arr1) {
            max = *arr1;
            idx = i;
        }
    } //printf("max = %d, idx= %d\n", max, idx);
    int tmp = *(arr + idx);
    *(arr + idx) = *(arr + k);
    *(arr + k) = tmp;
    int i = 0;
//    for(int *arr2 = arr; i < 10 ;arr2++, i++)
//        printf( "%d ", *arr2);



