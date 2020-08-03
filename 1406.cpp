#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

list<char> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, len;
    string tmp;
    char temp;
    cin >> tmp;
    for (char c : tmp)
    {
        res.push_back(c);
    }
    cin >> n;

    auto curr = res.end();
    
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == "L")
        {
            if (curr != res.begin())
                curr--;
        }
        else if (tmp == "D")
        {
            if (curr != res.end())
                curr++;
        }
        else if (tmp == "B")
        {
            if (curr != res.begin())
            {
                curr--;
                //cout<<*res.erase(curr);
                curr = res.erase(curr);//다음거를 가리켜야되니까
            }
        }
        else
        {
            cin >> temp;

            res.insert(curr, temp);
        }
    }
    for(char k:res){
        cout<<k;
    }
    cout<<'\n';
}