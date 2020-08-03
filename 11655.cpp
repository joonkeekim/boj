#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    getline(cin,tmp);
    for (int i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] >= 0x61 && tmp[i] <= 0x7A)
        {
            tmp[i] -= 0x61;
            tmp[i] = (tmp[i]+13)%26;
            tmp[i] += 0x61;
        }
        else if (tmp[i] >= 0x41 && tmp[i] <= 0x5A)
        {
            tmp[i] -= 0x41;
            tmp[i] = (tmp[i]+13)%26;
            tmp[i] += 0x41;
        }
    }
    cout<<tmp<<'\n';
}