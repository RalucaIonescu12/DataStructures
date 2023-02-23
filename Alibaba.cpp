#include <iostream>
#include<fstream>
#include<deque>
using namespace std;
deque<int> nr;
ifstream f("alibaba.in");
ofstream g("alibaba.out");
char c;
int n,k,i,cif;
int main()
{
    f>>n>>k;
    f.get();
    i=-1;

    while(f.get(c))
    {
        cif=c-'0';
        i++;
        while(!nr.empty() && (n-i+nr.size()>n-k) && nr.back()<cif)
        {
            nr.pop_back();
        }
        nr.push_back(cif);
    }
    i=1;
    while(!nr.empty() && i<=n-k)
    {
        g<<nr.front();
        nr.pop_front();
        i++;
    }
    return 0;
}
