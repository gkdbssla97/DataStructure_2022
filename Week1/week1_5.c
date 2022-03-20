//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>
#include <string.h>
typedef struct Time{
    int hour;
    int min;
    int sec;
}Time;
int main(void) {
    Time time1, time2;
    scanf("%d %d %d", &time1.hour, &time1.min, &time1.sec);
    scanf("%d %d %d", &time2.hour, &time2.min, &time2.sec);

    int sum1 = (time1.hour * 3600) + (time1.min * 60) + time1.sec;
    int sum2 = (time2.hour * 3600) + (time2.min * 60) + time2.sec;
    int result = sum2 - sum1;
//    printf("result:%d\n", result);
    printf("%d %d %d\n", result / 3600, (result - (3600*(result/3600))) / 60, (result) % 60);
    return 0;
}