#include<bits/stdc++.h>
using namespace std;
bool estePreordine(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;

    int root = INT_MIN;

    for (int i=0; i<n; i++)
    {
        //aici verificam daca in subarborele drept
        //elementul este mai mic decat radacina
        if (pre[i] < root)
            return false;

        //adaug toate elementele cat de in stanga pot si
        //cand dau de un nr in vector mai mare ca radacina ins ca
        //sunt in subarborele drept si schimb radacina cu ultimul element
        //din stiva care e mai mic decat acel nr din vector

        cout<<"pre["<<i<<"]= "<<pre[i]<<endl;
        while (!s.empty() && s.top()<pre[i])
        {   cout<<"pre["<<i<<"]= "<<pre[i]<<"si top= "<<s.top()<<endl;
            root = s.top();
            cout<<"root= "<<root<<endl;
            s.pop();
        }

        s.push(pre[i]);
    }
    return true;
}


int main()
{   int N;
    cin>>N;







    int pre1[] = {5,3,2,4,6,1,7};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true\n":
    cout << "false\n";

    int pre2[] = {1,2,3};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true\n":
    cout << "false\n";

    return 0;
}