#include <iostream>
using namespace std;

int arr[2179][2179];
int c1 = 0;
int c0 = 0;
int cm = 0;
void dq(int s, int e)
{
    int t = arr[s][e];
    bool flag = true;
    for (int i = s; i <= e; i++)
    {
        for (int j = s; j <= e; j++)
        {
            if (t != arr[i][j])
            {
                for (int k = 1; k <= 3; k++)
                {
                    for (int q = 1; q <= 3; q++)
                    {
                        dq((e-s+1)*k,(e-s+1)*q);
                    }
                }
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        if (t == 1)
            c1 += (e - s + 1) * (e - s + 1);
        else if (t == 0)
            c0 += (e - s + 1) * (e - s + 1);
        else
            cm += (e - s + 1) * (e - s + 1);
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
    dq(1, N);
    return 0;
}