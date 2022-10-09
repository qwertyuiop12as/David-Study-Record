#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char st[26];
int main()
{
	int i;
	for (i = 0; i < 26; i++)
		st[i] = 'A' + i;

	for (char alphabet : st)
		printf("%c ", alphabet);

	return 0;
}