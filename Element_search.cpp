#include <iostream>
using namespace std;
int main()
{
    int item,count=0,flag=0,num;
    cin>>item;
    while((cin>>num))
    {
        if(num==item)
        {
            cout<<count;
            flag++;
            break;
        }
        count++;
    }
    if(flag==0)
        cout<<-1;
    
    
}
