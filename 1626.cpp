#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int v, e, p[50050], c[200020], PARENT[50050][22], COST[50050][22], h[50050], x, y, z, f, cnt;
vector<pair<int, pair<int, int> > > vt;//cost,from,to
vector<vector<pair<int, int> > > mst;//mst[curr]하면 vector<pair<int,int>가 나온다.
//merge하면 여기에 vt[i],
int find(int h)
{
    return h == p[h] ? h : p[h] = find(p[h]);
}
//merge(vt[i].second.first -> from, vt[i].second.second -> to, vt[i].first -> cost)
bool merge(int x, int y, int z)
{
    if (find(x) == find(y))
        return false;
    mst[x].push_back({y, z});//x에서 y
    mst[y].push_back({x, z});//y에서 x
    f += z;
    p[find(x)] = find(y);
    return true;
}
void dfs(int curr, int prev)
{
    for (auto next : mst[curr])
    {
        if (next.first == prev)
            continue; //next는 vector<pair>로 나온다.
        h[next.first] = h[curr] + 1;//h가 뭐더라...

        PARENT[next.first][0] = curr;

        COST[next.first][0] = next.second;

        dfs(next.first, curr);
    }
}
int bsch(int x, int y, int z)
{ //binsearch
    if (y == 0)
        return 0;
    int ret = 0;
    if (COST[x][y - 1] == z)
        ret = max(ret, bsch(x, y - 1, z));
    else
        ret = max(ret, COST[x][y - 1]);
    if (COST[PARENT[x][y - 1]][y - 1] == z)
        ret = max(ret, bsch(PARENT[x][y - 1], y - 1, z));
    else
        ret = max(ret, COST[PARENT[x][y - 1]][y - 1]);
    return ret;
}
int getmax(int x, int y, int z)
{ //mst에서 최댓값
    if (h[x] > h[y])
        swap(x, y);
    int ret = 0;
    for (int i = 20; i >= 0; i--)
    {
        if ((h[y] - h[x]) >= (1 << i))
        {
            if (COST[y][i] == z)
                ret = max(ret, bsch(y, i, z));
            else
                ret = max(ret, COST[y][i]);
            y = PARENT[y][i];
        }
    }
    if (x == y)
        return ret;
    for (int i = 20; i >= 0; i--)
    {
        if (PARENT[x][i] != PARENT[y][i])
        {
            if (COST[x][i] == z)
                ret = max(ret, bsch(x, i, z));
            else
                ret = max(ret, COST[x][i]);
            if (COST[y][i] == z)
                ret = max(ret, bsch(y, i, z));
            else
                ret = max(ret, COST[y][i]);
            x = PARENT[x][i];
            y = PARENT[y][i];
        }
    }
    if (COST[x][0] != z)
        ret = max(ret, COST[x][0]);
    if (COST[y][0] != z)
        ret = max(ret, COST[y][0]);
    return ret;
}
int main()
{
    scanf("%d%d", &v, &e);
    mst.resize(v + 1);
    for (int i = 1; i <= v; i++)
        p[i] = i;
    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        vt.push_back({z, {x, y}});
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < e; i++)
    {
        if (merge(vt[i].second.first, vt[i].second.second, vt[i].first))
        {
            c[i]++; //c는 상관 없음
            cnt++;
        }
        if (cnt == v - 1) //다 되었는지 확인.
            break;
    }
    if (cnt != v - 1 || e <= v - 1)
    {
        puts("-1");
        return 0;
    } //mst만듬.


    dfs(1, 0);
    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i <= v; i++)
        {
            PARENT[i][j] = PARENT[PARENT[i][j - 1]][j - 1];
            COST[i][j] = max(COST[PARENT[i][j - 1]][j - 1], COST[i][j - 1]);
        }
    }
    ll r = 1e11;
    for (int i = 0; i < e; i++)
    {
        if (c[i])
            continue;
        int gmax = getmax(vt[i].second.first, vt[i].second.second, vt[i].first);
        if (!gmax)
            continue;
        r = min(r, (ll)(f - gmax + vt[i].first));
    }
    if (r == 1e11 || r == f)
        puts("-1");
    else
        printf("%lld\n", r);
    return 0;
}
