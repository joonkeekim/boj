#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;
int arr[25][25];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int aa = cin.get();
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = cin.get() - '0';
        }
    }
    int cnt = 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1)
            {
                int numcnt = 0;
                stack<pair<int, int> > s;
                s.push(make_pair(i, j));
                while (!s.empty())
                {
                    pair<int, int> p = s.top();
                    s.pop();

                    if (arr[p.first][p.second] != 1)
                        continue;

                    arr[p.first][p.second] = cnt;
                    numcnt++;

                    if (p.first > 0)
                        s.push(make_pair(p.first - 1, p.second));
                    if (p.first < N - 1)
                        s.push(make_pair(p.first + 1, p.second));
                    if (p.second > 0)
                        s.push(make_pair(p.first, p.second - 1));
                    if (p.second < N - 1)
                        s.push(make_pair(p.first, p.second + 1));
                }
                v.push_back(numcnt);
                cnt++;
            }
        }
    }
    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }*/
    cout << cnt - 2 << '\n';
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<'\n';
    }
    return 0;
}