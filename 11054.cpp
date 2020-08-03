#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;



int main(){
    int n,Max=0;
    cin>>n;
    int arr[1001];
    int dp1[1001];
    int dp2[1001];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        dp1[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp1[i]=max(dp1[i],(dp1[j]+1));
                //cout<<dp1[j]+1<<"!!"<<endl;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        dp2[i]=1;
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                dp2[i]=max(dp2[i],(dp2[j]+1));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp1[i]<<" "<<dp2[i]<<endl;
    }
    for(int i=0;i<n;i++){
        Max=max(dp1[i]+dp2[i],Max);
        //cout<<Max<<endl;
    }

    cout<<Max-1;
    
}