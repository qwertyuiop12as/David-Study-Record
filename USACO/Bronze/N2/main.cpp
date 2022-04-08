#include <stdio.h>


int pos[2][100003];
int ne[100003];
int ne2[100003];
int main()
{
    int N, i, j, num;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &num);
        pos[0][num] = i;
        pos[1][i] = num;
    }

    for (i = 1; i <= N; i++) {
        scanf("%d", &num);
        ne[pos[0][num]] = i;
        ne2[pos[0][num]] = i;
    }

    for (i = 2; i <= N; i++)
        if (ne[i-1] > ne[i]) {
            ne[i] = ne[i-1];
        }

    long long cnt = 0;
    for (i = 1; i <= N; i++)
        if (ne[i] > ne2[i])
            cnt++;

    printf("%d", cnt);

    return 0;
}
