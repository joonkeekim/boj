#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    bool res;
    //char tmp[100];
    string tmp;
    for (int i = 0; i < n; i++)
    {
        stack<char> stac;
        res = true;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++)
        {

            if (tmp[j] == '(')
            {
                stac.push('(');
            }
            else
            {
                if (stac.empty())
                {
                    res = false;
                    //cout<<i<<" ";
                    //cout << "NO\n";
                    //continue;
                }
                else
                {
                    stac.pop();
                }
            }
            
        }
        if (stac.empty()&&res == true)
        {
            cout << "YES\n";
        }
        else if (res == false)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}