#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left]))  left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    // Remove newline character if present
    s[strcspn(s, "\n")] = 0;

    if (isPalindrome(s)) {
        printf("\"%s\" is a palindrome.\n", s);
    } else {
        printf("\"%s\" is not a palindrome.\n", s);
    }
    return 0;
}