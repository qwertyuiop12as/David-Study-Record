#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;
int n, res = 1000;

char s[10][10];
int visited[10];
int additional[10][10];

void DFS(int size, int cnt, int last);
int combine(char str[], char tmp[]);

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &s[i]);
		//printf("len : %d\n", (*(s + i)).length());
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			additional[i][j] = combine(s[i], s[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		visited[i] = 1;
		DFS(strlen(s[i]), 1, i);
		visited[i] = 0;
	}

	printf("%d", res);
}

int combine(char str[], char tmp[])
{
	int idx = min(strlen(str), strlen(tmp));

	for (idx; idx > 0; idx--)
	{
		int str_idx = strlen(str) - idx, tmp_idx = 0;
		for (int i = 0; i < idx; i++)
		{
			if (str[str_idx+i] != tmp[tmp_idx+i])
				i = idx;

			if (i == idx - 1)
				return strlen(tmp) - idx;
		}
	}

	return strlen(tmp);
}

void DFS(int size, int cnt, int last)
{
	//printf("DFS(%d %d %d)\n", size, cnt, last);
	if (size >= res)
		return;
	if (cnt == n)
	{
		res = size;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		DFS(size + additional[last][i], cnt+1, i);
		visited[i] = 0;
	}
}