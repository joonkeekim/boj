#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int m;
    long long res = 0;
    vector<int> v;
    cin >> s >> m;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            res += (s[i] - 'A'+10) * pow(m,s.size() - 1-i);
        }
        else
        {
            res += (s[i] - '0') * pow(m, s.size() - 1-i);
        }
    }

    cout << res << '\n';
    return 0;
}