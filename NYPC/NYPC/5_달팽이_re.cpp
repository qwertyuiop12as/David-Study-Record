#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <math.h>

struct point {
	unsigned long long x, y;
};

point idx(unsigned long long int cur_size, unsigned long long int sum, unsigned long long int num);
unsigned long long abs(unsigned long long a, unsigned long long b);
unsigned long long N, left, right, up, down;

int main()
{
	int T, i;
	unsigned long long int A, B;
	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		point a = { 0, 0 }, b = { 0, 0 };
		bool done_a, done_b;
		done_a = done_b = false;

		scanf("%llu%llu%llu", &N, &A, &B);

		up = left = 1;
		down = right = N;

		unsigned long long int tmp = N-1;
		unsigned long long int sum = 0;

		if (N % 2 == 1)
		{
			if (A == N * N)
			{
				done_a = true;
				a = { (N + 1) / 2, (N + 1) / 2 };
			}
			if (B == N * N)
			{
				done_b = true;
				b = { (N + 1) / 2, (N + 1) / 2 };
			}
		}

		while (!done_b || !done_a)
		{
			sum += 4 * (tmp);

			if (done_a == false && sum >= A)
			{
				a = idx(tmp, sum, A);
				//a.state = state; // 체크용
				done_a = true;
			}

			if (done_b == false && sum >= B)
			{
				b = idx(tmp, sum, B);
				//b.state = state; // 체크용
				done_b = true;
			}

			tmp -= 2;
			up++;
			left++;
			down--;
			right--;
		}

		//printf("%d : (%d, %d)\n%d : (%d, %d)\n", A, a.x, a.y, B, b.x, b.y);

		if (abs(a.x, b.x) == abs(a.y, b.y)) {
			printf("YES\n");
			//printf("YES / %d : (%d, %d %d) %d : (%d %d %d)\n", A, a.x, a.y, a.state, B, b.x, b.y, b.state);
		}
		else
			printf("NO\n");
		//printf("NO / %d : (%d, %d %d) %d : (%d %d %d)\n", A, a.x, a.y, a.state, B, b.x, b.y, b.state);
	}
}

point idx(unsigned long long int cur_size, unsigned long long int sum, unsigned long long int num)
{
	unsigned long long int i = 1, gap;

	sum -= cur_size;

	for (i; i < 4 && sum >= num; i++)
		sum -= cur_size;

	gap = num - sum;

	switch(i) {
	case 1 :
		return { left, down-gap+1 };
	case 2 :
		return { right-gap+1, down };
	case 3 :
		return { right, up+gap-1 };
	case 4 :
		return { left+gap-1, up };

	}
}

unsigned long long abs(unsigned long long a, unsigned long long b)
{
	return (a > b) ? (a - b) : (b - a);
}