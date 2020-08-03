#include<iostream>
#include<cstring>
using namespace std;

class Problem{
    private:
    int n;
    int arr[1001][10];
    int sum;
    public:
    Problem():sum(0){//initializer
        cin>>n;
        memset(arr,0,sizeof(int)*((n+1)*10));
    }
    void solution(){
        for(int i=0;i<10;i++){
            arr[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            arr[i][0]=1;
            for(int j=1;j<10;j++){
                arr[i][j]=(arr[i-1][j]+arr[i][j-1])%10007;
            }
        }
    }
    void showResult(){
        for(int i=0;i<10;i++){
            sum+=arr[n][i]%10007;
        }
        cout<<sum%10007;//답에도 더 했어야 한다!! 준기 몽총아!!
    }
};

int main(){
    Problem k;
    k.solution();
    k.showResult();
    return 0;
}