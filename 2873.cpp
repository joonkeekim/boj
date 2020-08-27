#include <iostream>
#include <vector>
#include <algorithm>
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
                for (int j = 0; j < C - 1; j++)
                {
                    cout << "D";
                }
            }
            else
            {
                for (int j = 0; j < C - 1; j++)
                {
                    cout << "U";
                }
            }
            if (i != R - 1)
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
        for (int i = 0; i < p.first; i++)
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
            cout << "D";
        }
        ///
        //홀이면 오른쪽부터
        //짝이면 왼쪽부터
        if (p.first % 2 != 0)
        {
            //무조건 한번은 내려가고
            int a = p.first;
            int b = C - 1;
            bool flag = true;
            for (int i = 0; i < 2 * C - 1; i++)
            {
                if (i == 2 * C - 2)
                {
                    cout << "D";
                    break;
                }
                if (flag)
                {
                    if (a % 2 == 0)
                    {
                        if (b == p.second)
                        {
                            cout << "L";
                            b--;
                            continue;
                        }
                        else
                        {
                            cout << "U";
                            a--;
                        }
                    }
                    else
                    {
                        cout << "D";
                        a++;
                    }
                }
                else
                {
                    cout << "L";
                    b--;
                }
                flag = !flag;
            }
            for (int i = p.first + 2; i < R; i++)
            {
                if (i % 2 != 0)
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
        }
        else
        {
            int a = p.first;
            int b = C - 1;
            bool flag = true;
            for (int i = 0; i < 2 * C - 1; i++)
            {
                if (i == 2 * C - 2)
                {
                    cout << "D";
                    break;
                }
                if (flag)
                {
                    if (a % 2 == 0)
                    {
                        if (b == p.second)
                        {
                            cout << "R";
                            b++;
                            continue;
                        }
                        else
                        {
                            cout << "U";
                            a--;
                        }
                    }
                    else
                    {
                        cout << "D";
                        a++;
                    }
                }
                else
                {
                    cout << "R";
                    b++;
                }
                flag = !flag;
            }
            for (int i = p.first + 2; i < R; i++)
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
        }
        ///
        cout << '\n';
    }

    return 0;
}