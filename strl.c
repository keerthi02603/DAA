#include <stdio.h>
#include <string.h>


int count_substring_occurrences(const char *superstring, const char *substring) {
    int count = 0;
    int sub_len = strlen(substring);
    int super_len = strlen(superstring);
    
    for (int i = 0; i <= super_len - sub_len; i++) {
        int j;
        for (j = 0; j < sub_len; j++) {
            if (superstring[i + j] != substring[j]) {
                break;
            }
        }
        if (j == sub_len) {
            count++;
        }
    }
    return count;
}

int main() {
    const char *superstring = "ammuammuammuaaaammu";
    const char *substring = "ammu";
    int occurrences = count_substring_occurrences(superstring, substring);
    printf("Number of occurrences: %d\n", occurrences);
    return 0;
}
