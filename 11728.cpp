#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    vector<int> v1(N);
    vector<int> v2(M);
    vector<int> v3(N+M);
    for(int n=0;n<N;n++){
        cin>>v1[n];
    }
    for(int m=0;m<M;m++){
        cin>>v2[m];
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<N+M;i++){
        if(cnt1>=N){
            v3[i]=v2[cnt2++];
            continue;
        }
        if(cnt2>=M){
            v3[i]=v1[cnt1++];
            continue;
        }
        if(v1[cnt1]<v2[cnt2]){
            v3[i]=v1[cnt1++];
        }
        else{
            v3[i]=v2[cnt2++];
        }
    }
    for(int i=0;i<N+M-1;i++){
        cout<<v3[i]<<' ';
    }
    cout<<v3[N+M-1]<<'\n';

    return 0;
}