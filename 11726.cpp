#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Problem{
    private:
    int n;
    int arr[1001];
    public:
    Problem(int k):n(k){
        memset(arr,0,sizeof(int)*(n+1));
    }
    void setNum(){
        cin>>n;
        memset(arr,0,sizeof(int)*(n+1));
    }
    void solution(){
        arr[1]= 1;
        arr[2]= 2;
        for(int i=3;i<=n;i++){
            arr[i]=(arr[i-1]+arr[i-2])%10007;
        }
    }
    void show(){
        cout<<arr[n];
    }
};

int main(){
    Problem k(9);
    //k.setNum();
    k.solution();
    k.show();
}
