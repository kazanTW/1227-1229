#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(void) {
    char plain[1000];
    char key[1000];
    char newline;

    assert(2 == scanf("%1000[^\n]%c", plain, &newline));
    assert(1 == scanf("%1000[^\n]", key));

    int plain_len = strlen(plain);
    int key_len = strlen(key);
    for (int i = 0; i < plain_len; i += 1) {
        int encrypted = plain[i] ^ key[i % key_len];
        printf("%03d", encrypted);
    }
    printf("-01\n");
}


int main(int argc, char** argv) {
    encrypt();

    return 0;
}