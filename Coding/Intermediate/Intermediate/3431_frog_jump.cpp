#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int group_num[100003];

struct log {
	int st, en, no;
	bool operator<(const log &other)
	{
		return st < other.st;
	}
} list[100003];

int main()
{
	int N, Q, i;
	scanf("%d%d", &N, &Q);

	int x1, x2, y;
	for (i = 1; i <= N; i++)
	{
		scanf("%d%d%d", &x1, &x2, &y);
		list[i] = { x1, x2, i };
	}

	sort(list + 1, list + N + 1);

	/*for (i = 1; i <= N; i++)
	{
		printf("%d %d %d\n", list[i].st, list[i].en, list[i].no);
	}*/

	int cur_group = 1, cur_en = list[1].en;
	group_num[list[1].no] = 1;
	for (i = 2; i <= N; i++)
	{
		if (list[i].st <= cur_en)
		{
			cur_en = max(cur_en, list[i].en);
			group_num[list[i].no] = cur_group;
		}

		else
		{
			cur_group++;
			cur_en = list[i].en;
			group_num[list[i].no] = cur_group;
		}
	}

	for (i = 1; i <= Q; i++)
	{
		int x1, x2;
		scanf("%d%d", &x1, &x2);

		if (group_num[x1] == group_num[x2])
			printf("1\n");
		else
			printf("0\n")
	}

	return 0;
}