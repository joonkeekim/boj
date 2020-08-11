#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v1;
vector<int> v2;
int N, M;

int lower_b(int i)
{
    int high = N;
    int low = 0;
    int mid;
    while (low < high)
    {
        mid = (low+high)/2;
        
        if(v1[mid]<v2[i]){
            low = mid +1;
        }
        else{
            high = mid;
        }
    }
    return high + 1;
}

int upper_b(int i)
{
    int high = N;
    int low = 0;
    int mid;
    while (low < high)
    {
        mid = (low+high)/2;
        
        if(v1[mid]<=v2[i]){
            low = mid +1;
        }
        else{
            high = mid;
        }
    }
    return high +1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v1.push_back(input);
    }
    sort(v1.begin(), v1.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        v2.push_back(input);
    }

    for (int i = 0; i < M; i++)
    {
        int low_b = lower_b(i);
        int high_b = upper_b(i);
        cout<<high_b-low_b<<' ';
    }
    cout<<'\n';

    return 0;
}