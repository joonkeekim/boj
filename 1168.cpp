#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,tmp;
    vector<int> v;
    cin>>n>>k;

    cout<<'<';

    for(int i = 0;i<n;i++){
        v.push_back(i+1);
    }

    int cnt,mod;
    cnt = 0;
    mod = v.size();
    
    while(true){
        if(v.size() == 1) break;
        cnt=(cnt+k-1)%mod;

        cout<<v[cnt]<<", ";
        v.erase(v.begin()+cnt);

        mod--;
    }
    cout<<v[0]<<">\n";

    return 0;
}