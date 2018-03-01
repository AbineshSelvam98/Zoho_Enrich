#include <iostream>
using namespace std;
int main()
{
    int dec,count=0;
    cin>>dec;
    while(dec)
    {
        if(dec-(dec/2)*2==1)
        {
            count++;
        }
        dec/=2;
        
    }
    cout<<count;
    

}
