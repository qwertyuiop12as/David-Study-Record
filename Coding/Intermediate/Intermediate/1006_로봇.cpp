#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct pos {
	int x, y, dir;
};

pos st, en;
queue<pos> que;

int map[103][103];
int M, N;

int main()
{
	int i, j;

	scanf("%d%d", &M, &N);
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	scanf("%d%d%d", &st.x, &st.y, &st.dir);
	scanf("%d%d%d", &en.x, &en.y, &en.dir);

}