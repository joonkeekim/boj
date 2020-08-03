#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    /*vector<int> v;
    vector<int> so;
    v.resize(n + 1);

    v[1] = 1;

    long long i = 2;
    while (1)
    {
        if (v[i] == 0)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                if (v[j] == 0)
                {
                    if (j % i == 0)
                        v[j] = 1;
                }
            }
        }
        i++;
        if (i*i > n + 1)
            break;
    }
    for(int i = 2;i<n+1;i++){
        if(v[i] == 0){
            so.push_back(i);
        }
    }*/
    int a = 2;
    while(n!=1){
        if(n%a == 0){
            cout<<a<<'\n';
            n/=a;
        }
        else{
            a++;
        }
    }


    return 0;
}