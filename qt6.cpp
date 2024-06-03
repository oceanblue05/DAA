#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) {
        return s;
    }

    char** rows = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((strlen(s) + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int currentRow = 0;
    int direction = 1; 

    for (int i = 0; i < strlen(s); i++) {
        strcat(rows[currentRow], &s[i]);
        currentRow += direction;
        if (currentRow == 0 || currentRow == numRows - 1) {
            direction *= -1;
        }
    }

    char* result = (char*)malloc((strlen(s) + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }

    free(rows);
    return result;
}

int main() {
    char s1[] = "PAYPALISHIRING";
    int numRows1 = 3;
    char s2[] = "PAYPALISHIRING";
    int numRows2 = 4;
    char s3[] = "A";
    int numRows3 = 1;

    printf("Example 1: %s\n", convert(s1, numRows1)); 
    printf("Example 2: %s\n", convert(s2, numRows2)); 
    printf("Example 3: %s\n", convert(s3, numRows3)); 

    return 0;
}

