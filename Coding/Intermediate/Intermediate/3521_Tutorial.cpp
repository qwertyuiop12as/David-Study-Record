#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[10];
int main()
{
	int N, i, cur = 32, cnt = 0;
	
	for (i = 1; i <= 5; i++)
		scanf("%d", &num[i]);

	scanf("%d", &N);

	for (i = 5; i >= 1; i--)
	{
		cur /= 2;

		if (N < cur)
			continue;

		if (N >= cur * num[i])
		{
			N -= cur * num[i];
			cnt += num[i];
		}

		else
		{
			int n = N / cur;
			N -= cur * n;
			cnt += n;
		}

		if (N == 0)
			break;

		//printf("%d %d %d\n", N, cur, cnt);

	}

	if (N == 0)
		printf("%d", cnt);
	else
		printf("impossible");

	return 0;
}