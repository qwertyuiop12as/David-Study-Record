#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

struct delivery {
	int start, end, box;
	bool operator<(const delivery &other)
	{
		return start < other.start || (start == other.start && end < other.end);
	}
};

delivery arr[10003];

int main()
{
	int N, C, M, i;
	scanf("%d%d%d", &N, &C, &M);

	for (i = 0; i < M; i++)
		scanf("%d%d%d", &arr[i].start, &arr[i].end, &arr[i].box);

	sort(arr, arr + M);


}