#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;
    long long res = 1;
    bool two = false, five = false;
    for (int i = 2; i <= n; i++)
    {
        if (i % 125 == 0)//8곱하면 1000
            cnt += 3;
        else if (i % 25 == 0)//4곱하면 100
            cnt += 2;
        else if (i % 5 == 0)//2곱하면 10
            cnt++;
    }

    cout << cnt << '\n';
    return 0;
}