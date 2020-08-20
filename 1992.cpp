#include <iostream>
using namespace std;

int N;
int arr[65][65];
string s;

void quadtree(int s1, int s2, int len)
{
    int t = arr[s1][s2];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (t != arr[s1 + i][s2 + j])
            {
                //분할시작
                s += '(';
                quadtree(s1, s2, len / 2);
                quadtree(s1, s2 + len / 2, len / 2);
                quadtree(s1 + len / 2, s2, len / 2);
                quadtree(s1 + len / 2, s2 + len / 2, len / 2);

                s += ')';
                return;
            }
        }
    }
    s += t + '0';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin.get();
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = cin.get() - '0';
        }
        //cin.get();
    }
    //s += '(';
    quadtree(1, 1, N);
    //s += ')';
    cout << s << '\n';
    return 0;
}