#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool flag = false;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "-1\n";
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += s[i];
            ans %= 3;
        }
        if (ans != 0)
        {
            cout << "-1\n";
        }
        else
        {
            sort(s.begin(), s.end(), greater<char>());
            cout << s << '\n';
        }
    }
    //0이 없으면 끝

    return 0;
}