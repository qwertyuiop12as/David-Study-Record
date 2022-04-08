#include <stdio.h>
#include <algorithm>
#define MAX 9999999999999999
using namespace std;

struct pos {
    int x, y;
};

bool cmp_x (const pos a, const pos b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y (const pos a, const pos b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T, N, i, j;
    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d", &N);
        struct pos arr1[N], arr2[N];

        for (j = 0; j < N; j++) {
            scanf("%d %d", &arr1[j].x, &arr1[j].y);
            arr2[j].x = arr1[j].x;
            arr2[j].y = arr1[j].y;
        }

        sort(arr1, arr1 + N, cmp_x);
        sort(arr2, arr2 + N, cmp_y);

        long long res[60003][2];

        int cnt = 0, height = 0, width = 0, low = arr1[0].y, high = arr1[0].y, idx = -1;
        while (cnt < N && arr1[cnt].x < arr1[N-1].x) {
            int key = cnt;
            while (arr1[key].x == arr1[cnt].x && arr1[cnt].x < arr1[N-1].x) {
                if (high < arr1[cnt].y)
                    high = arr1[cnt].y;

                if (low > arr1[cnt].y)
                    low = arr1[cnt].y;

                cnt++;

                if (cnt > N)
                    break;
            }

            width = arr1[key].x - arr1[0].x;
            height = high - low;
            res[++idx][0] = width * height;
        }

        cnt = N-1; height = 0; width = 0; low = arr1[N-1].y; high = arr1[N-1].y;
        int che = 0;

        while (cnt > 0 && arr1[cnt].x > arr1[0].x) {
            int key = cnt;
            while (arr1[key].x == arr1[cnt].x && arr1[cnt].x > arr1[0].x) {
                if (high < arr1[cnt].y)
                    high = arr1[cnt].y;

                if (low > arr1[cnt].y)
                    low = arr1[cnt].y;

                cnt--;

                if (cnt < 0)
                    break;
            }

            width = arr1[N-1].x - arr1[key].x;
            height = high - low;
            res[idx-che][1] = width * height;
            che++;
        }

        long long answer = max(res[0][0], res[0][1]);
        for (i = 1; i <= idx; i++) {
            long long large = max(res[i][0], res[i][1]);
            if (large < answer)
                answer = large;
        }
        printf("%lld", answer);
    }
}
