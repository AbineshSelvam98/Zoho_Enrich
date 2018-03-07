#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float a[n][n],sub[n], factor;
    for(int i=0;i<n;i++)//Reading the square matrix
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];  
        }
    }
    int k=1;
    for(int i=0;i<n-1;i++) //to find the upper triangular matrix
    {
        for(int k=i+1;k<n;k++)
        {
            factor=a[k][i]/a[i][i];
            for(int j=0;j<n;j++) 
            {
                sub[j]=a[i][j]*factor;
            }
            for(int m=0;m<n;m++)
            {
                a[k][m]=a[k][m]-sub[m];
            }
        }
    }
    float det=1;
    for(int i=0;i<n;i++) // to calculate determinant 
    {
       det*=a[i][i];
    }
    cout<<det;
    
}
