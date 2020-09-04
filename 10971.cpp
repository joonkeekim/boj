#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10];
int route[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Min = 2e9;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
        route[i] = i;
    }
    do
    {
        int tmp = 0, flag = 0;
        for (int i = 0; i < N; i++)
        {
            int cost;
            if (i == N - 1)
            {
                cost = arr[route[N-1]][route[0]];
            }
            else
            {
                cost = arr[route[i]][route[i + 1]];
            }
            if (cost)
            {
                tmp += cost;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        Min = min(tmp, Min);
    } while (next_permutation(route, route + N));
    cout << Min << '\n';

    return 0;
}