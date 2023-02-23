#include <iostream>
#include <unordered_map>
#include <tuple>
#include <fstream>

using namespace std;


int main()
{   ifstream f("loto.in");
    ofstream g("loto.out");
    unordered_map<int, tuple<int,int,int>>M;
    tuple<int,int,int> tuplu;
    int N,S,i,suma,j,k,v[101];
    f>>N>>S;
    for(i=0;i<N;i++) f>>v[i];

    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            for(k=j;k<N;k++)
            {
                suma = v[i]+v[j]+v[k];
                M[suma]=make_tuple(v[i],v[j],v[k]);
            }
        }
    }
    int ok=0;
    unordered_map<int, tuple<int,int,int>>::iterator itr;
    for(itr=M.begin();itr!=M.end() && ok==0;itr++)
    {
        if(M.find(S-itr->first)!=M.end())
        {
            tuplu=M[S-itr->first];
            g<<get<0>(tuplu)<<" "<<get<1>(tuplu)<<" "<<get<2>(tuplu)<<" ";
            tuplu=itr->second;
            g<<get<0>(tuplu)<<" "<<get<1>(tuplu)<<" "<<get<2>(tuplu);
            ok=1;
        }

    }
    if(ok==0) g<<-1;
    return 0;
}
