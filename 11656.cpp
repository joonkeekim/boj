#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string tmp[1002];
    char temp[1002];
    
    cin>>temp;
    int len = strlen(temp);
    for(int i = 0;i<len;i++){
        tmp[i] = temp+i;
        //cout<<tmp[i]<<'\n';
    }
    
    sort(tmp,tmp+len);
    
    for(int i = 0;i<len;i++){
        //tmp[i] = temp+i;
        cout<<tmp[i]<<'\n';
    }
    //const char *temp;
    //temp = tmp.c_str();
    /*string res[1001];
    for(int i =0;i<tmp.length();i++){
        res[i] = tmp[i];
    }*/
    //cout<<res[3];
}