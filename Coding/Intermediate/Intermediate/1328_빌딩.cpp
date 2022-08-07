#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;

stack<pair<int, int>> st;
int res[100003];

int main()
{
	int N, num, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		while (!st.empty() && st.top().first < num)
		{
			int idx = st.top().second;
			res[idx] = i;
			st.pop();
		}

		st.push(make_pair(num, i));
	}

	while (!st.empty())
	{
		int idx = st.top().second;
		res[idx] = 0;
		st.pop();
	}

	for (i = 1; i <= N; i++)
		printf("%d\n", res[i]);
}