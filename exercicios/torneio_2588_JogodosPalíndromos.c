#include <stdio.h>
#include <string.h>

int main() {
    char string[1010];
    
    while (scanf("%s", string) != EOF) {
        int freq[256] = {0}; 
        
        for (int i = 0; string[i]; i++)
            freq[string[i]]++;
        
        int ans = 0;
        for (int i = 0; i < 256; i++) {
            if (freq[i] % 2 != 0)
                ans++;
        }
        
        printf("%d\n", ans <= 1 ? 0 : ans - 1);
    }

    return 0;
}
