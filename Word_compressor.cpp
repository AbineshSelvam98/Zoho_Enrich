#include <iostream>

using namespace std;

int main() 
{
    string a;
    cin>>a;
    int n=a.length();
    for(int i=0;i<n;i++)
    {
        int count=1;
        while(a[i]==a[i+1])
        {
            i++;
            count++;
        }
        cout<<a[i];
        if(count>=2)
        {
            cout<<count;
        }
    }
}
