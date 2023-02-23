#include<fstream>
#include<vector>
using namespace std;
ifstream f("hashuri.in");
ofstream g("hashuri.out");
int i,op,N;
long long x;
const int m=666013;
vector <int> v[m];
vector<int>::iterator gasire(long long x)
{
    vector<int>::iterator i;
    int lista = x % m;
    for(i=v[lista].begin();i!=v[lista].end();i++)
        if(*i==x)
            return i;
    return v[lista].end();

}
void inserare(long long x)
{
    int lista=x%m;
    if(gasire(x)==v[lista].end()) //x nu exista deja
        v[lista].push_back(x);
}
void stergere(long long x)
{
    int lista=x%m;
    vector<int>::iterator i=gasire(x);
    if( i != v[lista].end())
        v[lista].erase(i);
}
int main()
{
    f>>N;
    for(i=0;i<N;i++)
    {
        f>>op>>x;
        if(op==1)
            inserare(x);
        else if(op==2)
            stergere(x);
        else g<<(gasire(x)!=v[x%m].end())<<'\n';
    }
    return 0;
}