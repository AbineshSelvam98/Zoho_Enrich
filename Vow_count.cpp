#include <iostream>

using namespace std;

int main() 
{
    string str,vow="aeiou";
    getline (cin, str);
    int n=str.length();
    for(int i=0;i<5;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(vow[i]==tolower(str[j]))
            {
                count++;
            }

        }
        if(count!=0)
        {
            cout<<vow[i]<<"->"<<count<<endl;
        }
    }
}
