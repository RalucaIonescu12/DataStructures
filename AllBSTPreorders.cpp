//// #include <bits/stdc++.h>
//#include<iostream>
//#include<stack>
//#include<vector>
//#include <algorithm>
//using namespace std;
//vector<int>per;
//int n;
//int i;
//stack<int> s;
//int Preordine()
//{
//      stack<int> s;
//    int root = INT_MIN;
//    cout<<root;
//    for (int i=0; i<n; i++)
//    {
//        //aici verificam daca in subarborele drept
//        //elementul este mai mic decat radacina
//        if (per[i] < root) {
//            while (!s.empty())
//                s.pop();
//            return 0;
//        }
//        //adaug toate elementele cat de in stanga pot si
//        //cand dau de un nr in vector mai mare ca radacina ins ca
//        //sunt in subarborele drept si schimb radacina cu ultimul element
//        //din stiva care e mai mic decat acel nr din vector
//        while (!s.empty() && s.top()<per[i])
//        {
//            root = s.top();
//            s.pop();
//        }
//
//        s.push(per[i]);
//    }
//    while (!s.empty())
//        s.pop();
//    return 1;
//}
//void afisare()
//{
//    for(int i=0; i<n;i++)
//        cout<<per[i]<<" ";
//    cout<<'\n';
//}
//void AllBstPreorders()
//{
//    for (i = 1; i <= n; i++)
//        per.push_back(i);
//    afisare();
//    while (next_permutation(per.begin(), per.end()))
//        if (Preordine()) afisare();
//}
//int main()
//{
//    cin>>n;
//    AllBstPreorders();
//    return 0;
//}






#include <bits/stdc++.h>
using namespace std;
vector<int>per;
int n;
int Preordine(int st ,int dr)
{
    if(st>=dr)
        return 1;
    else
    {
        int root=per[st];
        int index=st+1;
        //parcurg elem din stanga cat timp sunt mai mici decat radacina
        while(per[index]<root && index<=dr)
            index++;
        //cand gasim primul elem mai mare decat radacina toate elem din
        //dr sunt mai mari ca radacina
        for(int i=index+1; i<=dr; i++)
            if(per[i]<root) //daca in subarb drept e un element mai mic decat
                return 0;   //radacina atunci ma opresc
        return Preordine(st+1, index-1) && Preordine(index, dr);
    }
}
void afisare()
{
    for(int i=0; i<n;i++)
        cout<<per[i]<<" ";
    cout<<'\n';
}
void AllBstPreorders()
{
    int i;
    for (i = 1; i <= n; i++)
        per.push_back(i);
    afisare();
    while (next_permutation(per.begin(), per.end()))
        if (Preordine(0, n-1)) afisare();
}
int main()
{
    cin>>n;
    AllBstPreorders();

    return 0;
}
