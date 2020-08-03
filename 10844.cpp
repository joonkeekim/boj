#include<iostream>
#include<algorithm>
#include<cstring>
#define mod 1000000000
using namespace std;

class Problem{
    private:
    int n;
    int sum;
    int arr[101][11];
    public:
    Problem():sum(0){
        cin>>n;
        for(int i=0;i<101;i++){
            for(int j=0;j<11;j++){
                arr[i][j]=0;
            }
        }
    }
    void solution(){
        for(int i=1;i<10;i++)
            arr[1][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<10;j++){
                if(j==0){
                    arr[i][j]=arr[i-1][j+1]%mod;
                }
                else{
                    arr[i][j]=(arr[i-1][j-1]+arr[i-1][j+1])%mod;
                }
            }
        }
    }
    void showResult(){
        
        for(int j=0;j<10;j++){
            sum=(sum+arr[n][j])%mod;
            
        }
        cout<<sum;
        
    }
};

int main(){
    Problem k;
    k.solution();
    k.showResult();
}