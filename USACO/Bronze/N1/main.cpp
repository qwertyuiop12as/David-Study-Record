#include <stdio.h>
using namespace std;

struct nu {
    long long le = 0, ri = 0, num = 0;
};

struct nu arr[400003];
long long res, s, sum1, left;
bool che = true;

void it(long long pos) {
    if (arr[pos].le == 0 && arr[pos].ri == 0)
        return;

    else if (arr[pos].num < res - s) {
        if (left == 0)
            left = arr[pos].le;
        s += arr[pos].num;
    }

    else if (arr[pos].num == res - s) {
        if (left == 0)
            sum1 += arr[pos].ri - arr[pos].le;
        else
            sum1 += arr[pos].ri - left;
        s = 0;
        left = 0;
    }

    else if (arr[pos].le == arr[pos].ri) {
        if (arr[pos].num + s > res) {
            che = false;
        }

        return;
    }

    else {
        it(pos * 2);
        it(pos*2 + 1);
    }
}

int main()
{
    long long T, i, j, k;


    scanf("%lld", &T);
    for (i = 1; i <= T; i++) {
        long long N, ma = 0, sum = 0, st = 1;
        scanf("%lld", &N);

        while (st < N)
            st *= 2;

        long long num;
        for (j = 0; j < N; j++) {
            scanf("%lld", &num);

            k = st + j;
            while (k > 0) {
                arr[k].num += num;
                arr[k].ri = st + j;

                if (arr[k].le == 0)
                    arr[k].le = st +j;

                k /= 2;
            }

            sum += num;

            if (ma < num)
                ma = num;
        }


        long long ans = 999999999;

        if (ma > 0) {
            for (j = ma; j <= sum; j++) {
                if (sum % j == 0) {
                    che = true;
                    s = 0;
                    res = j;
                    sum1 = 0;
                    left = st;
                    it(1);

                    if (che == true && sum1 < ans)
                        ans = sum1;
                }
            }
        }

        if (ans == 999999999)
            ans = 0;

        printf("%lld\n", ans);

        for (j = 0; j <= st*2; j++) {
            arr[j].num = 0;
            arr[j].le = 0;
            arr[j].ri = 0;
        }
    }
}
