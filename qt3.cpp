#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;

    int maxLen = 0;
    int start = 0;
    int index[128] = {0}; 

    for (int end = 0; end < len; end++) {
        if (index[s[end]] > start) {
            start = index[s[end]];
        }
        index[s[end]] = end + 1;
        int currLen = end - start + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}

int main() {
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";

    printf("Example 1: %d\n", lengthOfLongestSubstring(s1)); // Output: 3
    printf("Example 2: %d\n", lengthOfLongestSubstring(s2)); // Output: 1
    printf("Example 3: %d\n", lengthOfLongestSubstring(s3)); // Output: 3

    return 0;
}

