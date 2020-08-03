#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        arr[temp]++;
    }

    for(int i=0;i<10001;i++){
        for(int j=0;j<arr[i];j++){
            printf("%d\n",i);
        }
    }

}

