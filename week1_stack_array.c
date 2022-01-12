//.......................STACK IMPLEMENTATION USING ARRAY....................//
#include<stdio.h>
#include<conio.h>
int size;
int arr[1000];
int top=-1;
int push1();
int pop1();
int display();

int main()
{
	int p=1;
	int a;
	printf("\n.............Stack Implementation using array..............\n\n");
	printf("ENTER THE SIZE OF STACK.......\n");
	scanf("%d",&size);
	if(size<=0)
	{
		printf("\nInvalid Input..Try again later\n");
		return;
	}
	while(p!=4)
	{
		printf("\n...................STACK OPERATIONS......................\n");
	   	printf("\n ENTER \n 1 FOR PUSH DATA \n 2 FOR POP OPERATION \n 3.FOR DISPLAY\n 4.FOR EXIT\n");

     	scanf("%d",&p);
	    if(p==1)
	    {
	    	push1();
		}
	   		
	   		
	   	else if(p==2)
	   	{
	   		pop1();
		}
		else if(p==3)
		{
			display();
		}
	    else if(p==4)
	    {
	    	printf("...............exit..............");
	    	return;
		}
		else
		{
		
	   		printf("......................YOU ENTER WRONG INPUT.....................\n");
	   		
	   }
    }  
}

//To push data into stack.
int push1()
{
	int a;
   if(top>=size ||(top+1)>=size)
   {
   	  printf("\n stack is full.Insertion is not possible...\n ");
   	  return;
	}
	else
	{
		
		printf("enter the element...\n");
		scanf("%d",&a);
	    top=top+1;
		arr[top]=a;	
	}
	printf("Push an element into stack is successfully done...\n");
	
	
}
//pop data from stack
int pop1()
{  
   int p;
	if(top<0)
	{
		printf("\n Stack is empty.Deletion is not possible\n");
		return;
		
	}
	else
	{
		p=arr[top];
		top=top-1;
	
		
	}
	printf("Deletion is successsfully done\n");
	printf("Deleted element=%d \n",p);
	
	
}
//Display status of stack & display elements of stack
int display()
{
 int i; 
 if(top<0)
 {
 	printf("STACK IS EMPTY\n");
 	return;
  }
  if(top==(size-1))
  {
  	printf("stack is full\n ");
  	
  }
  printf(".....................ELEMENTS ARE...............\n");
  for(i=top;i>=0;i--)
  {
  	 printf("%d\t",arr[i]);
   }
   printf("\n");	
	
}

