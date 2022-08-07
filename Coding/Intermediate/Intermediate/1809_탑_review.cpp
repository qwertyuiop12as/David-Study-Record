#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

struct tower {
	int height, pos;
};

int list[500003], res[500003];
stack<tower> st;

int main()
{
	int N, i;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &list[i]);

	list[0] = 1000000000;

	for (i = N; i >= 0; i--)
	{
		while (!st.empty() && list[i] > st.top().height)
		{
			res[st.top().pos] = i;
			st.pop();
		}

		st.push({ list[i], i });
	}

	for (i = 1; i <= N; i++)
		printf("%d ", res[i]);
}