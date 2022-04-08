#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int T, N;
    scanf("%d\n", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);
        int arr[N];
        for (int j = 0; j < N; j++)
            scanf("%d ", &arr[i]);

        sort(arr, arr+N);

        int result = 0;
        for (int j = 2; j < N; j++) {
            result = max(result, abs(arr[j] - arr[j-2]));
        }

        printf("%d\n", result);
    }
}
