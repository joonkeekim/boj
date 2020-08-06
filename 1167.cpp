#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100001][100001];
bool check[100001];
int Max = -1;

int dfs(int a)//b는 전
{
    //제일 먼데에서 다시 제일 먼곳을 찾으면 그게 트리의 지름

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //1부터 시작해서 계속 넣어주면 되지 않을까..

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        while (a != -1)
        {
            int b, c;
            cin >> b;
            if (b == -1)
                break;
            cin >> c;
            arr[a][b] = c;
        }
    }

    cout << Max << '\n';
    return 0;
}