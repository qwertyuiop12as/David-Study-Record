#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;

stack<pair<int, int>> st;
int arr[500002], res[500002];

int main()
{
	int N, i, num;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (i = N; i >= 1; i--)
	{	
		while (!st.empty() && st.top().first < arr[i])
		{
			int idx = st.top().second;
			res[idx] = i;
			st.pop();
		}

		st.push(make_pair(arr[i], i));
	}

	for (i = 1; i <= N; i++)
		printf("%d ", res[i]);
}