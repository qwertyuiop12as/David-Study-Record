#include <stdio.h>
#include <algorithm>
using namespace std;

int money[100003];
int main()
{
    int i, j;
    money[1] = money[2] = 1;

    for (i = 3; i <= 99999; i++)
    {
        if (i % 2 == 0)
            money[i] = money[i/2];
        else
            money[i] = money[(i-1)/2] + money[((i-1)/2) + 1];
    }

    int in = 1;
    scanf("%d", &in);

    while (in != 0)
    {
        int maxn = 1;

        for (i = 1; i <= in; i++)
            maxn = max(maxn, money[i]);

        printf("%d\n", maxn);
        scanf("%d", &in);
    }
    return 0;
}
