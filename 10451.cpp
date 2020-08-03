#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int parent[1001];

int find(int a)
{
    if (parent[a] == a)
        return a;
    else
    {
        return find(parent[a]);
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
        cin >> N;
        vector<int> v;
        int cnt = 0;
        memset(parent, 0, sizeof(int) * (N + 1));
        v.push_back(0);
        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            parent[i+1] = i+1;
        }
        for (int i = 1; i <= N; i++)
        {
            if (i == v[i])
            {
                cnt++;
                continue;
            }
            int k = find(i);
            if(v[i] == k){
                cnt++;
                continue;
            }
            else{
                parent[v[i]] = k;
            }
            
        }
        cout<<cnt<<'\n';
    }

    return 0;
}