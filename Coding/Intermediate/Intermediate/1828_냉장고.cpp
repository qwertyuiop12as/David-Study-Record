#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct chem {
	int low, high;

	bool operator<(const chem &other)
	{
		return low < other.low || (low == other.low && high > other.high);
	}

};

vector<chem> arr;

int main()
{
	int N, i, x, y;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d%d", &x, &y);
		arr.push_back({ x, y });
	}

	sort(arr.begin(), arr.end());

	int cur_high, cnt = 1;
	cur_high = arr[0].high;

	for (i = 1; i < N; i++)
	{
		if (arr[i].low > cur_high) {
			cur_high = arr[i].high;
			cnt++;
		}

		cur_high = min(arr[i].high, cur_high);
	}

	printf("%d", cnt);

	/*for (i = 0; i < N; i++) {
		printf("%d %d\n", arr[i].low, arr[i].high);
	}*/
	
}