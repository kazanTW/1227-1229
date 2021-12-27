#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
    int mask[4];
    int ip[4];
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    int net[4];
    for(int i = 0; i < 4; i++) {
        net[i] = mask[i] & ip[i];
    }

    printf("%d.%d.%d.%d\n", net[0], net[1], net[2], net[3]);

    return 0;
}