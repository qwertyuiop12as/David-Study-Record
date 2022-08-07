#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Rectangle
{
	int width, height;
	bool operator<(Rectangle other)
	{
		return (width * height) < (other.width * other.height);
	}
	int operator+(Rectangle other)
	{
		return width += other.width;
	}
};

int main()
{
	Rectangle a, b;

	scanf("%d %d", &a.width, &a.height);
	scanf("%d %d", &b.width, &b.height);

	if (a < b)
		printf("a is smaller\n");
	else
		printf("b is smaller\n");

	// printf("%d\n", a+b);

	return 0;
}