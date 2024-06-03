#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int expand(char* s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; 
}

char* longestPal(char* s) {
    int start = 0, end = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int len1 = expand(s, i, i); 
        int len2 = expand(s, i, i + 1); 
        int maxLen = len1 > len2 ? len1 : len2;
        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }
    char* result = (char*)malloc((end - start + 2) * sizeof(char));
    strncpy(result, &s[start], end - start + 1);
    result[end - start + 1] = '\0';
    return result;
}

int main() {
    char s1[] = "babad";
    char s2[] = "cbbd";

    printf("Example 1: %s\n", longestPal(s1)); 
    printf("Example 2: %s\n", longestPal(s2)); 

    return 0;
}

