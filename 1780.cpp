#include <iostream>
using namespace std;

int arr[2188][2188];
int cnt[3];

bool is(int s1, int s2, int len)
{
    int tmp = arr[s1][s2];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(arr[s1+i][s2+j] != tmp){
                return false;
            }
        }
    }
    return true;
}

void ans(int s1, int s2, int len)
{
    if (is(s1, s2, len))
    {
        cnt[arr[s1][s2] + 1] += 1;
        return;
    }
    int tmp = len / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans(s1+tmp*i,s2+tmp*j,tmp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    ans(1, 1, N);

    cout<<cnt[0]<<"\n"<<cnt[1]<<"\n"<<cnt[2]<<"\n";

    return 0;
}