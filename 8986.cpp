#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
int N;

long long count(long long k)
{
    long long cnt = 0;
    for (long long i = 1; i < N; i++)
    {
        cnt += abs(k * i - v[i]);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    //high를 잘못 잡았다!!!!!
    //long long low = 1, high = v[N-1];//만약에 이렇게하면 항이 하나일때가 문제이다.
    
    long long low = 0, high = v[N-1];//이렇게 하던가 아래처럼하던가.
    //long long low = 1, high = 1e9;
    //high는 int의 최댓값으로 생각하는게 맞았따.
    while (high - low >= 3)
    {
        long long p = (low * 2 + high) / 3;
        long long q = (low + high * 2) / 3;
        long long tmp1 = count(p);
        long long tmp2 = count(q);
        if(tmp1>tmp2){
            low = p;
        }
        else{
            high = q;
        }
    }
    long long res;
    long long min = 1e18;
    for(res = low;res<=high;res++){
        if(count(res)<min){
            min = count(res);
        }
    }
    //cout<<low<<" "<<high<<'\n';
    cout<<min<<'\n';

    return 0;
}