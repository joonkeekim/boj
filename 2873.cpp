#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[1000][1000];
//홀 홀 이면 문제안됨.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, C;
    cin >> R >> C;

    if (R % 2 != 0)
    {
        //r*(c-1) d l*(c-1) ...
        for (int i = 0; i < R; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < C - 1; j++)
                {
                    cout << "R";
                }
            }
            else
            {
                for (int j = 0; j < C - 1; j++)
                {
                    cout << "L";
                }
            }
            if (i != R - 1)
            {
                cout << "D";
            }
        }
        cout << '\n';
    }
    else if (C % 2 != 0)
    {
        //d*(r-1) r u*(r-1) ...
        for (int i = 0; i < C; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < R - 1; j++)
                {
                    cout << "D";
                }
            }
            else
            {
                for (int j = 0; j < R - 1; j++)
                {
                    cout << "U";
                }
            }
            if (i != C - 1)
            {
                cout << "R";
            }
        }
        cout << '\n';
    }
    else
    {
        int Min = 1001;
        pair<int, int> p;
        string s;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> arr[i][j];
                if (i % 2 != j % 2)
                {
                    if (Min > arr[i][j])
                    {
                        Min = arr[i][j];
                        p.first = i;
                        p.second = j;
                    }
                }
            }
        }
        if (p.first % 2 != 0)
        { //홀인경우
            for (int i = 0; i < p.first - 1; i++)
            {
                if (i % 2 == 0)
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "R";
                    }
                }
                else
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "L";
                    }
                }
                s += "D";
            }
            int c = 0;
            for (c; c < p.second; c++)
            {
                if (c % 2 == 0)
                {
                    s += "DR";
                }
                else
                {
                    s += "UR";
                }
            }
            for (c; c < C - 1; c++)
            {
                if (c % 2 == 0)
                {
                    s += "RD";
                }
                else
                {
                    s += "RU";
                }
            }
            for (int i = p.first + 1; i < R; i++)
            {
                s += "D";
                if (i % 2 == 0)
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "L";
                    }
                }
                else
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "R";
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < p.first; i++)
            {
                if (i % 2 == 0)
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "R";
                    }
                }
                else
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "L";
                    }
                }
                s += "D";
            }
            int c = 0;
            for (c; c < p.second; c++)
            {
                if (c % 2 == 0)
                {
                    s += "DR";
                }
                else
                {
                    s += "UR";
                }
            }
            for (c; c < C - 1; c++)
            {
                if (c % 2 == 0)
                {
                    s += "RD";
                }
                else
                {
                    s += "RU";
                }
            }
            for (int i = p.first + 2; i < R; i++)
            {
                s += "D";
                if (i % 2 == 0)
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "L";
                    }
                }
                else
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        s += "R";
                    }
                }
            }
        }
        cout << s << "\n";
    }

    return 0;
}