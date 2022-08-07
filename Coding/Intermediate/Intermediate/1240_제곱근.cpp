#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long long find_sq(unsigned long long start, unsigned long long end, unsigned long long key);
int main()
{
	unsigned long long N;
	scanf("%llu", &N);

	printf("%llu", find_sq(1, N, N));
}

unsigned long long find_sq(unsigned long long start, unsigned long long end, unsigned long long key)
{
	unsigned long long mid = (start + end) / 2;
	
	if (mid > 3100000000)
		return find_sq(start, mid-1, key);

	if (mid * mid <= key && (mid+1) * (mid+1) > key)
		return mid;

	if (mid * mid > key)
		return find_sq(start, mid-1, key);

	if (mid * mid < key)
		return find_sq(mid+1, end, key);
}