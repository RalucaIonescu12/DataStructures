#include <iostream>
#include<fstream>
using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");
int i,N,k,front=1,rear,deq[5000001];
long long suma,v[5000001];
int main()
{
    f>>N>>k;
   for(i=1;i<=N;i++)f>>v[i];
   for(i=1;i<=N;i++)
   {
       while(front<=rear && v[i]<v[deq[rear]])rear--;
       rear++;
       deq[rear]=i;
       if(i-k==deq[front])front++;
       if(k<=i)suma+=v[deq[front]];
   }
    g<<suma;
    return 0;
}
