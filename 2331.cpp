#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int visited[300000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int P, A, cnt = 0;
    cin >> A >> P;
    //A를 P씩 제곱
    //dfs라...흠
    vector<int> v;
    v.push_back(A);
    while (1)
    {
        if (visited[A] == 2)
        {
            break;
        }
        visited[A]++;
        int sum = 0;
        while (A)
        {
            sum += (int)pow((A % 10), P);
            A /= 10;
        }
        A = sum;
    }
    for (int i = 0; i < 300000; i++)
    {
        if (visited[i] == 1)
            cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}