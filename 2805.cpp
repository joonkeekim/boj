#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int low = 0;
    long long Max = 0;
    int high = *max_element(v.begin(), v.end());
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        long long len = 0;
        for (int i = 0; i < N; i++)
        {
            len += v[i] - mid > 0 ? v[i] - mid : 0;
        }
        if(len<M){
            high = mid -1;
        }
        else{
            Max = mid;
            low = mid +1;
        }
    }
    cout<<Max<<'\n';
    return 0;
}