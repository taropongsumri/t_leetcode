#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* str;
    int groupid;
    struct Anagram* next;
} Anagram;

bool isAnagram(char* str1, char* str2) {
    int count[26] = {0};
    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i] - 'a']++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int i , j , k = 0;
    while (i < strsSize) {
        while() {
            if (isAnagram(strs[i], )) {
                // Add to group
            }
        }
        i++;
    }
}

int main(){
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    size_t strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;
    groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);
    printf("%d\n", *returnColumnSizes);
}