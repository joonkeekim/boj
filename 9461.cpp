#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long dp[101];
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    for(int i=6;i<101;i++){
        dp[i]=dp[i-1]+dp[i-5];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        cout<<dp[k]<<endl;
    }

}