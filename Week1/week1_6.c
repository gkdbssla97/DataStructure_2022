//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    int score;
} Student;
int main(void) {
    Student st[5];

    double avg = 0.0;
    for (int i = 0; i < 5; i++) {
        scanf("%s %d", st[i].name, &st[i].score);
        avg += st[i].score;
    } avg /= 5;
    for (int i = 0; i < 5; i++) {
        if(avg > st[i].score)
            printf("%s\n", st[i].name);
    }
    return 0;
}