#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    vector<int> v;
    cin >> n >> m;

    do
    {
        v.push_back(n % m);
        n = n / m;
    }while (n != 0);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int c = v[i];
        if (c > 9)
        {
            char c2 = c + 55;
            cout << c2;
        }
        else
        {
            cout << c;
        }
    }
    cout<<'\n';
    return 0;
}