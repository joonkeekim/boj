#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){
    char arr[5001];
    cin>>arr;
    long dp[5001];//0은 첫번째 문자를 얘기하는거임!
    memset(dp,0,sizeof(int)*5001);
    const int mod =1000000;
    if(arr[0]=='0'){
        cout<<0<<endl;
    }
    else{
        dp[0]=1;
        int a1=arr[0]-'0';
        int a2=arr[1]-'0';
        int det=10*a1+a2;
        if(det>=11&&det<=26){
            dp[1]=2;
            }
        else{
            if(a2==0&&a1>=3){
                cout<<0<<endl;
                return 0;
            }
            dp[1]=1;
        }
        for(int i=2;i<strlen(arr);i++){//0이 오는 경우도 생각하자. 0이 오면 앞 부분은 무조건 1이나 2다 그리고 본인 스스로는 불가능. 0이 오면 dp[n]=dp[n-2];
            
            long b1=arr[i-1]-'0';
            long b2=arr[i]-'0';
            long de=10*b1+b2;
            if(arr[i]!='0'){
                dp[i]=dp[i-1];
            }
            if(de>=10&&de<=26){
                dp[i]+=dp[i-2];//두 가지 해석이 나올 수 있으니까 i-2와 i-1번째 것을 더해준다.
            }
            dp[i]=dp[i]%mod;
        }
        cout<<dp[strlen(arr)-1]<<endl;
    }
    
}
