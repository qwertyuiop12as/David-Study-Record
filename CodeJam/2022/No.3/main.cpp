#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    printf("AA\n");

    int T;
    scanf("%d", &T);

    printf("AA\n");

    for (int i = 1; i <= T; i++) {
        printf("AA\n");
        int N;
        scanf("%d", &N);

        int val, max_val = 0;
        int arr_idx[20] = {0, };

        for (int idx = 0; idx < N; idx++) {
            scanf("%d", &val);
            arr_idx[val]++;
            max_val = max(val, max_val);
        }

        int cur = 0;
        for (int j = 1; j <= max_val; j++) {
            if (j <= cur)
                continue;
            cur += min(arr_idx[j], j - cur);
            // j = cur;
        }

        printf("%d\n", cur);

    }
}
