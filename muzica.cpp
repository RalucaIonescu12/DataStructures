#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
long long N,M,A,B,C,D,E,x,nr=0,melodie,i;

ifstream f("muzica.in");
ofstream g("muzica.out");
unordered_set<long long> mel(100005);
int main()
{
    f>>N>>M>>A>>B>>C>>D>>E;
    //N=nr mel Vasile
    //M=nr mel dj random
    for(i=0;i<N;i++)
    {
        f>>x;
        mel.insert(x);
    }
    if(mel.find(A)!=mel.end())
    {
        nr++;
        mel.erase(A);
    }
    if(mel.find(B)!=mel.end())
    {
        nr++;
        mel.erase(B);
    }
    for(i=3;i<=M;i++)
    {
        melodie= (C * B + D * A)%E;
        if(mel.find(melodie)!=mel.end())
        {
            nr++;
            mel.erase(melodie);
        }
        A=B;
        B=melodie;
    }
    g<<nr;
    return 0;
}
