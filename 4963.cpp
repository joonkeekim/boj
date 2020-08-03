#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

int arr[50][50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        int W, H;
        cin >> W >> H;
        if (W == 0 && H == 0)
        {
            break;
        }
        for (int i = 0; i < 50; i++)
        {
            memset(arr[i],0,sizeof(int)*50);
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> arr[i][j];
            }
        }
        int cnt = 2;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
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

                        if (p.first > 0)
                            s.push(make_pair(p.first - 1, p.second));
                        if (p.first < H - 1)
                            s.push(make_pair(p.first + 1, p.second));
                        if (p.second > 0)
                            s.push(make_pair(p.first, p.second - 1));
                        if (p.second < W - 1)
                            s.push(make_pair(p.first, p.second + 1));

                        if (p.first > 0 && p.second < W - 1)
                            s.push(make_pair(p.first - 1, p.second + 1));
                        if (p.first < H - 1 && p.second < W - 1)
                            s.push(make_pair(p.first + 1, p.second + 1));
                        if (p.first < H - 1 && p.second > 0)
                            s.push(make_pair(p.first + 1, p.second - 1));
                        if (p.first > 0 && p.second > 0)
                            s.push(make_pair(p.first - 1, p.second - 1));
                    }
                    cnt++;
                }
            }
        }

        /*for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cout << arr[i][j];
            }
            cout << '\n';
        }*/
        cout << cnt - 2 << '\n';
    }

    return 0;
}