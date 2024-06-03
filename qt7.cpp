#include <stdio.h>

int reverse(int x) {
    int result = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        if (result > 214748364 || (result == 214748364 && digit > 7)) {
            printf("Reversing caused overflow.\n");
            return 0;
        }
        if (result < -214748364 || (result == -214748364 && digit < -8)) {
            printf("Reversing caused overflow.\n");
            return 0;
        }
        result = result * 10 + digit;
    }
    
    return result;
}

int main() {
    int x1 = 123;
    int x2 = -123;
    int x3 = 120;

    printf("Example 1: %d\n", reverse(x1)); 
    printf("Example 2: %d\n", reverse(x2)); 
    printf("Example 3: %d\n", reverse(x3)); 

    return 0;
}

