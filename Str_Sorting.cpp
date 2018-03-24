#include <iostream>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if((a[pos].length()==a[j].length()&&a[pos]>a[j])||(a[pos].length()>a[j].length()))
            {
                pos=j;
            }
        }
        string t=a[pos];
        a[pos]=a[i];
        a[i]=t;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
