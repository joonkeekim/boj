#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int len = s.size();
    stack<int> res;
    for (int i = len - 1; i >= 0; i -= 3)
    {
        int tmp = 0;
        tmp += s[i] - '0';
        if (i - 1 >= 0)
            tmp += (s[i - 1] - '0') * 2;
        if (i - 2 >= 0)
            tmp += (s[i - 2] - '0') * 4;
        res.push(tmp);
    }
    int k = res.size();
    for (int i = 0; i < k; i++)
    {
        cout << res.top();
        res.pop();
        //cout<<res.size()<<'\n';
    }
    cout<<'\n';
}