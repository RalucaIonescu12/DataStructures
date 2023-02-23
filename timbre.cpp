#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream f("timbre.in");
ofstream g("timbre.out");

int N,M,K,minn,i,m,c;
//N=nr pagini
//M=nr intervale
//k =lingime subsecv
long long Smin=0;

int main()
{
    f>>N>>M>>K;
    vector<pair <int,int>> interval(10089);
    for(i=0;i<M;i++)
        f>>interval[i].first>>interval[i].second;
    while(N>0)
    {
        int j=-1;
        minn=10000;
        for(i=0;i<M;i++)
            if(interval[i].first>=N && interval[i].second<minn && interval[i].first!=-1)
            {
                j=i;
                minn=interval[i].second;
            }
        Smin=Smin+minn;
        interval[j].first=-1;
        N=N-K;
    }
    g<<Smin;
    return 0;
}