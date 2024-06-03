#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergedSize = nums1Size + nums2Size;
    int merged[mergedSize];
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }

    if (mergedSize % 2 == 0) {
        return (merged[mergedSize / 2 - 1] + merged[mergedSize / 2]) / 2.0;
    } else {
        return merged[mergedSize / 2];
    }
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    printf("Median: %.5f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    int nums3Size = sizeof(nums3) / sizeof(nums3[0]);
    int nums4Size = sizeof(nums4) / sizeof(nums4[0]);

    printf("Median: %.5f\n", findMedianSortedArrays(nums3, nums3Size, nums4, nums4Size));

    return 0;
}

