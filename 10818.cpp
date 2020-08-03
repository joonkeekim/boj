#include<iostream>
using namespace std;

int main(){
    int n,min,max;
    cin>>n;
    //int *num;
    //num=new int[n];
    cin>>min;
    max=min;
    for(int i=0;i<n-1;i++){
        int k;
        cin>>k;
        if(k>max) max=k;
        if(k<min) min=k;
    }
    cout<<min<<" "<<max<<endl;
}