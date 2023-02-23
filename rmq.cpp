#include <vector>
#include<fstream>
#include<iostream>
using namespace std;

#define NMAX 100002
#define LMAX 18

long int rmq[LMAX][NMAX]; //matricea cu valorile minime
long int n,m;
long int nivel[NMAX];  //vector cu nivelul elementului in arbore
long int a[NMAX];      //vectorul cu elemntele
//pe nivelul 1 aflu minimul dintre 2 elem
//pe nivelul 2 aflu minimul dintre 3 elem
//pe nivelul 3 aflu minimul dintre 4 elem
//pe nivelul 4 aflu minimul dintre 5 elem
int main()
{
    ifstream f("rmq.in");
    ofstream g("rmq.out");

    long int i,j,l;
    long int x,y,diff,sh;
    f>>n>>m;

    for (i=1;i<=n;i++)f>>a[i];
    nivel[1]=0;
    for (i=2;i<=n;i++) nivel[i] = nivel[i/2] + 1;

    for (i=1;i<=n;i++) rmq[0][i]=a[i];

    for (i=1; (1 << i) <=n;i++)
        for (j=1; j<=n-(1<<i)+1 ;j++)
        {   //pe nivelul 1 se pun minimele  dintre rmq[0][j] si rmq[0][j+1]
            //pe nivelul 2 se pun minimele  dintre rmq[1][j] si rmq[1][j+2]
            //pe nivelul 3 se pun minimele  dintre rmq[2][j] si rmq[2][j+4]etc
            l=1<<(i-1);
            rmq[i][j]= min(rmq[i-1][j],rmq[i-1][j+l]);
        }

    for (i=1;i<=m;i++)
    {
        f>>x>>y;
        diff=y-x+1;
        l=nivel[diff];  //dif=nr de elemente in interval pt a sti pe ce
                        //rand al matricei trebuie sa ne uitam

        sh=diff - (1<<l);// ca sa stim care elemente de pe linie le comparam
                         //rmq[l][x] si rmq[l][x-sh]

        g<<min(rmq[l][x],rmq[l][x+sh])<<'\n';
    }
    return 0;
}
//rmq
//1 5 6 4 3
//1 5 4 3    //minimul dintre 1 5, 5 6,6 4, 4 3
//1 3        //minimul dintre 1 4, 5 3
