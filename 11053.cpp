#include<iostream>
#include<cstring>
#define max(a,b) a>b? a:b
using namespace std;

int main(){
    int n;
    
    short arr[1001];
    short dp[1001];
    cin>>n;
    
    memset(dp,0,sizeof(short)*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=1;
    }
    short realMax=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],(dp[j]+1));
            }
        }
        realMax=max(realMax,dp[i]);
    }
    cout<<realMax;
}