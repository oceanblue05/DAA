#include <stdio.h>

int myAtoi(char *s) {
    int sign = 1;
    long long result = 0;
    int i = 0;


    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i++] - '0');

        if (result * sign < -2147483648LL) {
            return -2147483648;
        }
        if (result * sign > 2147483647LL) {
            return 2147483647;
        }
    }

    return (int)(result * sign);
}

int main() {
    char s1[] = "42";
    char s2[] = " -42";
    char s3[] = "4193 with words";

    printf("Example 1: %d\n", myAtoi(s1)); 
    printf("Example 2: %d\n", myAtoi(s2)); 
    printf("Example 3: %d\n", myAtoi(s3)); 

    return 0;
}

