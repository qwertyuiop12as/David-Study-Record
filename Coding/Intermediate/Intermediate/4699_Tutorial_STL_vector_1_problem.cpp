#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> arr;
	vector<int> order;
	int n;
	scanf("%d", &n);

	arr.resize(n);
	order.resize(n);

	for (int i = 0; i < n; i++)
	{
		int size;
		scanf("%d", &size);
		arr[i].resize(size);

		for (int &element : arr[i])
			scanf("%d", &element);
	}

	for (int &element : order)
		scanf("%d", &element);

	for (int i = 0; i < n; i++)
	{
		for (int element : arr[order[i]])
			printf("%d ", element);
		printf("\n");
	}
	return 0;
}