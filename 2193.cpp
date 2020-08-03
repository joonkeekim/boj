#include<iostream>
#include<cstring>
using namespace std;

class Problem{
    private:
    int n;
    long long int arr[91][2];
    long long int sum;
    public:
    Problem():sum(0){
        cin>>n;
        memset(arr,0,sizeof(long long int)*(n+1)*2);
    }
    void solution(){
        arr[1][0]=0;
        arr[1][1]=1;
        for(int i=2;i<=n;i++){
            arr[i][0]=arr[i-1][0]+arr[i-1][1];
            arr[i][1]=arr[i-1][0];
        }
    }
    void showResult(){
        cout<<arr[n][0]+arr[n][1]<<endl;
    }

};

int main(){
    Problem k;
    k.solution();
    k.showResult();
    return 0;
}