#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n, element;
	// int arr[110];
	vector<int> arr; // size 0, dynamic array
	scanf("%d", &n);

	//for (int i = 0; i < n; i++)	scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &element);
		arr.push_back(element);
	}

	/*for (int i = 0; i < n; i++)	printf("%d ", arr[i]);
	printf("\n");*/
	for (int i = 0; i < arr.size(); i++)	printf("%d ", arr[i]);
	printf("\n");

	for (int element : arr) printf("%d ", element);
	return 0;
}