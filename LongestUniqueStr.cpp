#include <iostream>
using namespace std;
void printer(string str,int index,int length)//This function is used to print the charecters from index to index+max length
{
    for(int i=0;i<length;i++)
    {
        cout<<str[index++];
    }
    cout<<endl;
}
void substring(string str)
{
    int checklist[26]={0},n,max=-1,start=0,end=0,i_array[10],k=-1;
    n=str.length();
    start=end=0;
    while(end<n)
    {
        while((checklist[str[end]-'a']==0)&&(end<n))
        {
            checklist[str[end]-'a']=1;
            end++;
        }
        int l=end-start;
        if(max<=l)
        {
            if(max<l)
            {
                max=l;
                k=-1;
            }
            i_array[++k]=start;// This array contains the  index positions of maximum lengthed substring
        }
       
        while((checklist[str[end]-'a']==1)&&(start<n))
        {
            checklist[str[start++]-'a']=0;
        }
   
    }
    for(int i=0;i<=k;i++)
    {
        printer(str,i_array[i],max);
    }
    
}

int main() 
{
    string str;
    cin>>str;
    substring(str);
}
