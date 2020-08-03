#include<iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    char *a;
    a=new char[n+1];
    cin>>a;
    for(int i=0;i<n;i++){
        sum+=(static_cast<int>(a[i])-'0');
    }
    cout<<sum<<endl;
}