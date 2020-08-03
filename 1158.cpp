#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    queue<int> q;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    cout << '<';

    while(true){
        if(q.size() == 1) break;
        for(int i = 0;i<k-1;i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        cout<<q.front()<<", ";
        q.pop();
        
    }
    cout<<q.front()<<">\n";

    return 0;
}