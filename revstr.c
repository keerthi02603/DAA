#include <stdio.h>
#include <string.h>

void reverseSubstring(char *superstring, int start, int length) {
    char substring[length + 1];
    strncpy(substring, &superstring[start], length);
    substring[length] = '\0';  
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = substring[i];
        substring[i] = substring[j];
        substring[j] = temp;
    }

   
    strncpy(&superstring[start], substring, length);
}

int main() {
    char superstring[] = "hello,keerthi!";
    int start = 7;  // Starting index of the substring
    int length = 5; // Length of the substring to reverse

    printf("Original superstring: %s\n", superstring);
    reverseSubstring(superstring, start, length);
    printf("Modified superstring: %s\n", superstring);

    return 0;
}
