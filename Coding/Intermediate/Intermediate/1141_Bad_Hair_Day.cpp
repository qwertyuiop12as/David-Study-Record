#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;

stack<int> st;

int main()
{
	int N, i, num;
	long long int sum = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		while (st.size() > 0 && st.top() <= num)
			st.pop();

		sum += st.size();
		st.push(num);
	}

	printf("%lld", sum);
}