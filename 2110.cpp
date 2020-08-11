#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, C;
    cin >> N >> C;
    vector<int> v;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    int high = v[N - 1] - v[0];
    int low = 1;
    int mid;
    int res;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int cnt = 1;
        //v[1]은 항상
        int past = v[0];
        //int min = 1e9;
        for (int i = 1; i < N; i++)
        {
            if (v[i] - past >= mid)
            {
                /*if (v[i] - past < min)
                    min = v[i] - past;*/
                past = v[i];
                cnt++;
            }
        }
        if (cnt >= C)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res << '\n';

    return 0;
}