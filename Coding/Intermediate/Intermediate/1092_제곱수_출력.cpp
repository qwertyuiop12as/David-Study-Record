#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int calc(int a, int n);

int main()
{
	int X, Y;
	scanf("%d%d", &X, &Y);

	printf("%lld", calc(X % 20091024, Y));
}


long long int calc(int a, int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return a;

	long long int res = calc(a, n / 2);
	long long int ans = (res * res) % 20091024;

	if (n % 2 == 1)
		return (ans * a) % 20091024;

	else
		return ans;
}