#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int tmp, cnt = 0;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int i = N - 1;
    while (K != 0)
    {
        int t = K / v[i];
        if (t > 0)
        {
            K = K % v[i];
            cnt += t;
        }
        i--;
    }
    cout<<cnt<<'\n';
    return 0;
}