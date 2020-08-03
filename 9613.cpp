#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tmp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, a,len;
        long long res;
        res = 0;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> a;
            tmp.push_back(a);
        }
        //k개 있다.
        len = tmp.size();
        for (int p = 0; p < len; p++)
        {
            for (int q = p + 1; q < len; q++)
            {
                int a, b;
                a = tmp[p];
                b = tmp[q];
                if (a < b)
                    swap(a, b);
                while(b!=0){
                    int temp = a%b;
                    a = b;
                    b = temp;
                }
                res+=a;
            }
        }
        tmp.clear();
        cout<<res<<'\n';
    }
}