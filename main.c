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

void decrypt(void) {
    char encrypted[1000];
    char key[1000];
    char newline;

    assert(2 == scanf("%1000[^\n]%c", encrypted, &newline));
    assert(1 == scanf("%1000[^\n]", key));

    int num, res;
    int i = 0;
    int key_len = strlen(key);
    while (res = sscanf(encrypted + 3 * i, "%3d", &num),
           res == 1 && num != -1) {
        char decrypted = (char)num ^ key[i % key_len];
        putchar(decrypted);
        i += 1;
    }
}

int main(int argc, char** argv) {
    assert(argc >= 2);
    if (strcmp(argv[1], "-e") == 0) {
        encrypt();
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt();
    } else {
        assert(0);
    }
    return 0;
}
