#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //부호없는 -2진수
    int n;
    stack<int> s;
    cin>>n;
    do
    {
        if(n%2 == 0){
            s.push(0);
        }
        else{
            n-=1;
            s.push(1);
        }
        n/=-2;
    }while(n != 0);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<'\n';
}