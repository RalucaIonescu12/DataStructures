#include <iostream>
#include <fstream>
using namespace std;
ifstream f("datorii.in");
ofstream g("datorii.out");
int a[60006];
void update(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        a[nod]=val;
        return;
    }
    int mij=(st+dr)/2;
    if(poz<=mij)  update(2*nod, st,mij, poz,val);//subarb stang
    else  update(2*nod+1,mij+1,dr,poz,val);//subarb drept

    a[nod]=a[2*nod]+a[2*nod+1]; //suma fiilor
}
void achitare(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        a[nod]=a[nod]-val; //se scade din acel nod valoarea achitata
        return;
    }
    int mij=(st+dr)/2;

    if(poz<=mij)   achitare(2*nod, st,mij, poz,val);

    else  achitare(2*nod+1,mij+1,dr,poz,val);

    a[nod]=a[2*nod]+a[2*nod+1];
}
int query(int nod, int st, int dr, int x,int y)
{
    if(x<=st && dr<=y) return a[nod];

    int suma1=0, suma2=0;

    int mij =(st+dr)/2;

    if(x<=mij)  suma1=query(2*nod,st,mij,x,y);

    if(y>mij)  suma2=query(2*nod+1, mij+1,dr, x ,y);

    return suma1+suma2;
}

int main()
{
    int n,m,cod,ziua,val,p,q,x,i;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>x;
        update(1,1,n,i,x);
    }
    for(i=1;i<=m;i++)
    {
        f>>cod;
        if(cod==0)  //achitare
        {   f>>ziua>>val;
            achitare(1,1,n,ziua,val);
        }
        if(cod==1)  //interogare
        {   f>>p>>q;
            g<<query(1,1,n,p,q)<<'\n';
        }
    }
    return 0;
}