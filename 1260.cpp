#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> vec[n + 1];

    for (int i = 0; i < m; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        vec[tmp.first].push_back(tmp.second);
        vec[tmp.second].push_back(tmp.first);
    }

    for (int i = 0; i < n; i++)
    {
        sort(vec[i + 1].begin(), vec[i + 1].end());
    }
    bool checks[n + 1];
    bool checkq[n + 1];
    for(int i = 0;i<=n;i++){
        checks[i] = false;
        checkq[i] = false;
    }
    stack<int> s;
    s.push(v);

    while (!s.empty())
    {
        int k = s.top();
        s.pop();
        if (!checks[k])
        {
            cout << k << ' ';
            checks[k] = true;
            for (int i = vec[k].size() - 1; i >= 0; i--)
            {
                if (!checks[vec[k][i]])
                {
                    s.push(vec[k][i]);
                }
            }
        }
    }
    cout << '\n';

    queue<int> q;
    

    q.push(v);

    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        if (!checkq[k])
        {
            cout << k << ' ';
            checkq[k] = true;
            for (int i = 0; i < vec[k].size(); i++)
            {
                if (!checkq[vec[k][i]])
                {
                    q.push(vec[k][i]);
                }
            }
        }
    }
    cout << '\n';
    return 0;
}