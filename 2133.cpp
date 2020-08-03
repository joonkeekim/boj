#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    int n;
    int dp[31];
    cin>>n;
    memset(dp,0,sizeof(int)*(n+1));
    dp[2]=3;
    for(int i=4;i<=n;i++){
        if(i%2==0){
            dp[i]+=dp[i-2]*3;
            for(int j=4;j<=i-2;j+=2){
                dp[i]+=2*dp[i-j];
            }
            dp[i]+=2;
        }
    }
    cout<<dp[n];
}
//나는 아직 잘 모른다.