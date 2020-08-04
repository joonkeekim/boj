#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> v;
void forward(int i){
    if(i == -1) return;
    char k = i+'A';
    cout<<k;
    forward(v[i].first);
    forward(v[i].second);
}
void middle(int i){
    if(i == -1) return;
    middle(v[i].first);
    char k = i+'A';
    cout<<k;
    middle(v[i].second);
}
void backward(int i){
    if(i == -1) return;
    backward(v[i].first);
    backward(v[i].second);
    char k = i+'A';
    cout<<k;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    v.resize(N);
    for(int i = 0;i<N;i++){

        char a,b,c;
        cin>>c>>a>>b;
        int q = c-'A';
        if(a != '.'){
            v[q].first = a-'A';
        }
        else{
            v[q].first = -1;
        }
        if(b != '.'){
            v[q].second = b-'A';
        }
        else{
            v[q].second = -1;
        }
    }
    forward(0);
    cout<<'\n';
    middle(0);
    cout<<'\n';
    backward(0);
    cout<<'\n';
    return 0;
}