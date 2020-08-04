#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
int check[101][101];
int cc[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
        //memset(check, 0, sizeof(int) * N);
    }

    //dfs로 섬구분
    int numcnt = 2;
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < N; m++)
        {
            if (arr[n][m] == 1)
            {
                //dfs
                stack<pair<int, int>> s;
                s.push({n, m});
                while (!s.empty())
                {
                    pair<int, int> p = s.top();
                    s.pop();
                    if (arr[p.first][p.second] != 1)
                        continue;
                    arr[p.first][p.second] = numcnt;
                    for (int i = 0; i < 4; i++)
                    {
                        pair<int, int> p2 = {p.first + dx[i], p.second + dy[i]};
                        if (p2.first >= 0 && p2.second >= 0 && p2.first < N && p2.second < N)
                        {
                            s.push(p2);
                        }
                    }
                }
                numcnt++;
            }
        }
    }
    //bfs로 최소거리 찾기
    vector<int> v;
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < N; m++)
        {
            if (arr[n][m] != 0)
            {
                //가장자리 판단
                int a = arr[n][m];
                for (int i = 0; i < 4; i++)
                {
                    pair<int, int> p2 = {n + dx[i], m + dy[i]};
                    if (p2.first >= 0 && p2.second >= 0 && p2.first < N && p2.second < N)
                    {
                        if (arr[p2.first][p2.second] == 0 && check[p2.first][p2.second] == 0)
                        {
                            check[p2.first][p2.second] = 1;
                            ///////
                            queue<pair<pair<int, int>, int>> q;
                            q.push({{p2.first, p2.second}, 1}); //2가 시작
                            while (!q.empty())
                            {
                                pair<pair<int, int>, int> p = q.front();
                                q.pop();
                                if (cc[p.first.first][p.first.second] != 0)
                                {
                                    //들렸던곳
                                    continue;
                                }
                                if(arr[p.first.first][p.first.second] != 0){
                                    if(arr[p.first.first][p.first.second] != a){
                                        v.push_back(p.second);
                                        break;
                                    }
                                    continue;
                                }
                                /*if(arr[p.first.first][p.first.second] != a){
                                    v.push_back(p.second);
                                    break;
                                }
                                if (arr[p.first.first][p.first.second] != 0 && cc[p.first.first][p.first.second] != 0)
                                    continue;*/
                                cc[p.first.first][p.first.second] = p.second;
                                for (int i = 0; i < 4; i++)
                                {
                                    pair<int, int> p2 = {p.first.first + dx[i], p.first.second + dy[i]};
                                    if (p2.first >= 0 && p2.second >= 0 && p2.first < N && p2.second < N)
                                    {
                                        q.push({p2, p.second + 1});
                                    }
                                }
                            }
                            for (int aa = 0; aa < 100; aa++)
                            {
                                memset(cc[aa], 0, sizeof(int) * 101);
                            }
                        }
                    }
                }
            }
        }
    }

    ///
    /*for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < N; m++)
        {
            cout << arr[n][m] << " ";
        }
        cout << "\n";
    }*/
    cout << *min_element(v.begin(), v.end()) -1<< "\n";
    return 0;
}