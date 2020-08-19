#include <iostream>
#include <vector>
using namespace std;

int K;
vector<vector<int>> v(4);
vector<pair<int,int>> ans;
int cnt = 0;

void hanoi(int from, int to, int height)
{
    if (height == 0)
        return;

    hanoi(from, 6 - from - to, height - 1); //전꺼 옮기는 부분

    /*if(height == 1){
        int tmp = *(v[from].end()-1);
        v[from].pop_back();
        v[to].push_back(tmp);
        return;
    }*/
    int tmp = *(v[from].end() - 1);
    v[from].pop_back();
    v[to].push_back(tmp);
    cnt += 1;
    ans.push_back({from,to});
    hanoi(6 - from - to, to, height - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        v[1].push_back(K - i);
    }
    //if(v[v[n].size()] == k) 마지막 장 찾음
    hanoi(1, 3, K);
    cout<<cnt<<"\n";
    for(int i = 0 ;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }
    return 0;
}