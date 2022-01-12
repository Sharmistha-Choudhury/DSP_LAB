//...................infix to postfix && infix to prefix......................................//
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct stack
{
	char data;
	struct stack *next;
}st;
st *header;
st *top;
char *arr1;
char *arr2;
char *arr3;
int n;
int check(char *infix);
int balance(char *infix,int size);
void push(char p)
{
	st *new;
	new=(st*)malloc(sizeof(st));
	new->data=p;
	if(header==NULL)
	{
	    header=new;
	    new->next=NULL;
	    top=new;
	}
	else
	{
		new->next=header;
		header=new;
		top=new;
	}
}

char pop()
{
	char m;
	st *new;
	new=(st*)malloc(sizeof(st));
	
	if(header==NULL)
	{
		top=NULL;
		return 0;
	}
   else
	{
       	new=header;
		m=header->data;
		header=new->next;
		top=new->next;
		free(new);
		return m;
		
	}
}

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
postfix()
{
	int i,j;
	char x,l;
	for(i=0,j=0;arr1[i]!='\0';i++)
	{
		if(isalnum(arr1[i]))
		{
			//printf("%c",arr1[i]);
			arr2[j]=arr1[i];
			printf("%c",arr2[j]);
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
			
               // printf("%c ", x);
                arr2[j]=x;
                printf("%c ",arr2[j]);
                j++;
            }
        }
        else if(top==NULL)
        {
        	push(arr1[i]);
		}

		else
		{
		
		        while(priority(top->data)>=priority(arr1[i]))
		        {
		        	l=pop();
		        	arr2[j]=l;
		        	printf("%c",arr2[j]);
		        	j++;
				   //printf("%c",l);
		        }
	
		          push(arr1[i]);
	    }
	    
			
		
		
	}
	while(top!=NULL)
	{
		l=pop();
		arr2[j]=l;
		printf("%c",arr2[j]);
		j++;
		//printf("%c",l);
	}
	arr2[j]='\0';
		
}
int reverse()
{
	int i,j=0;
	
	
	for(i=strlen(arr3)-1;i>=0;i--)
	{
		arr1[j]=arr3[i];
		j++;
		
	}
	arr1[j]='\0';
	
	for(i=0;arr1[i]!='\0';i++)
	{
		printf("%c",arr1[i]);
	}
	
	postfix();
	j=0;
	
	for(i=strlen(arr2)-1;i>=0;i--)
	{
		arr1[j]=arr2[i];
		j++;
		
	}
	arr2[j]='\0';
	
	printf("prefix is..\n");
	for(i=0;arr1[i]!='\0';i++)
	{
		printf("%c",arr1[i]);
	}
	
	
	
	
	
	


}


int main()
{
	int n;
	char x;
	int i,j=0;
	printf("enter size of your string\n");
	scanf("%d",&n);
	n=n+1;
	arr2=calloc(n,sizeof(char));
	arr1=calloc(n,sizeof(char));
	arr3=calloc(n,sizeof(char));
	printf("ENTER THE STRING.\n");
	for(i=0;i<n;i++)
	{
		scanf("%c",&arr1[i]);
	}
	
	printf("your input is...\n");
	for(i=0;arr1[i]!='\0';i++)
	{
		printf("%c",arr1[i]);
	}
	
	
	printf("\nPOSTFIX EXPRESSION IS......\n");
	postfix();
	for(i=0;arr2[i]!='\0';i++)
	{
		printf("%c",arr2[i]);
	}
	

	
	
	

	
}



