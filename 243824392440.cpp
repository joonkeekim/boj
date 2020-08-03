#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++)
            cout<<" ";
        cout<<"*";
        if(i!=0){
            for(int j=0;j<2*i-1;j++)
            cout<<" ";
        cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=0;i<2*n-1;i++)
        cout<<"*";
    //int len=2*n-1;
    /*for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++)
            cout<<" ";
        for(int j=0;j<i;j++)
            cout<<"* ";
        cout<<"*"<<"\n";
    }
        
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            cout<<" ";
        for(int j=0;j<len-2*i;j++)
            cout<<"*";
        
        cout<<"\n";
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n-i;j++)
            cout<<" ";
        for(int j=0;j<2*i+1;j++)
            cout<<"*";
        
        cout<<"\n";
    }
    for(int i=0;i<len;i++){
        if(i<n-1){
            for(int j=n-i-1;j>0;j--)
                cout<<" ";
            for(int j=0;j<i+1;j++)
                cout<<"*";
        }
        else if(i>n-1){
            for(int j=0;j<i-n+1;j++)
                cout<<" ";
            for(int j=i-n;j<n-1;j++)
                cout<<"*";
        }
        else{
            for(int i=0;i<n;i++)
                cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++)
            cout<<"*";
        for(int j=0;j<2*n-2*(i+1);j++)
            cout<<" ";
        for(int j=0;j<i+1;j++)
            cout<<"*";
        cout<<"\n";
    }
    for(int i=n+1;i<=2*n-1;i++){
        for(int j=0;j<(2*n-i);j++)
            cout<<"*";
        for(int j=0;j<2*i-2*n;j++)
            cout<<" ";
        for(int j=0;j<(2*n-i);j++)
            cout<<"*";
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=n-i-1;j>0;j--){
            cout<<" ";
        }
        for(int k=1;k<=2*(i+1)-1;k++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int k=n-i-1;k>0;k--){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }*/
    
}