#include <iostream>
using namespace std;
int main() 
{
    int n,base;
    cin>>n>>base;
    if(base<2||base>16)
    {
        cout<<"Invalid Entry";
        return 0;
    }
    int a[100],i=0;       //Integer array 'a' is for storing the integers
    char b[100];          //Charecter array 'b' is used for storing values which are greater than 9 
    while(n)
    {
        int temp=n%base;
        if(temp<10)
        {
            a[i++]=temp;  // values <=9 are stored in 'a' array 
        }
        else
        {
            char x='A'+temp-10;
            a[i]=-1;     // values >9 are stored in 'b' array
            b[i++]=x;
        }
        n=n/base;
     }
    for(int j=i-1;j>=0;j--)   
    {
        if(a[j]!=-1)
            cout<<a[j];
        else
            cout<<b[j];
    }
}
