#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

struct line {
	long start, end;
};

bool cmp(const line &a, const line &b)
{
	return a.start < b.start;
}

line arr[1000003];
int main()
{
	long cur_low, cur_high, sum = 0;
	int i, N;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%ld%ld", &arr[i].start, &arr[i].end);

	sort(arr + 0, arr + N, cmp);

	cur_low = (arr + 0)->start;
	cur_high = (arr + 0)->end;

	for (i = 1; i < N; i++)
	{
		if (cur_high >= arr[i].start)
		{
			if (arr[i].end > cur_high)
				cur_high = arr[i].end;
		}

		else
		{
			sum += cur_high - cur_low;
			cur_low = (arr + i)->start;
			cur_high = (arr + i)->end;
		}
	}

	sum += cur_high - cur_low;

	printf("%ld", sum);
	return 0;
}