#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int check[1000][1000];
int arr[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    queue<pair<pair<int, int>, int>> q;
    //M가로, N세로
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({{i, j}, 1});
            }
        }
        memset(check[i], 0, sizeof(int) * (M));
    }
    
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        if (arr[p.first.first][p.first.second] == -1)
        {
            continue;
        }
        if (check[p.first.first][p.first.second] != 0)
        {
            if (check[p.first.first][p.first.second] <= p.second)
            {
                continue;
            }
        }

        check[p.first.first][p.first.second] = p.second;

        if (p.first.first > 0)
            q.push({{p.first.first - 1, p.first.second}, p.second + 1});
        if (p.first.first < N - 1)
            q.push({make_pair(p.first.first + 1, p.first.second), p.second + 1});
        if (p.first.second > 0)
            q.push({make_pair(p.first.first, p.first.second - 1), p.second + 1});
        if (p.first.second < M - 1)
            q.push({make_pair(p.first.first, p.first.second + 1), p.second + 1});
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (check[i][j] > max)
            {
                max = check[i][j];
            }
            if (check[i][j] == 0 && arr[i][j] != -1)
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << check[i][j];
        }
        cout << '\n';
    }*/
    cout << max - 1 << '\n';
    return 0;
}