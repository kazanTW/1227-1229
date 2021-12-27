#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(void) {
    char encrypted[1000];
    char key[1000];
    char newline;

    assert(2 == scanf("%1000[^\n]%c", encrypted, &newline));
    assert(1 == scanf("%1000[^\n]", key));

    int num, res;
    int i = 0;
    int key_len = strlen(key);

    while(res = sscanf(encrypted + 3 * i, "%3d", &num),
          res == 1 && num != -1) {
        char decrypted = (char)num ^ key[i % key_len];
        putchar(decrypted);
        i += 1;
    }
    putchar('\n');
    
}

int main(int argc, char** argv) {
    decrypt();

    return 0;
}