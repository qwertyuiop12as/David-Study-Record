#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student {
	char name[11];
	int id, like;
};

bool cmp(const Student &a, const Student &b)
{
	if (a.like != b.like)
		return a.like > b.like;
	
	if (strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;

	return a.id < b.id;
}

Student list[100001];

int main()
{
	int N, Q, i;
	scanf("%d%d", &N, &Q);

	for (i = 0; i < N; i++)
	{
		scanf("%s%d", list[i].name, &list[i].like);
		list[i].id = i + 1;
	}

	sort(list, list + N, cmp);

	int idx;
	for (i = 0; i < Q; i++)
	{
		scanf("%d", &idx);
		printf("%d ", list[idx-1].id);
	}

}