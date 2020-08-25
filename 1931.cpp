#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

bool comp(const p &a, const p &b)
{
    if (a.second == b.second)
    {
        return a.first<b.first;
    }
    else
    {
        return a.second<b.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,cnt = 0;
    cin >> N;
    vector<p> v;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(),v.end(),comp);

    int min = v[0].second;
    cnt++;

    for (int i = 1; i < N; i++) {
        if (v[i].first >= min) {
            min = v[i].second;
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;

}