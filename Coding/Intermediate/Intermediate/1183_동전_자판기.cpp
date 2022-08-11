#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int money[10] = { 500, 100, 50, 10, 5, 1 };
int res[10];
int main()
{
	int n, sum = 0, cnt = 0;
	int arr[10];
	
	scanf("%d", &n);
	
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i] * money[i];
	}

	sum -= n;

	for (int i = 0; i < 6; i++)
	{
		res[i] = min((sum / money[i]), arr[i]);
		cnt += arr[i] - min((sum / money[i]), arr[i]);
		sum -= money[i] * min((sum / money[i]), arr[i]);
	}

	printf("%d\n", cnt);

	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i] - res[i]);

	return 0;
}