#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, x, a;
	char o;

	scanf("%d%d", &n, &x);
	vector<int> arr(n, x);

	scanf("%c", &o);
	while (o != 'e')
	{
		switch (o)
		{
			case 'i':
				scanf("%d", &a);
				arr.push_back(a);
				break;
			case 'r':
				if (!arr.empty())
					arr.pop_back();
				break;
			case 's':
				if (!arr.empty())
					sort(arr.begin(), arr.end());
				break;
			case 't':
				if (!arr.empty())
				{
					int tmp = arr.front();
					arr.front() = arr.back();
					arr.back() = tmp;
				}
				break;

		}
		scanf("%c", &o);
	}

	for (int element : arr)
		printf("%d ", element);

	return 0;
}