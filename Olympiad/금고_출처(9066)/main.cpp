#include <stdio.h>
#include <algorithm>
using namespace std;

bool arr[21][21];
bool arr2[21][21];

int N;
void change(int x, int y) {
    for (int idx = 0; idx < N; idx++) {
        arr2[x][idx] = !arr2[x][idx];
        arr2[idx][y] = !arr2[idx][y];
    }
}

bool check() {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if (arr2[x][y] == false)
                return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, i, j, i1, j1;
    //scanf("%d", &T);

    scanf("%d", &N);
    char ch;
    for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
        scanf("%c", &ch);
        if (ch == 'H')
            arr[i][j] = true;
        else
            arr[i][j] = false;
    }

    int res = -1;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int cnt = 0;

            for (i1 = 0; i1 < N; i1++)
                for (j1 = 0; j1 < N; j1++)
                    arr2[i1][j1] = arr[i1][j1];

            for (i1 = i; i1 < N; i1++) {
                for (j1 = j; j1 < N; j1++) {
                    if (arr2[i1][j1] == false) {
                        change(i1, j1);
                        cnt++;
                    }
                }
            }

            if (i == 1 && j == 1) {
                for (i1 = 0; i1 < N; i1++) {
                    for (j1 = 0; j1 < N; j1++)
                        printf("%i ", arr2[i1][j1]);
                    printf("\n");
                }
            }

            if (check() == true)
                if (res == -1)
                    res = cnt;
                else
                    res = min(res, cnt);

        }
    }

    printf("%d", res);
}
