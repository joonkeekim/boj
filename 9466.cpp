#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> v;
vector<int> v2;
int **visited;
//0은 방문여부 1은 몇 번째 깊이인가.
//visited[n][0] == -1 이면 방문 o & cycle x
//visited[n][0] == 0 이면 방문 x
//visited[n][0] == 1 이면 방문 o & cycle x &하는 중임
int dfs(int a, int cnt)
{
    //cout<<a<<" trial ";
    //cout<<'\n';
    //cout<<visited[a][0]<<" ";
    if (visited[a][0] == 0) //0
    {                       //들렸던데가 아니라면
        visited[a][0] = 1;
        visited[a][1] = cnt++;
        v2.push_back(a);
        return dfs(v[a], cnt);
    }
    else if (visited[a][0] == 1) //1
    {
        //cout << cnt - visited[a][1] << '\n';
        int k = v2.size();
        for (int i = 0; i < k; i++)
        {
            visited[v2[i]][0] = -1;
            //cout<<v2[i]<<"!!!";
        }
        v2.clear();
        return cnt - visited[a][1];
    }
    else //-1
    {
        int k = v2.size();
        for (int i = 0; i < k; i++)
        {
            visited[v2[i]][0] = -1;
            //cout<<v2[i]<<"!!!";
        }
        v2.clear();
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        //back edge를 찾을것 그리고, cycle이 어떻게 형성되는지 확인할것.
        //각각 번호를 매기고 back edge를 찾으면 빼서 그 사이에 사이클에 포함되는 노드의 개수를 구한다.
        int res = 0;
        cin >> N;
        visited = new int *[N + 1];
        v.push_back(0);
        visited[0] = new int[2];
        visited[0][0] = 0;
        visited[0][1] = 0;
        for (int n = 0; n < N; n++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            visited[n + 1] = new int[2];
            visited[n + 1][0] = 0;
            visited[n + 1][1] = 0;
        }
        for (int i = 1; i <= N; i++)
        {
            if (visited[i][0] == 0)
            {
                res += dfs(i, 0);
            }
        }
        //stack<pair<int, int>> s;
        //s.push(make_pair(1, 0));
        cout << N - res << '\n';
        delete[] visited;
        v.clear();
    }

    return 0;
}