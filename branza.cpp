#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
struct saptamana{
    long long pret, cant;
} v[100000];
deque <int> deq;
ifstream f("branza.in");
ofstream g("branza.out");
int main()
{
    long long Nsapt,termen, cost = 0;
    int Pdep,i;
    f>>Nsapt>>Pdep>>termen;
    for(i=0;i<Nsapt;i++)
    {
        f>>v[i].pret>>v[i].cant;
        if(!deq.empty() && i-deq.back()>termen)
            deq.pop_back();

        while(!deq.empty() && v[i].cant*v[i].pret+v[deq.front()].pret*v[deq.front()].cant<v[deq.front()].pret*(v[deq.front()].cant+v[i].cant)+Pdep*(i-deq.front())*v[i].cant)
            deq.pop_front();
        deq.push_front(i);
        cost+=v[deq.back()].pret*v[i].cant+(i-deq.back())*Pdep*v[i].cant;
    }
    g<<cost;
    return 0;
}