#include <fstream>
#include<iostream>
using namespace std;
#define dim 100001


int MaxArb[4*dim+66];
int inceput, final, maxim;
int poz,val;

inline int Maxim(int a, int b)
{
    if ( a > b ) return a;
    return b;
}


void Update(int nod, int st, int dr)
{
    if ( st == dr )  //inseamna ca nodul nu are fii si
                    // nodul va fi chiar val aceea
                    // adica val maxima
    {
        MaxArb[nod] = val;
        return;
    }

    int mij = (st+dr)/2;
    if ( poz <= mij )Update(2*nod,st,mij); //ins ca poz se afla in subarb stang
    else Update(2*nod+1,mij+1,dr);//subarb drept
    MaxArb[nod] = Maxim( MaxArb[2*nod], MaxArb[2*nod+1] );
    //in arbore pe pozitia nod se pune maximul dintre cei doi fii


    //practic pune nodul nou jos si apoi pana sus schimba
    //valorile din noduri cu maximul dintre cei doi fii
}

void Query(int nod, int st, int dr)
{
    if ( inceput <= st && dr <= final )
    {
        if ( maxim < MaxArb[nod] ) maxim = MaxArb[nod];
        return;
    }

    int mij = (st+dr)/2;
    if ( inceput <= mij )Query(2*nod,st,mij);
    if ( mij < final )Query(2*nod+1,mij+1,dr);
}


int main()
{   int i,M,N,x,a,b;
    ifstream f("arbint.in");
    ofstream g("arbint.out");
    f>>N>>M;
    for (i = 1; i <= N; i++ )
    {   f>>x;
        poz = i, val = x;
        Update(1,1,N);
    }

    for (i = 1; i <= M; i++ )
    {
        f>>x>>a>>b;
        if ( x == 0 )
        {
            maxim = -1;
            inceput = a, final = b;
            Query(1,1,N);
            g<<maxim<<'\n';
        }
        else
        {
            poz = a, val = b;
            Update(1,1,N);
        }
    }
}
