#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> is_prime, visited;
vector<int> prime_list;
vector<vector<int>> prime_connection;
queue<pair<int, int>> que;

bool is_connected(int a, int b);
int BFS();
int st, en;

int main()
{
	int i, j;
	scanf("%d%d", &st, &en);

	is_prime.resize(10000, true);	visited.resize(10000, false);
	prime_connection.resize(10000);

	for (i = 2; i <= 9999; i++)
	{
		if (is_prime[i] == false)
			continue;

		for (j = i * 2; j <= 9999; j += i)
			is_prime[j] = false;

		if (i < 1000)
			continue;

		prime_list.push_back(i);
		for (j = 0; j < prime_list.size() - 1; j++)
		{
			if (is_connected(i, prime_list[j]))
			{
				prime_connection[i].push_back(prime_list[j]);
				prime_connection[prime_list[j]].push_back(i);
			}
		}
	}

	visited[st] = true;
	que.push(make_pair(st, 0));
	printf("%d", BFS());
}
bool is_connected(int a, int b)
{
	int diff = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a % 10 != b % 10)
			diff++;
		
		a /= 10;	b /= 10;

		if (diff > 1)
			return false;
	}

	return true;
}

int BFS()
{
	while (!que.empty())
	{
		int cur = que.front().first;
		int cur_t = que.front().second;

		for (int i = 0; i < prime_connection[cur].size(); i++)
		{
			int new_p = prime_connection[cur][i];
			if (visited[new_p] == true)
				continue;

			if (new_p == en)
				return cur_t+1;

			visited[new_p] = false;
			que.push({ new_p, cur_t + 1 });
		}

		que.pop();
	}
	return -1;
}