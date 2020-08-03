#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    stack<int> res;
    cin>>s;

    for(int i = s.size()-1;i>0;i--){
        int tmp =s[i]-'0';
        res.push(tmp % 2);
        tmp /= 2;
        res.push(tmp % 2);
        tmp /= 2;
        res.push(tmp % 2);
        tmp /= 2;
    }
    int tmp =s[0]-'0';
    if(tmp>=4){
        res.push(tmp % 2);
        tmp /= 2;
        res.push(tmp % 2);
        tmp /= 2;
        res.push(1);
    }
    else if(tmp>=2){
        res.push(tmp % 2);
        tmp /= 2;
        res.push(1);
    }
    else{
        res.push(tmp);
    }
    while(!res.empty()){
        cout<<res.top();
        res.pop();
    }
    cout<<'\n';

    return 0;
}