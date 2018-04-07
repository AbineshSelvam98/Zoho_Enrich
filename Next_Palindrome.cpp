#include<iostream>
#include<string> // for integer  to string conversion --> to_string()
#include<algorithm>
using namespace std;
int check(string a,int l) //to check all the whether all digits in left part of a number is 9
{
    for(int i=0;i<l;i++)
    {
        char n=a[i];
        if(n!='9')
        {
            return 0;
        }
    }
    return 1;
}

int next_palindrome(string a,int l)
{
    string left="",right="",mid;//spliting  the integer into 3 parts
    for(int i=0;i<l/2;i++)
    {
        left=left+a[i];
    }
    right=left;
    reverse(right.begin(),right.end());
    if(l%2)  //if number is odd lengthed number then middle part will be considered
    {
        mid=a[l/2];
    }
    else
    {
        mid="";
    }
    int pal_num=stoi(left+mid+right);
    int org_num=stoi(a);
    if(pal_num>org_num)
    {
        return pal_num;
    }
    if(l%2)
    {
        if(mid<"9")  
        {
            mid=to_string(stoi(mid)+1);
            pal_num=stoi(left+mid+right);
            return pal_num;
        }
        else //if the middle part is 9 we have to deal with the carry so, make middle as 0 and increment left part by
        {
            mid="0";
        }
        
    }
    if(check(left,l/2))
    {
        left=to_string(stoi(left)+1);
        right=left;
        reverse(right.begin(),right.end());
        pal_num=stoi(left+mid+right);
        return pal_num;
    }
    else
    {
        left=to_string(stoi(left)+1);
        right=left;
        reverse(right.begin(),right.end());
        pal_num=stoi(left+mid+right);
        return pal_num;
    }

}
int main()
{
    int num,l;
    cin>>num;
    string a,left="",right="";
    a=to_string(num);
    l=a.length();
    int pal_num=next_palindrome(a,l);//function to find the next palindrome
    cout<<pal_num;
    
}
