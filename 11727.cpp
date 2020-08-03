#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Problem{
    private:
    int n;
    int arr[1001];
    public:
    Problem(){
        cin>>n;
        memset(arr,0,sizeof(int)*(n+1));
    }
    void solution(){
        arr[1]=1;
        arr[2]=3;
        for(int i=3;i<n+1;i++){
            arr[i]=(arr[i-1]+2*arr[i-2])%10007;
        }
    }
    void showsol(){
        cout<<arr[n];
    }
};

int main(){
    Problem k;
    k.solution();
    k.showsol();
}