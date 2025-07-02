#include <stdio.h>
#include <string.h>

#define MAX 14

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    char word[MAX + 1];
    int freq[256] = {0};

    scanf("%s", word);
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        freq[(unsigned char)word[i]]++;
    }

    unsigned long long totalAnagrams = factorial(length);

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            totalAnagrams /= factorial(freq[i]);
        }
    }

    printf("%llu\n", totalAnagrams);
    return 0;
}
