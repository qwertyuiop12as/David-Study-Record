// c++
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string DFS(string a, int idx, int limit);
bool check(string a);
string arr[5] = { "1", "2", "3" };

int main()
{
	int N;
	scanf("%d", &N);
	string a = "1";
	cout << DFS(a, 1, N) << endl;
}

string DFS(string a, int idx, int limit)
{
	//cout << idx << endl;
	if (limit == idx)
		return a;

	for (int i = 0; i < 3; i++)
	{
		string next = a + arr[i];
		if (!check(next))
			continue;

		string res = DFS(next, idx+1, limit);
		
		if (res == "-1")
			continue;
		return res;
	}

	return "-1";
}

bool check(string a)
{
	int len = a.length();
	for (int i = 1; i <= len / 2; i++)
	{
		if (a.substr(len - i, i)._Equal(a.substr(len-(2*i), i)))
			return false;
	}
	return true;
}