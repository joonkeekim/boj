#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *dp=new int[n];
    memset(dp,0,sizeof(int)*n);
    dp[0]=arr[0];
    dp[1]=arr[1]+dp[0];
    dp[2]=max(dp[0]+arr[2],arr[1]+arr[2]);
    dp[2]=max(dp[1],dp[2]);
    for(int i=3;i<n;i++){
        dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
        dp[i]=max(dp[i-1],dp[i]);
    }
    cout<<dp[n-1];

}