#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

struct date {
	int month, day;
};

struct flower {
	date start, end;
};
flower list[100003];

int is_fine(const date &my, const date &other)
{
	if (my.month == other.month)
	{
		if (other.day == my.day)
			return 0;
		return (my.day > other.day) ? 1 : -1;
	}

	return (my.month > other.month) ? 1 : -1;
}

bool compare_date(const date &a, const date &b)
{
	return a.month < b.month || (a.month == b.month && a.day < b.day);
}

bool cmp(const flower &a, const flower &b) 
{
	date a_end = a.end, b_end = b.end;

	return a_end.month > b_end.month || (a_end.month == b_end.month && a_end.day > b_end.day);
}

int main()
{
	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d%d%d%d", &list[i].start.month, &list[i].start.day, &list[i].end.month, &list[i].end.day);

	sort(list, list + N, cmp);
	//reverse(list, list + N);

	/*printf("\n-------------------------------------\n");
	for (i = 0; i < N; i++)
		printf("%2d %2d %2d %2d\n", list[i].start.month, list[i].start.day, list[i].end.month, list[i].end.day);
	printf("-------------------------------------\n");*/

	int cnt = 0, idx = 0, last = N-1, k = 0;
	date st, cur;
	cur = { 3, 1 };

	while (is_fine(cur, {11, 31}) != 1)
	{
		if (last == 0)
		{
			printf("0");
			return 0;
		}

		idx = 0;
		while (is_fine(cur, list[idx].start) == -1 && idx != last)
		{
			idx++;
		}

		cur = list[idx].end;
		cnt++;
		last = idx;
		//printf("idx : %d cur : (%d, %d)\n", idx, cur.month, cur.day);
		k++;
	}

	printf("%d\n", cnt);

	return 0;
}