#include <iostream>
#include<fstream>
#include<queue>
#include<set>
using namespace std;
string op;
priority_queue<pair<int,pair<int,int>>>mindif;
set<int> z;
ifstream f("zeap.in");
ofstream g("zeap.out");
//mindif : dif,(x,y)
void insereaza(int x)
{
    if (z.find(x)==z.end())
    {
        z.insert(x);
        if(z.size()>1)
        {
            auto index = z.find(x);
            if(index!=z.begin()) //daca exista alt element in stanga lui x
            {
                index--;
                mindif.push(make_pair((-1)*abs(x-*index),make_pair(*index, x)));
                //adaug dif dintre x si elem din stanga
            }
            index = z.find(x);
            if(index!=z.end()) //daca exista alt element in dr lui x
            {
                index++;
                mindif.push(make_pair((-1)*abs(*index - x),make_pair(*index, x)));
                //adaug dif dintre x si elem din dr
            }
        }
    }
}
void sterge(int x)
{
    if(z.find(x)==z.end()) g<<-1<<'\n';
    else
    {
        auto index=z.find(x);
        auto dr = index;
        dr++;
        if(index==z.begin() || dr==z.end()) //eliminam primul/ultimul element
        {
            z.erase(x);
        }
        else
        {
            auto st = index;
            st--;
            if (dr != z.end() and index != z.begin())
                mindif.push(make_pair((-1)*abs(*dr - *st),make_pair(*st, *dr)));
            z.erase(x);
        }

    }
}

void cauta(int x)
{
    if(z.find(x)!=z.end())
        g<<1<<'\n';
    else g<<0<<'\n';
}
void maxDIF()
{
    if(z.size()>1)
    {
        auto dr=z.end();
        dr--;
        auto st=z.begin();
        g<<*dr-*st<<'\n';
    }
    else g<<-1<<'\n';
}
void minDIF()
{
    if(z.size()>1)
    {
       while(z.find(mindif.top().second.first) == z.end() or z.find(mindif.top().second.second) == z.end())
            mindif.pop(); //se sterg din mindif perechile a caror elemente nu mai exista in z
        g<<(-1)*mindif.top().first<<'\n';
    }
    else g<<-1<<'\n';
}
int main()
{   int x;
    while(f>>op)
    {
        if(op!="MAX" && op!="MIN")
        {
            f>>x;
            if(op=="I")
                insereaza(x);//daca exista deja nu face nmc
            else if (op=="S")
                sterge(x);  //afiseaza -1 daca nu exista
            else if(op=="C")
                cauta(x); //0 nu exista, 1 exista
        }
        else if(op=="MAX")
            maxDIF();
        else if(op=="MIN")
            minDIF();
    }

    return 0;
}
