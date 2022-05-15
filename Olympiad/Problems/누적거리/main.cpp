#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<ll, ll> > a(n);
    vector<ll> x(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &a[i].second, &a[i].first);
        x[i] = a[i].first;
    }

    sort(a.begin(), a.end());
    sort(x.begin(), x.end());

    vector<ll> sum_left(n);
    vector<ll> sum_right(n);
    vector<ll> cnt(n);

    cnt[0] = a[0].second;

    for (int i = 1; i < n; ++i) {
        cnt[i] = cnt[i - 1] + a[i].second;
        sum_left[i] = sum_left[i - 1] + cnt[i - 1] * (x[i] - x[i - 1]);
    }

    for (int i = n - 2; i >= 0; --i) {
        sum_right[i] = sum_right[i + 1] + (cnt[n - 1] - cnt[i]) * (x[i + 1] - x[i]);
    }

    for (int i = 0; i < sum_left.size(); i++)
        printf("%lld ", sum_left[i]);

    printf("\n");

    for (int i = 0; i < sum_right.size(); i++)
        printf("%lld ", sum_right[i]);

    printf("\n");

    while (m--) {
        ll q, dist = 0;
        scanf("%lld", &q);
        int idx = lower_bound(x.begin(), x.end(), q) - x.begin();
        if (q < x[0]) {
            dist = sum_right[0] + cnt[n - 1] * (x[0] - q);
        }
        else if (x[n - 1] < q) {
            dist = sum_left[n - 1] + cnt[n - 1] * (q - x[n - 1]);
        }
        else if (x[idx] == q) {
            dist = sum_left[idx] + sum_right[idx];
        }
        else {
            dist = sum_left[idx - 1] + sum_right[idx];
            dist += cnt[idx - 1] * (q - x[idx - 1]);
            dist += (cnt[n - 1] - cnt[idx - 1]) * (x[idx] - q);
        }
        printf("%lld\n", dist);
    }
    return 0;
}
