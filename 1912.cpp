#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int arr[100001];
    int dp[100001];
    int n;
    int max;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    max=dp[1];//max를 -1000으로 하는게 아니라 dp[1]로 해야 정답이 된다. 이유가 뭘까.
    //왜냐면 내가 max를 -10000으로 해도 dp[1]은 비교를 하지 않기 때문이다.

    for(int i=2;i<=n;i++){
        if(dp[i-1]+arr[i]>dp[i]){
            dp[i]=dp[i-1]+arr[i];
        }
        if(dp[i]>max) max=dp[i];
    }
    cout<<max;

    return 0;
}