#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string arr;
stack<char> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> arr;

    int res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == '(')
        {
            ans.push('(');
        }
        else
        {
            if (arr[i-1] == '(')
            {
                //laser
                ans.pop();
                res += ans.size();
                //cout<<i<<"  "<<ans.size()<<'\n';
            }
            else
            {
                //끝
                ans.pop();
                res +=1;
            }
        }
    }

    cout<<res<<'\n';
    //cout << arr << '\n';
    //cout<<"-------\n";
}