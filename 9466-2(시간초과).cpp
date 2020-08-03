#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int parent[100001];
int cyclemem[100001];
vector<int> v;
int k;
int find(int a)
{
    k++;
    if (parent[a] == a)
    {
        return a;
    }
    else
    {
        return find(parent[a]);
    }
}

void find2(int a)
{
    cyclemem[a] = 1;
    if (v[a] == a)
    {
        return;
    }
    else
    {
        find2(v[a]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        memset(parent, 0, sizeof(int) * (n + 1));
        memset(cyclemem, 0, sizeof(int) * (n + 1));
        int cnt = 0;
        
        v.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            parent[i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            //cycle 멤버면 안들어가게 하기
            if(cyclemem[v[i]]){
                cyclemem[i] = 1;
                continue;
            }
            if (i == v[i])
            { //self
                cnt++;
                continue;
            }
            k = 0;
            int tmp = find(v[i]);
            //cout<<tmp<<"  "<<i<<'\n';
            if (tmp == i)
            { //cycle
                find2(v[i]);
                cnt+=k;
                continue;
            }
            else
            {
                parent[i] = tmp;
            }
        }
        v.clear();
        cout << n - cnt << '\n';
    }
    return 0;
}