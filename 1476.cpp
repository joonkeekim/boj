#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int E, S, M;
    cin >> E >> S >> M;
    int x = 0;
    while (1)
    {
        if ((x % 15) == E - 1)
        {
            if ((x % 28) == S - 1)
            {
                if ((x % 19) == M - 1)
                {
                    break;
                }
            }
        }
        x++;
    }
    cout << x + 1 << '\n';
    return 0;
}