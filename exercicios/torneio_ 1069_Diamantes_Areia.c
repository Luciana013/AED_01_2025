#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char solo[1010];
        scanf("%s", solo);
        int diamante = 0;
        for (int i = 0; solo[i] != '\0'; i++) {
            if (solo[i] == '<') {
                for (int j = i; solo[j] != '\0'; j++) {
                    if (solo[j] == '>') {
                        diamante++;
                        solo[j] = '0';
                        break;
                    }
                }
            }
        }
        printf("%d\n", diamante);
    }
    return 0;
}
