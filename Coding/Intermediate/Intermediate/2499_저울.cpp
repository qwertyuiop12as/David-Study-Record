#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, i;
	long long int sum;
	int arr[1003];

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	if (arr[0] != 1)
	{
		printf("1");
		return 0;
	}

	sum = 1;
	for (i = 1; i < N; i++)
	{
		if (sum + 1 < arr[i])
			break;

		sum += arr[i];
	}

	printf("%lld", sum+1);
}