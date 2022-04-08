#include <stdio.h>
#include <queue>
using namespace std;

struct pos1 {
    long long x, y;
};

struct pos2 {
    long long x, y, val, si;
    bool che[43];
};

struct pos1 arr[43];
bool temp[43];
long long res[43];
queue<pos2> que;

int main()
{

    int N, i;
    struct pos1 goal;

    scanf("%d", &N);
    scanf("%lld %lld", &goal.x, &goal.y);

    for (i = 0; i < N; i++) {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
        que.push(pos2{arr[i].x, arr[i].y, 1, i});
        que.back().che[i] = true;
    }

    while (que.front().val <= N && !que.empty()) {
        long long cur_x = que.front().x;
        long long cur_y = que.front().y;
        long long cur_val = que.front().val;
        long long cur_si = que.front().si;

        if (cur_x == goal.x && cur_y == goal.y) {
            res[cur_val]++;
        }

        for (i = cur_si+1; i < N; i++) {
            if (que.front().che[i] == false) {
                que.front().che[i] = true;
                que.push(que.front());
                que.front().che[i] = false;
                que.back().val++;
                que.back().x += arr[i].x;
                que.back().y += arr[i].y;
                que.back().si = i;
            }
        }


        que.pop();
    }

    for (i = 1; i <= N; i++)
        printf("%lld\n", res[i]);
}
