#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N;
    vector<int> v1;
    vector<int> v2;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v1.push_back(input);
    }
    sort(v1.begin(),v1.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        v2.push_back(input);
    }
    int high = v1[N-1];
    int low = v1[0];
    for (int i = 0; i < M; i++)
    {
        if (v2[i] > high || v2[i] < low)
        {
            cout << "0\n";
            continue;
        }
        int tmphigh = N-1;
        int tmplow = 0;
        int mid;
        int ans = v2[i];
        bool flag = false;
        while (tmplow <= tmphigh)
        {
            mid = (tmplow + tmphigh) / 2;

            if (v1[mid] > ans)
            {
                tmphigh = mid - 1;
            }
            else if (v1[mid] < ans)
            {
                tmplow = mid + 1;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }

    return 0;
}