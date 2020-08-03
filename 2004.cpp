#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    long long cntn2 = 0, cntn5 = 0;
    long long cntm2 = 0, cntm5 = 0;
    long long cntnm2 = 0, cntnm5 = 0;
    //nCm은     n! / (m)!(n-m)!
    //에서 0의 개수
    //아예 다르게 접근하자.
    for (long long i = 2; i <= n; i *= 2)
    {
        cntn2 += n / i; //2의 개수 4의 개수 8의 개수 ...
    }
    for (long long i = 5; i <= n; i *= 5)
    {
        cntn5 += n / i;
    }
////
    for (long long i = 2; i <= m; i *= 2)
    {
        cntm2 += m / i; //2의 개수 4의 개수 8의 개수 ...
    }
    for (long long i = 5; i <= m; i *= 5)
    {
        cntm5 += m / i;
    }
/////
    int k = n-m;
    for (long long i = 2; i <= k; i *= 2)
    {
        cntnm2 += k / i; //2의 개수 4의 개수 8의 개수 ...
    }
    for (long long i = 5; i <= k; i *= 5)
    {
        cntnm5 += k / i;
    }
    cout<<min(cntn2-cntm2-cntnm2,cntn5-cntm5-cntnm5)<<'\n';
    return 0;
}