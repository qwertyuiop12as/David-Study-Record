```c++
#include <stdio.h>
#include <algorithm>
using namespace std;

long long int dp[33][103];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int S, N, K, D, i, j;
    scanf("%d %d", &S, &N);

    for (i = 1; i <= N; i++) {
        scanf("%d %d", &K, &D);
        for (j = 1; j <= S; j++) {
            if (j >= K)
                dp[i][j] = max(dp[i-1][j], D + dp[i-1][j-K]);

            else
                dp[i][j] = dp[i-1][j];
        }
    }

    /*for (i = 0; i <= N; i++) {
        for (j = 0; j <= S; j++)
            printf("%d ", dp[i][j]);

        printf("\n");
    }*/

    long long int maxn = dp[N][0];
    for (i = 1; i <= S; i++)
        maxn = max(dp[N][i], maxn);

    printf("%lld", maxn);
}
```

Dynamic Programming "Knapsack";