#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxi = 1000200;
vector<int> v(10);
int cnt;
bool possible(int a)
{
    if(a == 0){
        if(v[0] == 0){
            return false;
        }
    }
    while (a > 0)
    {
        if (v[a % 10] == 0)
        {
            return false;
        }
        a /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    fill(v.begin(), v.end(), 1);
    cin >> N >> M;
    int tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        v[tmp] = 0;
    }

    int MIN = abs(N - 100);
    int temp;
    for (int i = 0; i < maxi; i++)
    {
        if (possible(i))
        {
            temp = to_string(i).length();
            temp += abs(N-i);
            MIN = min(MIN,temp);
        }
    }
    cout << MIN << "\n";

    return 0;
}