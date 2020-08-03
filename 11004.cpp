#include <iostream>
#include <algorithm>
using namespace std;
int arr[5000001];
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    //scanf("%d", &n);
    //scanf("%d", &k);
    k--;
    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &arr[i]);
        cin>>arr[i];
    }
    /*int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int i = start;
        int j = end;
        int mid = arr[(start + end) / 2];

        while (i < j)
        {
            if(arr[i] >= mid){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                j--;//넘어온거도 다시 검사하게 된다.
            }
            else{
                i++;
            }
        }
        if (arr[i] > mid)
            i--;
        if (k <= i)
            end = i;
        else
            start = i + 1;
    }*/ // 속도가 느려서 위의 방법은 안된다.
    nth_element(arr,arr+k,arr+n);
    cout<<arr[k]<<"\n";
    //printf("%d\n",arr[k]);
}