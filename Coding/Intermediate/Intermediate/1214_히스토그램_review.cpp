#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

stack<pair<int, int>> st;
void push(int height, int pos);

long long int big = 0;

int main()
{
	int N, height;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &height);
		push(height, i);
	}

	push(0, N+1);

	printf("%d", big);
}

void push(int height, int pos)
{
	int idx = pos;
	while (!st.empty() && st.top().first > height) {
		idx = st.top().second;
		big = max(big, (long long)(pos - idx) * st.top().first);
		st.pop();
	}

	st.push(make_pair(height, idx));

	return;
}