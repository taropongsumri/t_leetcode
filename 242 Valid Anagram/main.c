#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
    
}

int main() {
    char s[] = "a";
    char t[] = "ab";
    int *array = malloc(ft_strlen(s) * sizeof(int));
    int i = 0;

    while (s[i] != '\0') {
        array[i] = s[i];
        i++;
    }
    while(array[i]) {
        printf("%d\n", array[i]);
        i++;
    }
    return 0;
}