#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct point {
	int x, y;
	int state;
};

int main()
{
	int T, N, A, B, i;
	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		point a = { 0, 0, 0 }, b = { 0, 0, 0 };

		scanf("%d%d%d", &N, &A, &B);
		unsigned int tmp = N, left = 1, right = N, up = 1, down = N, x, y;
		int state = 0; // À­º¯(0), ¿À¸¥ÂÊº¯(1), ¾Æ·§º¯(2), ¿ÞÂÊº¯(3)

		unsigned long long int sum = 0;
		
		while (A || B)
		{
			sum += tmp;

			switch(state) {
				case 0 :
					x = right;
					y = up;
					up++;
					tmp--;
					break;
				case 1 :
					x = right;
					y = down;
					right--;
					break;
				case 2:
					x = left;
					y = down;
					down--;
					tmp--;
					break;
				case 3:
					x = left;
					y = up;
					left++;
					break;
			}

			if (A && sum >= A)
			{
				switch (state) {
				case 0 :
					a.y = y;
					a.x = right - (sum - A);
					break;
				case 1:
					a.x = x;
					a.y = down - (sum - A);
					break;
				case 2:
					a.y = y;
					a.x = left + (sum - A);
					break;
				case 3:
					a.x = x;
					a.y = up + (sum - A);
					break;
				}
				a.state = state;
				A = 0;
			}

			if (B && sum >= B)
			{
				switch (state) {
				case 0:
					b.y = y;
					b.x = right - (sum - B);
					break;
				case 1:
					b.x = x;
					b.y = down - (sum - B);
					break;
				case 2:
					b.y = y;
					b.x = left + (sum - B);
					break;
				case 3:
					b.x = x;
					b.y = up + (sum - B);
					break;
				}
				b.state = state;
				B = 0;
			}

			//printf("%d %d %d %d %d\n", sum, up, right, down, left);

			state++;
			state %= 4;
		}

		if (abs(a.x - b.x) == abs(a.y - b.y)) {
			printf("YES\n");
			//printf("YES / %d : (%d, %d %d) %d : (%d %d %d)\n", A, a.x, a.y, a.state, B, b.x, b.y, b.state);
		}
		else
			printf("NO\n");
			//printf("NO / %d : (%d, %d %d) %d : (%d %d %d)\n", A, a.x, a.y, a.state, B, b.x, b.y, b.state);
	}

}