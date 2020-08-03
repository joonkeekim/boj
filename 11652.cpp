#include <iostream>
#include <algorithm>

using namespace std;
long long arr[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&arr[i]) ;
    }
    sort(arr, arr + n);
    /*int tmp = 1, max = 0;
    long long res = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            tmp++;
            if (tmp > max)
            {
                res = arr[i];
                max = tmp;
            }
        }
        else
        {
            tmp = 1;
        }
    }*/
    int temp = 1;
    int max = 1;
    long long cul = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            temp++;
            if (temp > max)
            {
                cul = arr[i];
                max = temp;
            }
        }
        else
        {
            temp = 1;
        }
    }
    printf("%lld\n", cul);
}