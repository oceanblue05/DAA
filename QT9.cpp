#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(int x) {
    if (x < 0) {
        return 0;
    }
    char str[12]; 
    sprintf(str, "%d", x);
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int x1 = 121;
    int x2 = -121;
    int x3 = 10;

    printf("Example 1: %s\n", isPalindrome(x1) ? "true" : "false"); 
    printf("Example 2: %s\n", isPalindrome(x2) ? "true" : "false"); 
    printf("Example 3: %s\n", isPalindrome(x3) ? "true" : "false"); 

    return 0;
}

