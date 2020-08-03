#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

int parent[1001];

int find(int a)
{
    if (parent[a] == a)
    {
        return a;
    }
    else
    {
        return find(parent[a]);
    }
}

void uni(int a, int b)
{   
    //find(a);

    parent[find(b)] = find(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 1001; i++)
    {
        parent[i] = i;
    }

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        uni(a,b);
    }

    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(i == parent[i]) {
            cnt++;
        }
        //cout<<parent[i]<<' ';
    }
    cout<<cnt<<'\n';
    return 0;
}