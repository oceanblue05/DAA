#include <stdio.h>

int main() {
    int nums[] = {2, 7, 11, 15};
    int t = 9;
    int size = 4; 
    int res[2];
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == t) {
                res[0] = i;
                res[1] = j;
                printf("Indices: %d, %d", res[0], res[1]);
                return 0;
            }
        }
    }
    return 0;
}

