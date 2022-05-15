#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char in[2000];
int arr[2003][2003];

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", &in);
        for (int j = 0; j < strlen(in); j++)
            arr[i][j] = in[j]-'0';
    }

    int res = 0;
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            int tmp = 0;
            if (j > 0)
            {
                tmp = arr[i][j-1];

                if (i > 0)
                    tmp = max(tmp, arr[i-1][j-1]);
                if (i < N-1)
                    tmp = max(tmp, arr[i+1][j-1]);
                arr[i][j] += tmp;
            }
            res = max(tmp, res);
        }
    }


    printf("%d\n", res);
    return 0;
}
