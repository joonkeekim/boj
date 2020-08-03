#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string tmp;
    cin >> n;
    queue<int> que;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == "push")
        {
            cin >> tmp;
            que.push(stoi(tmp));
        }
        else if (tmp == "pop")
        {
            if (!que.empty())
            {
                cout << que.front() << '\n';
                que.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (tmp == "size")
        {
            cout << que.size() << '\n';
        }
        else if (tmp == "empty")
        {
            cout << que.empty() << '\n';
        }
        else if (tmp == "front")
        {
            if (!que.empty())
            {
                cout << que.front() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
        else
        { //back
            if (!que.empty())
            {
                cout << que.back() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}