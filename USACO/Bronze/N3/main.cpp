#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int alpha[4][30];
int che[30];
bool used[10], is_make, fi;
char str[10];

void DFS(int cnt) {
    if (cnt == strlen(str)) {
        is_make = true;
        for (int i = 0; i < 26; i++)
            if (che[i] > 0)
                is_make = false;

        if (is_make == true)
            fi = true;
    }
    for (int i = 0; i < 26; i++) {
        if (che[i] >= 1) {
            for (int j = 0; j < 4; j++) {
                if (used[j] == false && alpha[j][i] > 0) {
                    alpha[j][i]--;
                    che[i]--;
                    used[j] = true;


                    DFS(cnt+1);

                    alpha[j][i]++;
                    che[i]++;
                    used[j] = false;
                }
            }
        }
    }
}

int main()
{

    int N, i, j;

    scanf("%d", &N);

    for (i = 0; i < 4; i++) {
        scanf("%s", str);
        for (j = 0; j < 6; j++)
            alpha[i][str[j]-'A'] = 1;
    }


    for (i = 0; i < N; i++) {
        for (j = 0; j < 26; j++)
            che[j] = 0;
        for (j = 0; j < 10; j++)
            used[j] = false;

        scanf("%s", str);

        for (j = 0; j < strlen(str); j++)
            che[str[j]-'A']++;

        fi = false;
        DFS(0);

        if (fi == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
