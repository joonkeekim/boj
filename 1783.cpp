#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;//n은 세로, m은 가로
    cin>>N>>M;
    if(N == 1){
        cout<<"1\n";
    }
    if(N == 2){
        int ans = (M+1)/2;
        if(ans > 4){
            ans = 4;
        }
        cout<<ans<<'\n';
    }
    if(N >= 3){
        int ans;
        if(M<7){
            ans = min(M,4);
        }
        else{
            ans = M-2;
        }
        cout<<ans<<'\n';
    }
}