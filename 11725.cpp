#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> v(100001);
bool check[100001];
int parent[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        //arr[a][b] = true;
        //arr[b][a] = true;
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
        parent[p.first] = p.second;
        for (int i = 0; i < v[p.first].size(); i++)
        {
            s.push({v[p.first][i], p.first});
        }
    }
    for (int i = 2;i < N+1; i++)
    {
        cout<<parent[i]<<"\n";
    }
    return 0;
}