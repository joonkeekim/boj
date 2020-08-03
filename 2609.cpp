#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b,a2,b2;

    cin>>a>>b;
    a2 = a;
    b2 = b;
    if(b>a) swap(a,b);
    

    while(b!=0){
        int n = a%b;
        a = b;
        b = n;
    }
    cout<<a<<'\n';
    cout<<a2*b2/a<<'\n';
}