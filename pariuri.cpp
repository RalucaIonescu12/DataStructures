#include <iostream>
#include <unordered_map>
#include<fstream>

using namespace std;

ifstream f("pariuri.in");
ofstream g("pariuri.out");

unordered_map<int, int> PR;

int N,nr,timp,bani;

int main()
{
    f>>N;
    for (int i=1;i<=N;i++)
    {
        f>>nr;
        for(int j = 0;j<nr;j++)
        {
            f>>timp>>bani;
            PR[timp]+=bani;
        }
    }
    g<<PR.size()<<endl;
    for(auto x:PR)
        g<<x.first<<" "<<x.second<<" ";
    return 0;
}