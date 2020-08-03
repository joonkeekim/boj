#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int n;
char tmp[100];
string temp;
stack<int> sta;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /*fgets(tmp,100,stdin);
        cout<<tmp<<'\n';
        if(strcmp(tmp,"top")){

        }
        else if(strcmp(tmp,"pop")){

        }
        else if(strcmp(tmp,"size")){

        }
        else if(strcmp(tmp,"empty")){

        }
        else{
            int k = atoi(tmp+5);
            cout<<k<<'\n';
            //printf("%d",k);
        }*/
        cin >> temp;
        if (temp == "push")
        {
            cin >> temp;
            sta.push(stoi(temp));
            //cout<<sta.top()<<'\n';
        }
        else if (temp == "pop")
        {
            if (!sta.empty())
            {
                int k = sta.top();
                sta.pop();
                cout << k << '\n';
            }
            else{
                cout<<"-1\n";
            }
        }
        else if (temp == "size")
        {
            cout << sta.size() << '\n';
        }
        else if (temp == "empty")
        {
            if (sta.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else
        {
            if (sta.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << sta.top() << '\n';
            }
        }
        //cout << temp << '\n';
    }

    //scanf("%d",&n);
    return 0;
}