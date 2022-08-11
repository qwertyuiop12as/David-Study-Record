#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

struct milk {
	int price, amount;
};

milk list[10002];
int min_price[10002];

int main()
{
	int N, S, p, a;
	long long int sum = 0;
	scanf("%d%d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &list[i].price, &list[i].amount);
		
		if (i == 0)
		{
			sum += list[i].amount * list[i].price;
			continue;
		}

		list[i].price = min(list[i - 1].price + S, list[i].price);
		sum += list[i].amount * list[i].price;
	}

	printf("%lld\n", sum);
}