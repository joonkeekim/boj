#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,sum=0;
    cin>>N;
    int arr[8];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    //next_permutation은 오름차순이어야 정확하게 동작한다.
    //명심할것!
    sort(arr,arr+N);
    do{
        int tmp=0;
        for(int i=0;i<N-1;i++){
            tmp += abs(arr[i]-arr[i+1]);
        }
        sum = max(tmp,sum);
    }while(next_permutation(arr,arr+N));
    cout<<sum<<'\n';

    return 0;
}
