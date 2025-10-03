#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXW 5000
#define MAXL 201

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void addWord(char *w, char **dict, int *cnt) {
    for (int i = 0; w[i]; i++) {
        w[i] = tolower(w[i]);
    }
    
    for (int i = 0; i < *cnt; i++) {
        if (strcmp(dict[i], w) == 0) {
            return;
        }
    }
    
    dict[*cnt] = strdup(w);
    (*cnt)++;
}

int main() {
    char *dict[MAXW];
    int cnt = 0;
    char line[MAXL];
    char w[MAXL];
    
    while (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line);
        int j = 0;

        for (int i = 0; i <= len; i++) {
            if (isalpha(line[i])) {
                w[j++] = line[i];
            } else {
                if (j > 0) {
                    w[j] = '\0';
                    addWord(w, dict, &cnt);
                    j = 0;
                }
            }
        }
    }
    
    qsort(dict, cnt, sizeof(char *), cmp);
    
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", dict[i]);
        free(dict[i]);
    }
    
    return 0;
}
