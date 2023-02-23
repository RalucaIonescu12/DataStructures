#include <iostream>
#include<fstream>
#include <cstring>
#include<vector>
#include <bits/stdc++.h>
#include<cmath>
#include<stack>
using namespace std;
ifstream f("paranteze.in");
ofstream fout("paranteze.out");
int poz[1000003];
stack<char> s;
int main()
{
    int n,i;
    char x;
    f>>n;
    vector<char> v;
    for(i=0; i<n; i++)
    {
        f>>x;
        v.push_back(x);
    }
    int maxim=0;

    for (i=0; i<n; i++)
    {
        if (v[i]=='{' || v[i]=='[' ||v[i]=='(')
            {s.push(v[i]);}
        else
        {
            if (!s.empty())
            {
                if(v[i]== ')')
                {
                    x = s.top();
                    if (x == '(')
                    {
                        poz[s.size()-1]+=poz[s.size()]+2;

                        if(maxim<poz[s.size()-1]) maxim=poz[s.size()-1];
                        poz[s.size()]=0;
                        s.pop();
                    }
                    else  s.push(v[i]);
                }
                else if(v[i]== ']')
                {
                    x = s.top();
                    if (x == '[' )
                    {
                        poz[s.size()-1]+=poz[s.size()]+2;

                        if(maxim<poz[s.size()-1]) maxim=poz[s.size()-1];
                        poz[s.size()]=0;
                        s.pop();
                    }
                    else  s.push(v[i]);
                }
                else if(v[i]== '}')
                {
                    x = s.top();
                    if (x == '{')
                    {
                        poz[s.size()-1]+=poz[s.size()]+2;

                        if(maxim<poz[s.size()-1]) maxim=poz[s.size()-1];
                        poz[s.size()]=0;
                        s.pop();
                    }
                    else  s.push(v[i]);
                }
                else s.push(v[i]);
            }
            else s.push(v[i]);
        }
    }
    fout<<maxim;
    return 0;
}
