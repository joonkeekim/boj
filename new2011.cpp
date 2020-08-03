#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    char ar[5001];
    int dp[5001];
    cin>>ar;
    int len=strlen(ar);
    if(ar[0]=='0'){
        cout<<0;
        return 0;
    }
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=len;i++){
        int now=i-1;
        if(ar[now]!='0'){
            dp[i]=dp[i-1];
        }
        int b1=ar[now-1]-'0';
        int b2=ar[now]-'0';
        int tmp=10*b1+b2;
        if(tmp>=10&&tmp<=26){
            dp[i]=(dp[i]+dp[i-2])%1000000;
        }
    }
    cout<<dp[len];
}