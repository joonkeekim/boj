#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> v;
    vector<int> v2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int max = *max_element(v.begin(), v.end());

    v2.resize(max + 1);
    
    v2[1] = 1;
    int i = 2;
    while (1)
    {
        if (v2[i] == 0)
        {
            for (int j = i + 1; j < max + 1; j++)
            {
                if (j % i == 0)
                    v2[j] = 1;
            }
        }
        i++;
        if(i>max+1) break;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(v2[v[i]] == 0) cnt++;
    }
    cout<<cnt<<'\n';

    return 0;
}