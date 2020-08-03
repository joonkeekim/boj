#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,res = 1;
    cin>>n;
    for(int i = 2;i<=n;i++){
        res*=i;
    }
    cout<<res<<'\n';
    return 0;
}