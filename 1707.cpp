#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

int N, V, E;
vector<vector<int> > v;
bool *b;
bool c;

void dfs(int start)
{
    c = true;
    bool check[V + 1];
    int colors[V + 1];
    for (int i = 0; i <= V; i++)
    {
        check[i] = false;
        colors[i] = 0;
    }
    stack<pair<int,int> > s;
    //first 본인 second 부모
    int tmp = 1;
    s.push(make_pair(start,0));
    colors[0] = tmp;

    while (!s.empty() && c)
    {
        pair<int,int> k = s.top();
        s.pop();

        if (check[k.first])
            continue;
        check[k.first] = true;
        b[k.first] = true;
        colors[k.first] = colors[k.second]%2 + 1;
        //tmp = tmp % 2 + 1;

        //cout << k << ' ';
        for (int i = v[k.first].size() - 1; i >= 0; i--)
        {
            int t = v[k.first][i];
            if ((colors[k.first] == colors[t]) && check[t])
            {
                cout << "NO\n";
                c = false;
                break;
            }

            if (!check[t])
            {
                s.push(make_pair(t,k.first));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int n = 0; n < N; n++)
    {
        cin >> V >> E; //v는 정점의 개수, e는 간선정보
        v.resize(V + 1);
        for (int i = 0; i < E; i++)
        {
            int tmp, tmp2;
            cin >> tmp >> tmp2;
            v[tmp].push_back(tmp2);
            v[tmp2].push_back(tmp);
        }

    
        //dfs시작

        b = new bool[V+1];
        memset(b,0,sizeof(bool)*(V+1));
        for (int i = 1; i <= V; i++)
        {
            if(!b[i]){
                dfs(i);
            }
            
            if(!c) break;
        }
        if (c)
        {
            cout << "YES\n";
        }
        v.clear();
    }

    return 0;
}