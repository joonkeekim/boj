#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Problem{
    private:
    int arr[1000001];
    int n;
    public:
    void setNum(){
        cin>>n;
        memset(arr,0,sizeof(int)*(n+1));
    }
    void solution(){
        arr[1]=0;

        for(int i=2;i<n+1;i++){
            arr[i]=arr[i-1]+1;
            if(i%2==0){
                arr[i]=min(arr[i],arr[i/2]+1);
            }
            if(i%3==0){
                arr[i]=min(arr[i],arr[i/3]+1);
            }
        }
    }
    void Println(){
        cout<<arr[n];
    }
};


int main(){
    Problem p;
    p.setNum();
    p.solution();
    p.Println();
    return 0;
}