#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//국어, 영어, 수학
struct info
{
    string name;
    int guk;
    int eng;
    int math;
};
info person[100000];
bool cmp(const info &a, const info &b)
{ //a가 b보다 앞에 올 조건!!!을 return한다.
    if (a.guk > b.guk)
    {
        return true;
    }
    else if (a.guk == b.guk)
    {
        if (a.eng < b.eng)
        {
            return true;
        }
        else if (a.eng == b.eng)
        {
            if (a.math > b.math)
            {
                return true;
            }
            else if (a.math == b.math)
            {
                if(a.name < b.name){
                    return true;
                }
            }
        }
    }
    return false;
}

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin.tie(0);
    for (int i = 0; i < n; i++)
    {
        cin >> person[i].name >> person[i].guk >> person[i].eng >> person[i].math;
    }
    sort(person, person + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << person[i].name<<"\n";
    }
}