#include <iostream>
#include<fstream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
ifstream f("queue.in");
ofstream g("queue.out");
int n,num,i,j;
stack <int> s1;
stack <int> s2;
string comanda;
int main()
{

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>comanda;
        if(comanda[1]=='u')
        {
            num= 0;
            j=10;
            while (comanda[j] != ')')
            {
                num= num*10 + (comanda[j] - '0');
                j++;
            }
            s1.push(num);
            g<<i<<": read("<<num<<") "<<"push("<<1<<","<<num<<")";
            g<<"\n";
        }
        else
        {
            if (s2.empty())
            {   g<<i<<": ";
                while(s1.size()!=1)
                {
                    g<<"pop("<<1<<") "<<"push(2,"<<s1.top()<<") ";
                    s2.push(s1.top());
                    s1.pop();
                }
                g<<"pop("<<1<<") "<<"write("<<s1.top()<<") ";
                g<<"\n";
                s1.pop();
            }
            else
            {
                g<<i<<": pop("<<2<<") "<<"write("<<s2.top()<<")";
                g<<"\n";
                s2.pop();
            }
        }
    }

    return 0;
}

