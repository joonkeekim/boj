#include<iostream>
using namespace std;

int main(){
    int a,b,sum=0;
    cin>>a>>b;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<a-1;i++){
        sum+=month[i];
    } 
    sum+=b;
    switch(sum%7){
        case 0: cout<<"SUN"<<endl; break;
        case 1: cout<<"MON"<<endl; break;
        case 2: cout<<"TUE"<<endl; break;
        case 3: cout<<"WED"<<endl; break;
        case 4: cout<<"THU"<<endl; break;
        case 5: cout<<"FRI"<<endl; break;
        case 6: cout<<"SAT"<<endl; break;
    }

}