#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, j,k, res = 0;
    vector<int> v;
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (j = N - 1; j > 0; j -= 2)
    {
        if (v[j] <= 1 || v[j - 1] <= 1)
            break;
        res += v[j] * v[j - 1];
    }
    for (k = 0; k < j; k += 2)
    {
        if(v[k]<=0 && v[k+1]<=0){
            res+= v[k]*v[k+1];
        }
        else{
            break;
        }
    }
    for(int i=k;i<=j;i++){
        res += v[i];
    }
    cout<<res<<'\n';
    return 0;
}