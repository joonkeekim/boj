#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[26];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    for (int i = 0; i < 26; i++)
    {
        arr[i] = -1;
    }
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (arr[tmp[i] - 'a'] == -1)
        {
            arr[tmp[i] - 'a'] = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}