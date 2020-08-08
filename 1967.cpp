#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<vector<pair<int, int>>> v;
bool check[100001];
int Max = -1;
int MaxNode = 0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //1부터 시작해서 계속 넣어주면 되지 않을까..

    cin >> N;
    v.resize(N+1);
    for (int i = 0; i < N-1; i++)
    {
            int a,b, c;
            cin >>a>> b>>c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
    }


    stack<pair<int, int>> s;
    s.push({1, 0});
    while (!s.empty())
    {
        pair<int, int> p = s.top();
        s.pop();
        if (check[p.first])
            continue;
        check[p.first] = true;
        if (p.second > Max)
        {
            MaxNode = p.first;
            Max = p.second;
        }
        for (int i = 0; i < v[p.first].size(); i++)
        {
            s.push({v[p.first][i].first, p.second + v[p.first][i].second});
        }
    }

    memset(check, 0, sizeof(bool) * (N + 1));
    Max = -1;

    stack<pair<int, int>> s2;
    s2.push({MaxNode, 0});
    while (!s2.empty())
    {
        pair<int, int> p = s2.top();
        s2.pop();
        if (check[p.first])
            continue;
        check[p.first] = true;
        if (p.second > Max)
        {
            MaxNode = p.first;
            Max = p.second;
        }
        for (int i = 0; i < v[p.first].size(); i++)
        {
            s2.push({v[p.first][i].first, p.second + v[p.first][i].second});
        }
    }
    cout << Max << '\n';
    return 0;
}