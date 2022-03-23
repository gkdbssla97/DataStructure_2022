//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursive(char *str, char c, int len);
int main(void) {
    char str[101], c;
    gets(str);
    scanf("%c", &c);
    getchar();
    int len = strlen(str);
    printf("%d\n",recursive(str, c, len));
}
int recursive(char *str, char c, int len) {
    int cnt = 0;
    if (len == 0)
        return str[len];
    else {
        char tmp = recursive(str, c, len - 1);
        if (tmp == c)
            cnt++;
    }
    return cnt;
}
// SheIsAStudent