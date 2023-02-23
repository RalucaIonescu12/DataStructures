#include <iostream>
#include <fstream>
#include<string>
using namespace std;
ifstream f("baruri.in");
ofstream g("baruri.out");
const int NMAX= 1e5 + 10;

int a[4*NMAX],v[NMAX],poz,val, inceput,final,suma;
string c;
void inserare(int nod, int st, int dr)
{
    if(st==dr)
    {
        a[nod]=v[st];
        return;
    }
    inserare(nod<<1, st, (st+dr)>>1);
    inserare(nod<<1|1,(st+dr)/2+1,dr);

    a[nod]=a[nod<<1]+a[nod<<1|1];
}

void update(int nod,int st,int dr)
{
    if(st==dr){
        a[nod]+=val;
        return;
    }
    int mij=(st+dr)>>1;
    if(poz<=mij) update(nod<<1, st,mij);
        else update(nod<<1|1,mij+1, dr);

        a[nod]=a[nod<<1]+a[nod<<1|1];
}

void query(int nod,int st,int dr)
{
    if(inceput<=st && dr<=final)
    {
        suma+=a[nod];
        return ;
    }
    int mij=(st+dr)/2;
    if(inceput<=mij) query(nod<<1, st,mij);

    if(final>mij) query(nod<<1|1, mij+1, dr);
}
void test()
{   int n;
    f >> n;
    f.get();
    getline(f,c);
    int nr=0;
    poz=0;
    int l=c.length();
    for(int i=0;i<l;i++){
        if(c[i]==' '){
            poz++;
            val=nr;
            v[poz]=nr;
            nr=0;
        }
        else
            nr=nr*10+(c[i]-'0');
    }
    v[++poz]=nr;
    int m,tip,b2;
    inserare(1,1,n);
    f>>m;
    for(int i=1;i<=m;i++)
    {
        f>>tip;
        if(tip==0)  //nr de prieteni in barurile de la distanta val
        {
            f>>poz>>val;
            inceput=max(1,poz-val);
            final=min(n,poz+val);
            suma=0;
            query(1,1,n);
            suma-=v[poz]; //nu se pun cei din aceeasi gasca(acelasi bar)
            g<<suma<<'\n';
        }
        else if(tip==1) //vin in bar
        {
            f>>val>>poz;
            update(1,1,n);
            v[poz]+=val;
        }
        else if(tip==2) //pleaca din bar
        {
            f>>val>>poz;
            val=-val;
            update(1,1,n);
            v[poz]+=val;
        }
        else
        {   //se muta x prieteni din barul 1 in barul 2
            f>>val>>poz>>b2;
            //pleaca din barul 1
            val=-val;
            update(1,1,n);
            v[poz]+=val;
            //se duc in barul 2
            val=-val;
            poz=b2;
            update(1,1,n);
            v[poz]+=val;
        }
    }
}
int main()
{
    int t;
    for(f>>t;t>=1;t--)
        test();
    return 0;
}

