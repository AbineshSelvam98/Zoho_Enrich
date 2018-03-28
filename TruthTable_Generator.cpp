#include <iostream>
using namespace std;

void TruthtableGenerator(int table[32][6],int var) // This Function Generates the truth Table based  on variable count
{

    int k=1<<var-1;
    for(int i=0;i<var;i++)
    {
        int value=0;
        for(int j=0;j<1<<var;j++)
        {
            table[j][i]=value;
            if((j+1)%k==0)
            {
                value=!value;
            }
        }
        k=k>>1;
    
    }
}
void printer(int table[31][6],int var)//This function is used to display the truthtable with output
{
    for(int i=0;i<2<<var-1;i++)
    {
        for(int j=0;j<var+1;j++)
        {
            cout<<table[i][j]<<"    ";
        }
        cout<<endl;
    }
}
void evaluator(int table[32][6],string exp,int var, int row)//This function  used to evaluate the given expression for particular row
{
    int top=-1;
    char stack[10];
    for(int i=0;i<exp.length();i++)
    {
        if((exp[i]>='2'&&exp[i]<='9')||((exp[i]=='+'||exp[i]=='.')&&exp[i-1]=='('))
        {
            stack[++top]=exp[i];
        }
        else if((exp[i]=='+'||exp[i]=='.')&&exp[i+1]=='(')
        {
            stack[++top]=exp[i];
            i++;
        }
        else
        {
            if((exp[i]=='+'||exp[i]=='.'||exp[i]=='^')&&exp[i+1]!='(')
            {   

                if(stack[top]>='2')
                {
                    int x=stack[top]-'2';
                    if(exp[i]=='+')
                    {
                        stack[top]=(table[row][x]||table[row][exp[i+1]-'2'])+'0';
                    }
                    else if(exp[i]=='.')
                    {
                        stack[top]=(table[row][x]&&table[row][exp[i+1]-'2'])+'0';
                    }
                    else if(exp[i]=='^')
                    {
                        stack[top]=(table[row][x]^table[row][exp[i+1]-'2'])+'0';
                    }
                }
                
                else
                {
                    if(exp[i]=='+')
                    {
                        stack[top]=(stack[top]-'0' || table[row][exp[i+1]-'2'])+'0';
                    }
                    else if(exp[i]=='.')
                    {
                        stack[top]=(stack[top]-'0' && table[row][exp[i+1]-'2'])+'0';
                    }
                    else if(exp[i]=='^')
                    {
                        stack[top]=(stack[top]-'0' ^ table[row][exp[i+1]-'2'])+'0';
                    }
                    
                }
                i++;
            }
        }
    }
    if(top>0)
    {
        for(int j=top;j>0;)
        {
            
            int x,y;
            if(stack[j]>='2')
            {
                x=table[row][stack[j]-'2'];
            }
            else
            {
                x=stack[j]-'0';
            }
            
            if(stack[j-2]>='2')
            {
                y=table[row][stack[j-2]-'2'];
            }
            else
            {
                y=stack[j-2]-'0';
            }
            

            if(stack[j-1]=='+')
            {
                stack[j-2]=(x||y)+'0';
            }
            if(stack[j-1]=='.')
            {
                stack[j-2]=(x&&y)+'0';
            }
             if(stack[j-1]=='^')
            {
                stack[j-2]=(x^y)+'0';
            }
            j=j-2;
        }
        
    }
    table[row][var]=stack[0]-'0';

}
int main() 
{
    string exp;
    cin>>exp;
    int var=0,table[32][6];
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]>='A'&&exp[i]<='Z')
        {
            cout<<exp[i]<<"    ";
            var++;
            exp[i]='0'+var+1;
        }
    }
    cout<<"output";
    TruthtableGenerator(table,var);
   for(int i=0;i<2<<var-1;i++)//for loop is iterated for pow(2,var) times to calculate the value for each row form 0 t0 pow(2,var)-1
    {
        evaluator(table,exp,var,i);
    }
    cout<<endl;
   printer(table,var);
    
}
