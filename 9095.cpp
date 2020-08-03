#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class Problem{
    private:
    int n;
    int arr[11];
    public:
    Problem(){
        cin>>n;
        memset(arr,0,sizeof(int)*(n+1));
    }
    void solution(){
        arr[1]=1;
        arr[2]=2;
        arr[3]=4;
        for(int i=4;i<11;i++){
            arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
        }
    }
    void showsol(){
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            cout<<arr[a]<<"\n";            
        }
    }
};
int main(){
    Problem k;
    k.solution();
    k.showsol();
}