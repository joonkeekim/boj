#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long res = 0;

void merge(vector<int> &v, int s, int e)
{
    int left = s;
    int mid = (s + e) / 2;
    int right = mid + 1;
    if (s == e)
        return;
    vector<int> temp;

    merge(v, s, mid);
    merge(v, mid + 1, e);

    while (left <= mid && right <= e)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left++]);
        }
        else
        {
            //뒤에 있는 애가 앞으로 가는거니까
            temp.push_back(v[right++]);
            res += (mid + 1 - left);
        }
    }
    while (left <= mid)
    {
        temp.push_back(v[left++]);
    }
    while (right <= e)
    {
        temp.push_back(v[right++]);
    }
    for (int i = s, j = 0; i <= e; ++i, ++j) {
		v[i] = temp[j];
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    merge(v, 0, N - 1);
    /*for (int i = 0; i < N; i++)
    {
        cout<<v[i]<<" ";
    }*/
    cout<<res<<'\n';
    return 0;
}