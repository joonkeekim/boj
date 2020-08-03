#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> deq;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        if(tmp == "push_front"){
            cin>>tmp;
            deq.push_front(stoi(tmp));
        }
        else if(tmp == "push_back"){
            cin>>tmp;
            deq.push_back(stoi(tmp));
        }
        else if(tmp == "pop_front"){
            if(!deq.empty()){
                cout<<deq.front()<<'\n';
                deq.pop_front();
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(tmp == "pop_back"){

            if(!deq.empty()){
                cout<<deq.back()<<'\n';
                deq.pop_back();
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(tmp == "size"){
            cout<<deq.size()<<'\n';
        }
        else if(tmp == "empty"){
            cout<<deq.empty()<<'\n';
        }
        else if(tmp == "front"){
            if(!deq.empty()){
                cout<<deq.front()<<'\n';
            }
            else{
                cout<<"-1\n";
            }
        }
        else{//back
            if(!deq.empty()){
                cout<<deq.back()<<'\n';
            }
            else{
                cout<<"-1\n";
            }
        }
        

    }
}