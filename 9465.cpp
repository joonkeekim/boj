#include<iostream>
#include<cstring>
using namespace std;

int Max(int a, int b) {
    	return a > b ? a : b; 
}
int main(){
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){//몇 회 반복하는가.
        int n;//몇 줄 짜리인가
        cin>>n;
        int **arr=new int*[2];
        for(int j=0;j<2;j++){
            arr[j]=new int[n+1];
            memset(arr[j],0,sizeof(int)*(n+1));
        }//선언 및 초기화
        for(int k=1;k<=n;k++){
            scanf("%d",&arr[0][k]);
        }
        for(int k=1;k<=n;k++){
            scanf("%d",&arr[1][k]);
        }//입력
        int **dp=new int*[2];
        for(int j=0;j<2;j++){
            dp[j]=new int[n+1];
            memset(dp[j],0,sizeof(int)*(n+1));
        }//선언 및 초기화
        dp[0][1]=arr[0][1];
        dp[1][1]=arr[1][1];

        for(int o=2;o<=n;o++){
            dp[0][o]=Max(dp[1][o-1],dp[1][o-2])+arr[0][o];
            dp[1][o]=Max(dp[0][o-1],dp[0][o-2])+arr[1][o];
        }
        printf("%d\n",Max(dp[0][n],dp[1][n]));
        for(int j=0;j<2;j++){
            delete [] arr[j];
        }
        delete [] arr;
    }
    return 0;
}