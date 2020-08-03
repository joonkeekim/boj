//입력받은대로 출력하기
#include <iostream>
using namespace std;

int main(){
    for(int i=0;i<100;i++){
        char a[101];
        if(cin.getline(a,101,'\n')) cout<<a<<endl;
    }
}