#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, m;
    cin >> a >> b >> m; //a진법, b진법, m(a진법으로 나타낸 수의 자리수의 개수)
    vector<int> va;
    vector<int> vb;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        va.push_back(tmp);
    }
    int res = 0;
    for (int i = va.size() - 1; i >= 0; i--)
    {
        res += va[i] * pow(a, va.size() - 1 - i);
    }
    //cout << res;
    do
    {
        vb.push_back(res%b);
        res/=b;
    }while(res!=0);

    for (int i = vb.size() - 1; i >= 0; i--)
    {
        cout<<vb[i]<<' ';
    }
    cout<<'\n';
    
    return 0;
}