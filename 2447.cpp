#include <iostream>
#include <cstring>
using namespace std;

int N;
char arr[6562][6562];

void star(int s1, int s2, int len)
{
    if (len == 3)
    {
        arr[s1][s2] = '*';
        arr[s1][s2 + 1] = '*';
        arr[s1][s2 + 2] = '*';
        arr[s1 + 1][s2 + 2] = '*';
        arr[s1 + 2][s2 + 2] = '*';
        arr[s1 + 2][s2 + 1] = '*';
        arr[s1 + 2][s2] = '*';
        arr[s1 + 1][s2] = '*';
        return;
    }
    int new_len = len / 3;
    star(s1, s2, new_len);
    star(s1, s2 + new_len, new_len);
    star(s1, s2 + 2 * new_len, new_len);
    star(s1 + new_len, s2 + 2 * new_len, new_len);
    star(s1 + 2 * new_len, s2 + 2 * new_len, new_len);
    star(s1 + 2 * new_len, s2 + new_len, new_len);
    star(s1 + 2 * new_len, s2, new_len);
    star(s1 + new_len, s2, new_len);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        memset(arr[i], ' ', sizeof(char) * (N + 1));
    }
    star(1, 1, N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}