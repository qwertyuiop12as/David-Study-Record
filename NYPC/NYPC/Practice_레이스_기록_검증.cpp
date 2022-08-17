#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;

struct time {
	int start, end;
	bool is_running;
};

time li[200];


int main()
{
	int N, M, i;
	scanf("%d%d", &N, &M);

	for (i = 1; i <= N; i++)
		li[i].is_running = false;

	int t, idx, state;
	for (i = 0; i < M; i++)
	{
		scanf("%d%d%d", &t, &idx, &state);
		if (state == 1)
		{
			if (li[idx].is_running == false || t - li[idx].start <= 59)
			{
				printf("NO");
				return 0;
			}

			li[idx].is_running = false;
			li[idx].end = t;
		}

		if (state == 0)
		{
			if (li[idx].is_running == true || li[idx].end > t)
			{
				printf("NO");
				return 0;
			}

			li[idx].start = t;
			li[idx].is_running = true;
		}
	}

	for (i = 1; i <= N; i++)
		if (li[i].is_running == true)
		{
			printf("NO");
			return 0;
		}
			

	printf("YES");

	return 0;
}