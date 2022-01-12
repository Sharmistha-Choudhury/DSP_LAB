//.................STACK USING LINK LIST................................//
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head;

void push();
int pop();
void display();

int main()
{
	int p=1;
	int a;
	while(p!=4)
	{
		printf("\n...................STACK OPERATIONS......................\n");
	   	printf("\n ENTER \n 1 FOR PUSH DATA \n 2 FOR POP OPERATION \n 3.FOR DISPLAY\n 4.FOR EXIT\n");

     	scanf("%d",&p);
	   if(p==1)
	   {
	   	
	   		
	   		push();
	   }
	   else if(p==2)
	   {
	        pop();
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
	free(head); 
	
}

//to push data into stack

void push()
{
	int a;
	printf("ENTER ELEMENT\n");
	scanf("%d",&a);
	struct node *n1;
	n1=(struct node*)malloc(sizeof(struct node));
	n1->data=a;
	if(head==NULL)
	{
		n1->link=NULL;
		head=n1;
	}
	else
	{
		n1->link=head;
		head=n1;
	}
	printf("successfully push the element\n");
	
	
}
//pop data from stack
int pop()
{
   int a;
   struct node *p1;	
   
   if(head==NULL)
	{
		printf("STACK IS EMPTY!!DELETION IS NOT POSSIBLE\n");
		return;
	}
	else
	{
		p1=head;
		a=p1->data;
		
		
		head=p1->link;
		free(p1);
	}
	
	printf("DELETION IS SUCCESSFULLY\n");
	printf("Deleted element=%d \n",a);
	
	
	
}

//display the status & elements from stack
void display()
{
	struct node *p1;
	int count=0;
	p1=head;
	if(head==NULL)
	{
		printf("STACK IS EMPTY\n");
	}
	else
	{
		printf("\n.......ELEMENTS ARE..............\n");
		while(p1!=NULL)
		{
			count++;
			printf("%d \t",p1->data);
			p1=p1->link;
			
		}
		printf("\n NO OF NODE=%d",count);
	}
}

