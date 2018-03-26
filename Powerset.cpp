#include<iostream>
using namespace std;
void Generator(int set[10],int checklist[10],int beg,int remain,int n)
{
    
	if(remain==0)// remain is the remaing elements to be taken in the subset
	{
	    for(int i=0;i<n;i++)
		{
			if(checklist[i]==1)// we are printing only the selected elements in the checklist
			{
				cout<<set[i]<<",";
			}
		}
		cout<<endl;
	}
	else
	{
		if(beg+remain>n);
		else
		{
			for(int i=beg;i<n;i++)
			{
				if(checklist[i]==0)
				{
					checklist[i]=1; // we adding that element in the subset
					Generator(set,checklist,i+1,remain-1,n);
					checklist[i]=0; // we are unchecking to take the next set of elements
				}
			}	
		}

	}	
}
int main()
{
	int n,set[10],beg,remain;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>set[i];
	}
	for(int i=0;i<n+1;i++)
	{
		int checklist[n];
		for(int i=0;i<n;i++)
		{
		    checklist[i]=0; //check list is used to know whether to consider element is consdered in subset or not @ first no elements are selecte
		}
		Generator(set,checklist,0,i,n);	//for each call in this loop we are generating a sub set of i elements;
	}

} 
