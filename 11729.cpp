#include <iostream>
#include <vector>
using namespace std;

int K;
vector<pair<int,int>> ans;
string s;
int cnt = 0;

void hanoi(int from, int to, int height)
{
    if (height == 0)
        return;

    hanoi(from, 6 - from - to, height - 1); //전꺼 옮기는 부분
    cnt += 1;
    //ans.push_back({from,to});
    s += from + '0';
    s += ' ';
    s += to + '0';
    s += '\n';
    hanoi(6 - from - to, to, height - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    
    hanoi(1, 3, K);
    cout<<cnt<<"\n";
    cout<<s;
    //string으롤 하는게 훨씬 빠르다!!!
    /*for(int i = 0 ;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }*/
    return 0;
}