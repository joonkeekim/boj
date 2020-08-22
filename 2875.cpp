#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int tmp, max = 0;
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i <= K; i++)
    {
        int j = K - i;
        int nN = N - i;
        int nM = M - j;
        //int res = nN/nM;
        if (nN >= 2 * nM)
            tmp = nM;
        else
        {
            tmp = nN/2;
        }
        if (tmp > max)
            max = tmp;
    }

    cout << max << '\n';
    return 0;
}