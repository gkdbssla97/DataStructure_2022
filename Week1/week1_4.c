//
// Created by 하윤 on 2022/03/13.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[101];
    gets(str);
    printf("%s\n", str);
    int len = strlen(str);
    for(int i = 0; i < len - 1; i++) {
        char tmp = str[0];
        for(int j = 1; j < len; j++) {
            str[j - 1] = str[j];
        } str[len - 1] = tmp;
        printf("%s\n", str);
    }
    return 0;
}
