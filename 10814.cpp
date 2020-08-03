#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct person
{
    int age;
    string name;
};
bool compare(const person &a, const person &b)
{
    return a.age < b.age;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<person> info;
    info.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&info[i].age);
        cin>>info[i].name;
    }
    stable_sort(info.begin(),info.end(),compare);
    for(int i=0;i<n;i++){
        cout << info[i].age << ' ' << info[i].name << '\n';
    }
}