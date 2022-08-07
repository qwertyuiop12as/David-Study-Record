// #define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100003];

bool compare(int &x, int &y)
{
	return x > y;
}

int main()
{
	int N, i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	/*sort(arr + 0, arr + N);
	reverse(arr, arr + N);*/

	sort(arr, arr + N, compare);

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
}