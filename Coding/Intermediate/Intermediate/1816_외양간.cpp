#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int nums[210], gaps[210];

int main()
{
	int i;
	int M, S, C, res = 0;

	scanf("%d%d%d", &M, &S, &C);

	for (i = 0; i < C; i++)
		scanf("%d", &nums[i]);

	sort(nums, nums + C);

	for (i = 1; i < C; i++)
		gaps[i - 1] = nums[i] - nums[i - 1];

	sort(gaps, gaps + C - 1);
	reverse(gaps, gaps + C - 1);

	res = nums[C - 1] - nums[0] + 1;

	for (i = 0; i < min(M - 1, C-1); i++)
		res -= gaps[i] - 1;

	printf("%d", res);
}