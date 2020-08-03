#include<iostream>
#include<cstring>
#define max(a,b) a>b? a:b
using namespace std;

int main(){
    int n;
    int arr[1001];
    int dp[1001];
    cin>>n;
    memset(dp,0,sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    int sumMax=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],(dp[j]+arr[i]));
            }
        }
        sumMax=max(sumMax,dp[i]);
    }
    cout<<sumMax;
}