#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string pos[n],neg[n],s;
    int posn=0,negn=0;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s[0]=='-')
            neg[negn++]=s;
        else
            pos[posn++]=s;
     }
    for(int i=0;i<negn;i++)//sorting negative numbers
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(neg[j]<neg[j+1])
            {
                string t=neg[j];
                neg[j]=neg[j+1];
                neg[j+1]=t;
            }
        }
    }
    for(int i=0;i<posn;i++)//sorting positive numbers
    {
        for(int j=0;j<posn-i-1;j++)
        {
            if(pos[j]>pos[j+1])
            {
                string t=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=t;
            }
        }
    }
    for(int i=0;i<negn;i++)
    {
        cout<<neg[i]<<" ";
    }
    for(int i=0;i<posn;i++)
    {
        cout<<pos[i]<<"  ";
    }
    
    
  


}
