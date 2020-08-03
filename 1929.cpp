#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    vector<int> v2;
    cin >> m >> n;

    v2.resize(n + 1);

    v2[1] = 1;
    long long i = 2;
    while (1)
    {
        if (v2[i] == 0)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                if (v2[j] == 0)
                {
                    if (j % i == 0)
                        v2[j] = 1;
                }
            }
        }
        i++;
        if (i*i > n + 1)
            break;
    }

    for (int i = m; i < n + 1; i++)
    {
        if (v2[i] == 0)
        {
            cout << i << '\n';
        }
    }

    return 0;
}