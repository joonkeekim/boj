#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int arr[101][101];
ll sum[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin.get();
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = cin.get() - '0';
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (ll)arr[i][j];
        }
    }
    ll mm = arr[1][1];
    //가로로 나누기
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            ll t1 = sum[i][M];
            ll t2 = sum[j][M] - t1;
            ll t3 = sum[N][M] - t1 - t2;
            //cout<<t1*t2*t3<<"\n";
            long long res = t1 * t2 * t3;
            if (res > mm)
            {
                mm = res;
            }
        }
    }
    //세로
    for (int i = 1; i < M - 1; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            ll t1 = sum[N][i];
            ll t2 = sum[N][j] - t1;
            ll t3 = sum[N][M] - t1 - t2;
            //cout<<t1*t2*t3<<"\n";
            long long res = t1 * t2 * t3;
            if (res > mm)
            {
                mm = res;
            }
        }
    }

    //1
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            ll t1 = sum[i][j];
            ll t2 = sum[i][M] - t1;
            ll t3 = sum[N][M] - t1 - t2;
            //cout<<t1*t2*t3<<"\n";
            long long res = t1 * t2 * t3;
            if (res > mm)
            {
                mm = res;
            }
        }
    }
    //2
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            ll t1 = sum[N][j];
            ll t2 = sum[i][M] - sum[i][j];
            ll t3 = sum[N][M] - t1 - t2;
            //cout<<t1*t2*t3<<"\n";
            long long res = t1 * t2 * t3;
            if (res > mm)
            {
                mm = res;
            }
        }
    }
    //3
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            ll t1 = sum[i][M];
            ll t2 = sum[N][j] - sum[i][j];
            ll t3 = sum[N][M] - t1 - t2;
            //cout<<t1*t2*t3<<"\n";
            long long res = t1 * t2 * t3;
            if (res > mm)
            {
                mm = res;
            }
        }
    }
    //4
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            ll t1 = sum[i][j];
            ll t2 = sum[N][j] - t1;
            ll t3 = sum[N][M] - t1 - t2;
            //cout<<t1*t2*t3<<"\n";
            long long res = t1 * t2 * t3;
            if (res > mm)
            {
                mm = res;
            }
        }
    }

    cout << mm << '\n';
    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    return 0;
}