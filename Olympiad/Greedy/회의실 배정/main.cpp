#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > arr;

bool cmp(const pair<int, int> a, const pair<int, int> b) {
    return a.second < b.second;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, x, y;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("\n%d %d", &x, &y);
        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end(), cmp);


    int cur_end = arr[0].second, cnt = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (cur_end <= arr[i].first) {
            cur_end = arr[i].second;
            cnt++;
        }
    }

    printf("%d\n", cnt);
}
