//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[8];
    int a, b, c;
    double avg;
} Student;
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    Student *student = (Student *) malloc(sizeof(Student) * N);
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", student[i].name, &student[i].a, &student[i].b, &student[i].c);
        getchar();
        student[i].avg = (double) (student[i].a + student[i].b + student[i].c) / 3;
        printf("%s %.1lf ",student[i].name, student[i].avg);
        if(student[i].a >= 90 || student[i].b >= 90 || student[i].c >= 90)
            printf("GREAT ");
        if(student[i].a < 70 || student[i].b < 70 || student[i].c < 70)
            printf("BAD\n");
    }

    free(student);
    return 0;
}