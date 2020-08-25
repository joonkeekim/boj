#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    vector<int> v;
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int res = v[0];
    for (int i = 1; i < N; i++)
    {
        v[i] = v[i-1]+v[i];
        res += v[i];
    }
    cout<<res<<'\n';
    return 0;
}