#include <stdio.h>
#include <string.h>

void stringMatchBruteForce(char *text, char *pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int found = 0;

    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (text[i+j] != pattern[j])
                break;

        if (j == M) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found in the text.\n");
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

   
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    stringMatchBruteForce(text, pattern);

    return 0;
}
