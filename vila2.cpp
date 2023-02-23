#include <iostream>
#include <deque>
#include <fstream>
using namespace std;
deque <int> deqmin;
deque <int> deqmax;
ifstream f("vila2.in");
ofstream g("vila2.out");
int n,k,i,x,v[100001],maxim;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        while(!deqmin.empty() && v[i]<=v[deqmin.front()])
            deqmin.pop_front();
        deqmin.push_front(i);
        while(!deqmax.empty() && v[i]>=v[deqmax.front()])
            deqmax.pop_front();
        deqmax.push_front(i);
        if(i-deqmin.back()>=k+1)
            deqmin.pop_back();
        if(i-deqmax.back()>=k+1)
            deqmax.pop_back();
        if(i>=k+1)
        {
            x=v[deqmax.back()]-v[deqmin.back()];
            if(maxim<x)
                maxim=x;
        }
    }
    g<<maxim;
    return 0;
}
