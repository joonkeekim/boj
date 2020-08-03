#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
//다시 무조건 큰 것들의 조합이 최소는 아니다.


int main(){
    int n;
    int dp[100001];
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=i;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(int)sqrt(i);j++){
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n];
    

    //제곱수의 합 항의 최소의 갯수.
    //7은 2하나 1세개 4
    //처음에 7들어가고 

}