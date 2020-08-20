#include <iostream>
#include <cstring>
using namespace std;

int N;
char arr[6562][6562];

void star(int s1, int s2, int len)
{
    if(len == 3){
        arr[s1][s2] = '*';
        arr[s1+1][s2-1] = '*';
        arr[s1+1][s2+1] = '*';
        for(int i = -2;i<3;i++){
            arr[s1+2][s2+i] = '*';
        }
        return;
    }
    star(s1,s2,len/2);
    star(s1+len/2,s2-len/2,len/2);
    star(s1+len/2,s2+len/2,len/2);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int M = 2*N - 1;
    for (int i = 1; i <= N; i++)
    {
        memset(arr[i], ' ', sizeof(char) * (M + 1));
    }
    star(1, N, N);
    for (int i = 1; i <= N; i++)
    {
        cout<<arr[i];
        cout<<'\n';
    }
}