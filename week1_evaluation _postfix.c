//....................EVALUATION OF POSTFIX EXPRESSION.....................//
#include<stdio.h>
#include<ctype.h>
int arr1[1000];
int top=-1;
void push(int c)
{
	top=top+1;
	arr1[top]=c;
}
int pop()
{
	int c;
	if(top==-1)
	{
		return -1;
	}
	c=arr1[top];
	top=top-1;
	return c;
	
}

int main()
{
	char arr[1000];
	int i,k1,k2,re=0,p;

	printf("ENTER THE POSTFIX EXPRESSION ......\n");
	
		scanf("%s",arr);
	
	printf("POSTFIX EXPRESSION IS.......\n");
	
		printf("%s",arr);
	
	for(i=0;arr[i]!='\0';i++)
	{
		if(isdigit(arr[i]))
		{
			
			push(arr[i]-'0');
		}
		else
		{
			k2=pop();
			k1=pop();
			switch(arr[i])
			{
				case '+':
					re=k1+k2;
					push(re);
					break;
				case '-':
					re=k1-k2;
					push(re);
					break;
				case '*':
					re=k1*k2;
					push(re);
					break;
				case '/':
					 re=k1/k2;
					 push(re);
					 break;
				default:
					printf("operator is wrong\n");
			}
			
			
			
		}
	}
	printf("\nAFTER EVALUATION OF POSTFIX EXPRESSION\n");
	printf("\nresult=%d",re);

}
