#include <iostream>

using namespace std;

int main() 
{
    int n,a[100],set[100],top=0;
    cin>>n;
    for(int i=0;i<n;i++) //This loop is to eliminate the duplicates and store in new array
    {
        cin>>a[i];
        int l=top;
        while(l>=0)
        { 
            if(a[i]==set[l])
            {
                break;
            }
            l--;
        }
        if(l==-1)
        {
            set[top++]=a[i];
        }
        
    }
    for(int i=0;i<top;i++)
    {   int count=0;
        cout<<set[i]<<"-->";
        for(int j=0;j<n;j++)
        {
            if(set[i]==a[j])
            {
                count++;
            }
            
        }
        cout<<count<<endl;
    }
}
