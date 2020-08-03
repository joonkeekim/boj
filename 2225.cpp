#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    /*long dp[201][201];
    const int a=1000000000;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=1;
        }
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=j;x++){
                dp[j][i]+=dp[x][i-1]%a;
            }
        }
    }
    cout<<dp[n][k];*/
    //위에 꺼는 틀린거 다음에 다시 한번 보자.
    int N,K,mod=1000000000;
    cin>>N>>K;
    
    //dp[k][n]=k개 더해서 n나오는 경우의 수
    long dp[201][201]={0};
    for(int n=0;n<=N;n++){
        dp[1][n]=1; //0,1,2,3,...N
    }
    
    for(int k=2;k<=K;k++){
        for(int n=0;n<=N;n++){
            for(int l=0;l<=n;l++){
                dp[k][n]+=dp[k-1][l];
            }
            dp[k][n]%=mod;
        }
    }
    
    cout<<dp[K][N]<<endl;
}