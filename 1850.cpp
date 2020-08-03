#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;
    //모든 자리가 1이다...
    //cout<<sizeof(b);
    while (b != 0)
    {
        long long tmp = a%b;
        a=b;
        b=tmp;
    }
    for(int i =0;i<a;i++){
        cout<<'1';
    }
    cout<<'\n';
    return 0;
}