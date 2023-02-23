#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream f("heapuri.in");
ofstream g("heapuri.out");
const int maxn=200010;
int N, l,  nr;
int  Heap[maxn], Pos[maxn];
long long A[maxn];
//A=vectorul cu toate valorile inserate in ordinea inserarii
//Pos= pozitia din heap unde se gaseste elementul A[i]
//Heap[i]=indicele elementului din A

void inserare(int x)  //urca
{
    int aux;
    while (x/2 && A[Heap[x]]<A[Heap[x/2]])
    {
        aux = Heap[x];
        Heap[x] = Heap[x/2];
        Heap[x/2] = aux; //urca valoarea mai mica mai sus

        Pos[Heap[x]] = x;
        Pos[Heap[x/2]] = x/2;
        x =x/2;
    }

}

void stergere(int x) //coboara
{
    int aux, y = 0;
    while (x != y)
    {
        y = x;
        if (y*2<=l  && A[Heap[x]]>A[Heap[y*2]]) x = y*2;
        if (y*2+1<=l && A[Heap[x]]>A[Heap[y*2+1]]) x = y*2+1;

        aux = Heap[x];
        Heap[x] = Heap[y];
        Heap[y] = aux;

        Pos[Heap[x]] = x;
        Pos[Heap[y]] = y;
    }
}

int main()
{
    int i,op;
    long long x;
    f>>N;

    for (i=1; i<=N; i++)
    {
        f >> op;
        if (op < 3)f >> x;

        if (op == 1)
        {
            l++, nr++;
            A[nr] = x;
            Heap[l] = nr;
            Pos[nr] = l;
            inserare(l);
        }

        if (op == 2) {
            A[x] = -1;
            inserare(Pos[x]);

            Pos[Heap[1]] = 0;
            Heap[1] = Heap[l--];
            Pos[Heap[1]] = 1;

            if (l > 1) stergere(1);
        }

        if (op == 3) g<<A[Heap[1]]<<'\n';

    }
    return 0;
}
