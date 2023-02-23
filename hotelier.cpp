#include <iostream>
#include <cmath>
using namespace std;
int camere[11];
int n,i,cif,j;
char x;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x=='L')
        {
            for(j=0;j<=9;j++)
                if(camere[j]==0){
                    camere[j]=1;
                    break;
                }
        }
        else if (x=='R')
        {
            for(j=9;j>=0;j--)
                if(camere[j]==0) {
                    camere[j] = 1;
                    break;
                }
        }
        else {
            cif = x - '0';
            camere[cif] = 0;

        }
    }
    for(i=0;i<=9;i++)cout<<camere[i];
    return 0;
}
