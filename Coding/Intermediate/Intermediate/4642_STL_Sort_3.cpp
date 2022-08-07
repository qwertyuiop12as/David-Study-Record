#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student {
	char name[21];
	int score;

	/*bool operator<(const Student &other)
	{
		return score > other.score || (score == other.score && strcmp(name, other.name) < 1);
	}*/
};

bool cmp(const Student &s1, const Student &s2)
{
	return s1.score > s2.score || (s1.score == s2.score && strcmp(s1.name, s2.name) < 0);
}

Student list[50001];
int main()
{
	
	int N, i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%s%d", list[i].name, &list[i].score);

	sort(list+0, list+N, cmp);

	for (i = 0; i < N; i++)
		printf("%s %d\n", list[i].name, list[i].score);

	return 0;
}