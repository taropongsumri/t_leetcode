#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct a_struct{
    char* str;
    int groupid;
    struct a_struct * next;
} Anagram;

static int compareChars(const void* a, const void* b) {
    unsigned char ca = *(const unsigned char*)a;
    unsigned char cb = *(const unsigned char*)b;
    return (ca > cb) - (ca < cb);
}

static char* canonicalKey(const char* s) {
    size_t len = strlen(s);
    char* key = malloc((len + 1) * sizeof(char));
    if (key == NULL) {
        return NULL;
    }

    memcpy(key, s, len + 1);
    qsort(key, len, sizeof(char), compareChars);
    return key;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (returnSize == NULL || returnColumnSizes == NULL) {
        return NULL;
    }

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (strs == NULL || strsSize <= 0) {
        return NULL;
    }

    char*** groups = malloc((size_t)strsSize * sizeof(char**));
    char** groupKeys = calloc((size_t)strsSize, sizeof(char*));
    int* sizes = malloc((size_t)strsSize * sizeof(int));
    if (groups == NULL || groupKeys == NULL || sizes == NULL) {
        free(groups);
        free(groupKeys);
        free(sizes);
        return NULL;
    }

    for (int i = 0; i < strsSize; i++) {
        char* key = canonicalKey(strs[i]);
        if (key == NULL) {
            for (int j = 0; j < *returnSize; j++) {
                free(groupKeys[j]);
            }
            free(groupKeys);
            free(sizes);
            for (int j = 0; j < *returnSize; j++) {
                free(groups[j]);
            }
            free(groups);
            return NULL;
        }

        int found = -1;
        for (int g = 0; g < *returnSize; g++) {
            if (strcmp(groupKeys[g], key) == 0) {
                found = g;
                break;
            }
        }

        if (found == -1) {
            groups[*returnSize] = malloc(sizeof(char*));
            if (groups[*returnSize] == NULL) {
                free(key);
                for (int j = 0; j < *returnSize; j++) {
                    free(groupKeys[j]);
                }
                free(groupKeys);
                free(sizes);
                for (int j = 0; j < *returnSize; j++) {
                    free(groups[j]);
                }
                free(groups);
                return NULL;
            }

            groups[*returnSize][0] = strs[i];
            groupKeys[*returnSize] = key;
            sizes[*returnSize] = 1;
            (*returnSize)++;
        } else {
            groups[found] = realloc(groups[found], (size_t)(sizes[found] + 1) * sizeof(char*));
            if (groups[found] == NULL) {
                free(key);
                for (int j = 0; j < *returnSize; j++) {
                    free(groupKeys[j]);
                }
                free(groupKeys);
                free(sizes);
                for (int j = 0; j < *returnSize; j++) {
                    free(groups[j]);
                }
                free(groups);
                return NULL;
            }
            groups[found][sizes[found]] = strs[i];
            sizes[found]++;
            free(key);
        }
    }

    *returnColumnSizes = malloc((size_t)(*returnSize) * sizeof(int));
    if (*returnColumnSizes == NULL) {
        for (int i = 0; i < *returnSize; i++) {
            free(groupKeys[i]);
        }
        free(groupKeys);
        free(sizes);
        for (int i = 0; i < *returnSize; i++) {
            free(groups[i]);
        }
        free(groups);
        return NULL;
    }

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = sizes[i];
    }

    for (int i = 0; i < *returnSize; i++) {
        free(groupKeys[i]);
    }
    free(groupKeys);
    free(sizes);
    return groups;
}

int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    if (result == NULL) {
        printf("No groups produced\n");
        return 0;
    }

    for (int i = 0; i < returnSize; i++) {
        printf("Group %d: ", i);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}