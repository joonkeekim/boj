#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[101];
    cin>>a;
    for(int i=0;i<strlen(a);i++){
        cout<<a[i];
        if(i%10==9) cout<<endl;
    }
    cout<<endl;
}