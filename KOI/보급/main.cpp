#include <stdio.h>
#include <algorithm>
using namespace std;

struct date{
    long long int st, en, idx;
} range[103];

struct pt {
    long long int x, y, start_day, end_day;
} mil[103];

long long int comp[2][103]; // comp[0][i]에는 i번보다 작은 애들 갯수, comp[1][i]에는 i번보다 큰 애들 갯수
long long int result[103];
bool token = true;

bool cmp(const date a, const date b)
{
    return a.en > b.en || (a.en == b.en && a.st > b.st);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, i, j;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%lld%lld%lld%lld", &mil[i].x, &mil[i].y, &mil[i].start_day, &mil[i].end_day);

    for (i = 0; i < N-1; i++)
    {
        for (j = i+1; j < N; j++)
        {
            if (mil[i].x > mil[j].x && mil[i].y > mil[j].y)
            {
                comp[0][i]++;
                comp[1][j]++;
            }

            else if (mil[i].x < mil[j].x && mil[i].y < mil[j].y)
            {
                comp[1][i]++;
                comp[0][j]++;
            }
        }
    }

    for (i = 0; i < N; i++) {
        range[i].st = max(comp[0][i] + 1, mil[i].start_day);
        range[i].en = min(N - comp[1][i], mil[i].end_day);
        range[i].idx = i+1;
        printf("(%lld, %lld) / %lld ~ %lld\n", comp[0][i], comp[1][i], range[i].st, range[i].en);
    }

    sort(range, range+N, cmp);

    for (i = 0; i < N; i++) {
        printf("%lld %lld(%lld) / x : %lld, y : %lld\n", range[i].st, range[i].en, range[i].idx, mil[range[i].idx-1].x, mil[range[i].idx-1].y);
    }

    for (int da = N; da >= 1; da--)
    {
        if (range[N-da].st <= da && range[N-da].en >= da)
            result[range[N-da].idx] = da;
        else {
            token = false;
            da = 0;
        }
    }

    if (token == true)
    {
        for (i = 1; i <= N; i++)
            printf("%lld ", result[i]);
    }
    else if (token == false)
        printf("-1\n");
}
