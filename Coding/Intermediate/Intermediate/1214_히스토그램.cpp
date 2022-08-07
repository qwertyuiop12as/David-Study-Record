#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<long long int, int>> st;
void push(int h, int p);

long long int big = 0;

int main()
{
	int N, i, height;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &height);
		push(height, i);
	}

	push(0, N + 1);

	printf("%lld", big);
}

void push(int h, int p)
{
	int idx = p;

	while (!st.empty() && st.top().first > h)
	{
		idx = st.top().second;

		big = max(big, (p-idx) * st.top().first);
		st.pop();
	}
	
	st.push(make_pair(h, idx));

	return;
}