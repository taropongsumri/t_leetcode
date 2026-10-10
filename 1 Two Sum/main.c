#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    while (i < numsSize) {
        int j = i + 1;
        while (j < numsSize) {
            if (nums[i] + nums[j] == target) {
                int* returned = malloc(2 * sizeof(int));
                returned[0] = i;
                returned[1] = j;
                *returnSize = 2;
                return returned;
            }
            j++;
        }
        i++;
    }
    *returnSize = 0;
    return NULL;
}

int main(){
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    // int numsSize = 4;
    int *result = twoSum(nums, 4, target, &returnSize);
    printf("[%d, %d]\n", result[0], result[1]);
    free(result);

    return 0;
}