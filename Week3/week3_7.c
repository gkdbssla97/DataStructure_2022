//
// Created by 하윤 on 2022/03/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursive(char *str, char c, int len, int cnt);
int main(void) {
    char str[101], c;
    gets(str);
    scanf("%c", &c);
    getchar();
    int len = strlen(str), cnt = 0;
    printf("%d\n",recursive(str, c, len, cnt));
}
int recursive(char *str, char c, int len, int cnt) {
    if (len == 0) {
        return 0;
    }
    else {
        if(c == str[len - 1]) {
            // printf("%d %d\n", tmp, c);
            return 1 + recursive(str, c, len - 1, cnt);
        }
        else
            return 0 + recursive(str, c, len - 1, cnt);
    }
}
/*
 * Alg recursive(str, c, len, cnt)
 *  if(len = 0)
 *      return 0
 *  else
 *      if(c = str[len - 1]
 *          return 1 + recursive(str, c, len - 1, cnt)
 *      else
 *          return 0 + recursive(str, c, len - 1, cnt)
 */