#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string arr[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    long long a = stoll(arr[0] + arr[1]);
    long long b = stoll(arr[2] + arr[3]);
    cout << a + b << '\n';
}