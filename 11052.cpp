#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int arr[1001];
    int dp[1001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    }
    memset(dp,0,sizeof(int)*(n+1));
    dp[1]=arr[1];
    for(int i=2;i<=n;i++){
        int tmp = arr[i];
        for(int j=1;j<i;j++){
            tmp=max(dp[i-j]+arr[j],tmp);
        }
        dp[i]=tmp;
    }
    cout<<dp[n];
}