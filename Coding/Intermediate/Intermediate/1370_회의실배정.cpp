#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
	int id, start, end;
};

vector<meeting> arr;
vector<int> res;

bool cmp(const meeting &a, const meeting &b)
{
	return a.end < b.end;
}

int main()
{
	int N, id, start, end;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &id, &start, &end);
		arr.push_back({id, start, end});
	}

	sort(arr.begin(), arr.end(), cmp);

	int cur = arr[0].end, cnt = 1;
	res.push_back(arr[0].id);

	for (int i = 1; i < N; i++)
	{
		if (arr[i].start >= cur)
		{
			cur = arr[i].end;
			cnt++;
			res.push_back(arr[i].id);
		}
	}

	printf("%d\n", cnt);

	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
}