#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char temp[105];

    while (fgets(temp, 105, stdin))
    {
        int res[4];
        memset(res, 0, sizeof(int) * 4);
        string tmp(temp);
        for (int i = 0; i < tmp.size() - 1; i++)
        {
           
            if (tmp[i] == 0x20)
            {
                res[3]++;
            }
            else if (tmp[i] >= 0x30 && tmp[i] <= 0x39)
            {
                res[2]++;
            }
            else if (tmp[i] >= 0x41 && tmp[i] <= 0x5A)
            {
                res[1]++;
            }
            else if (tmp[i] >= 0x61 && tmp[i] <= 0x7A)
            {
                //cout<<'tmp[i]';
                res[0]++;
            }
        }
        //cout<<tmp<<'\n';
        for (int i = 0; i < 4; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}