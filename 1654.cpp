#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long K, N;
    cin >> K >> N;
    //long long * arr = new long long[K];
    vector<long long> v;
    for (int i = 0; i < K; i++)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    long long low = 1;
    long long high = *max_element(v.begin(), v.end());
    long long Max = 0;

    while (low<=high)
    {
        long long mid = (low+high)/2;
        long long cnt = 0;
        for (int i = 0; i < K; i++)
        {
            int tmp = v[i] / mid;
            cnt += tmp;
        }
        if (cnt >= N)
        {
            low = mid + 1;
            if(mid>Max){
                Max = mid;
            }
        }
        else if (cnt < N)
        {
            high = mid - 1;
        }
    }
    cout<<Max<<'\n';
    return 0;
}