#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    for(int i = 0 ;i<n;i++){
        int a,b,a2,b2;
        cin>>a>>b;
        a2 = a;
        b2 = b;
        while(b!=0){
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        //a는 최소 공배수
        cout<<(a2*b2)/a<<'\n';
    }
    return 0;
}