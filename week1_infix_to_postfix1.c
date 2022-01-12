//.........................INFIX TO POSTFIX CONVERSION.....................//
#include<stdio.h>

#include<ctype.h>
char arr[1000];
int top=-1;
int balance(char *infix,int size);
int check(char *infix);
void push(char c);
char pop();
int priority(char x);
//int postfix_eva(char *arr1);
int check_digit(char *arr1);

int main()
{
	char arr1[1000];
	char arr2[1000];
	char x;
	int i,j=0;
	printf("ENTER THE STRING.\n");
	scanf("%s",arr1);
	//check balance of brackrts is correct or not
	if(balance(arr1,1000)==0)
	{
		return;
	}
	//Input is valid or not
	if(check(arr1)==0)
	{
		return;
	}
	printf("your input is...\n");
	printf("%s\n",arr1);
	printf("POSTFIX EXPRESSION IS......\n");
	for(i=0;arr1[i]!='\0';i++)
	{
		if(isalnum(arr1[i]))
		{
			printf("%c",arr1[i]);
			arr2[j]=arr1[i];
			j++;
			
		}
		
		else if(arr1[i] == '(')
		{
			push(arr1[i]);
		}
            
        else if(arr1[i] == ')')
        {
            while((x = pop()) != '(')
            {
			
                printf("%c ", x);
                arr2[j]=x;
                j++;
            }
        }

		else
		{
		
		        while(priority(arr[top])>=priority(arr1[i]))
		        {
		        	x=pop();
				printf("%c",x);
				arr2[j]=x;
				j++;
		        }
	
		          push(arr1[i]);
	    }
	    
			
		
		
	}
	while(top!=-1)
	{
		x=pop();
		printf("%c",x);
		arr2[j]=x;
		j++;
	}
	//postfix_eva(arr2);
	
}



void push(char c)
{
	top=top+1;
	arr[top]=c;
}
char pop()
{
	char t;
	if(top==-1)
	{
		arr[top]=-1;
		return -1;
	}
	t=arr[top];
	top=top-1;
	return t;
}
//used to set priority of oprator
int priority(char x)
{
	if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
	
}

//check the balancing of brackets
int balance(char *infix,int size)
{
    int i;
    int top=-1;
    char stack[size];
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='{' || infix[i]=='}' || infix[i]=='[' || infix[i]==']')
        {
        	printf("wrong bracket\n");
        	return 0;
		}
        
            
            if(infix[i]=='(') 
			{
			         top++;
                     stack[top]='(';
            }
                      
            
            if(infix[i]== ')')
            {
			
			 if(stack[top]=='(')
			 {
			 
                      top--;
                }
            }
           /* if(infix[i]==')' && stack[top]!='(')
            {
            	printf("unbalance brackets\n");
            	return 0;
			}*/
              
        
    }

    if(top==-1)
    return 1;
    printf("unbalance brackets\n");
    return 0;
}

//this function is used to check the input is correct infix or not
int check(char *infix)
{
	
	int x=priority(infix[0]); //used to find the operator
	int i;
	if(x==1 || x==2)
	{
		printf("invalid input\n");
		return 0;
	}
	for(i=0;infix[i]!='\0';i++)
	{
		x=priority(infix[i]); 
		if(x==1 || x==2)
		{
			if(i>0 && isalnum(infix[i-1]) && isalnum(infix[i+1]));
			else
			{   printf("invalid input\n");
				return 0;
			}
		}
	}
	return 1;
	
	
}
/*int check_digit(char *arr1)
{
	int i,x;
	for(i=0;arr1[i]!='\0';i++)
	{
		if(isdigit(arr1[i]))
		{
			
		}
		x=priority(arr1[i]);
		 if(x==1 || x==2)
		{
			
		}
		if(isdigit(arr1[i])==0)
		{
			printf("\nwrong data & postfix evaluation can not be done\n");
			return 0;
		}
	}
	return 1;
}*/


