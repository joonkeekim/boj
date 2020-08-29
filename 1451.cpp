#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[8];
    arr[0] = cin.get()-'0';
    for (int i = 1; i < 8; i++)
    {
        int tmp = cin.get()-'0';
        arr[i] = arr[i-1] + tmp;
    }
    for (int i = 1; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            int t1 = arr[i-1];
            int t2 = arr[j-1] - t1;
            int t3 = arr[7] - t1 - t2;
            
            if(t1*t2*t3 == 108){
                cout<< i<< " "<<j;
            }
        }
    }

    return 0;
}