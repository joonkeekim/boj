#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    vector<int> ans;
    while (1)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
            break;
        ans.push_back(tmp);
    }
    int maxi = *max_element(ans.begin(),ans.end());
    v.resize(maxi);
    long long i = 2;
    v[1] = 1;
    while (1)
    {
        if (v[i] == 0)
        {
            for (int j = i + 1; j < maxi; j++)
            {
                if (v[j] == 0)
                {
                    if (j % i == 0)
                        v[j] = 1;
                }
            }
        }
        i++;
        if (i * i > maxi)
            break;
    }
    //0는 소수, 1은 안소수
    int len = ans.size();
    int aa= 0;
    while (aa<len)
    {
        int tmp, tmp2;
        bool c = false;
        tmp = ans[aa++];
        tmp2 = tmp;
        if (tmp % 2 == 0)
        {
            tmp2--;
        }
        for (int i = tmp2; i > 0; i -= 2)
        {
            if (v[i] == 0)
            {
                if (i + 2 == tmp)
                {
                    cout << tmp << " = " << 2 << " + " << i << '\n';
                    c = true;
                    break;
                }
                int kk = tmp - i;
                for (int j = 3; j <= kk; j += 2)
                {
                    if (v[j] == 0)
                    {
                        if (i + j == tmp)
                        {
                            cout << tmp << " = " << j << " + " << i << '\n';
                            c = true;
                            break;
                        }
                    }
                }
            }
            if (c)
                break;
        }
        if (!c)
        {
            cout << "Goldbach's conjecture is wrong.\n";
        }

    }

    return 0;
}