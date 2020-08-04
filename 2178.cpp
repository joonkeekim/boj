#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[1001][1001];
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    cin >> N >> M;
    cin.get();
    for (int n = 1; n < +N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            arr[n][m] = cin.get() - '0';
        }
        cin.get();
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, 2}); //2가 시작
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        if (arr[p.first.first][p.first.second] != 1)
            continue;
        arr[p.first.first][p.first.second] = p.second;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> p2 = {p.first.first + dx[i], p.first.second + dy[i]};
            if (p2.first > 0 && p2.second > 0 && p2.first <= N && p2.second <= M)
            {
                q.push({p2, p.second + 1});
            }
        }
    }
    cout << arr[N][M] - 1 << '\n';

    return 0;
}