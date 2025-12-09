#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat_strings(char *s1, char *s2);

int main() {
    char temp[500];

    printf("Enter First Message: ");
    fgets(temp, 500, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    char *str1 = (char *)malloc(strlen(temp) + 1);
    if (str1 == NULL) {
        printf("Memory Allocation Failed.\n");
        return 1;
    }
    strcpy(str1, temp);

    printf("Enter Second Message: ");
    fgets(temp, 500, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    char *str2 = (char *)malloc(strlen(temp) + 1);
    if (str2 == NULL) {
        printf("Memory Allocation Failed.\n");
        free(str1);
        return 1;
    }
    strcpy(str2, temp);

    char *combined = concat_strings(str1, str2);
    if (combined == NULL) {
        free(str1);
        free(str2);
        return 1;
    }

    printf("First concatenation: %s\n", combined);

    while (1) {
        printf("Enter another message to add (Q to quit): ");
        fgets(temp, 500, stdin);
        temp[strcspn(temp, "\n")] = '\0';

        if (strcmp(temp, "Q") == 0)break;

        int oldLen = strlen(combined);
        int addLen = strlen(temp);
        char *newCombined = (char *)realloc(combined, oldLen + addLen + 1);
        if (newCombined == NULL) {
            printf("Memory Reallocation Failed.\n");
            free(combined);
            free(str1);
            free(str2);
            return 1;
        }
        combined = newCombined;
        strcat(combined, temp);
    }
    printf("Final concatenated message: %s\n", combined);
    free(str1);
    free(str2);
    free(combined);
    return 0;
}

char *concat_strings(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
