#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int sm, sc, si;
        cin >> sm >> sc >> si;

        int mem[100001] = {
            0,
        };
        char command[4096];
        char input[4096];
        int loop[4096];

        cin >> command;
        cin >> input;
        //cout<<command<<" "<<input;
        int arrptr = 0, coptr = 0, inptr = 0, max_oper = 0;
        stack<int> s;
        for (int i = 0; i < sc; i++)
        {
            if (command[i] == '[')
            {
                s.push(i);
            }
            else if (command[i] == ']')
            {
                int p = s.top();
                s.pop();
                loop[i] = p;
                loop[p] = i;
                //cout << p << " " << i << '\n';
            }
        }
        bool ter = false;
        for (int q = 0; q < 50000000; q++)
        {
            if (coptr >= sc)
            {
                cout << "Terminates\n";
                ter = true;
                break;
            }
            if (command[coptr] == '-')
            {
                mem[arrptr] = mem[arrptr] - 1 < 0 ? 255 : mem[arrptr] - 1; //modulo
            }
            else if (command[coptr] == '+')
            {
                mem[arrptr] = (mem[arrptr] + 1) % 256;
            }
            else if (command[coptr] == '<')
            {
                arrptr = arrptr - 1 < 0 ? sm - 1 : arrptr - 1;
            }
            else if (command[coptr] == '>')
            {
                arrptr = (arrptr + 1) % sm;
            }
            else if (command[coptr] == '[')
            {
                if (mem[arrptr] == 0)
                {
                    coptr = loop[coptr];
                }
            }
            else if (command[coptr] == ']')
            {
                if (mem[arrptr] != 0)
                {
                    coptr = loop[coptr];
                }
            }
            else if (command[coptr] == ',')
            {
                /*int c = inptr >= si ? 255 : (int)input[inptr];
                mem[arrptr] = c;
                inptr = inptr >= si ? inptr : inptr + 1;*/

                if (inptr >= si)
                {
                    mem[arrptr] = 255;
                }
                else
                {
                    mem[arrptr] = (int)input[inptr];
                }
                //inptr = inptr >= si ? inptr : inptr + 1;
                if (!(inptr >= si))//괄호가 문제였다.
                {
                    inptr++;
                }
            }
            coptr++;
            max_oper = coptr > max_oper ? coptr : max_oper;
        }
        if (!ter)
        {
            cout << "Loops " << loop[max_oper] << " " << max_oper << '\n';
        }
    }
    //modulo해야한다.
    return 0;
}