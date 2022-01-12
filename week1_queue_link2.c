//....................QUEUE IMPLEMENTATION USING LINK LIST..........................//
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *header;
void enqueue1()
{
	struct node *p;
	struct node *p1;
	int a;
	p=(struct node*)malloc(sizeof(struct node));
	printf(".............ENTER THE ELEMENT..........\n");
	scanf("%d",&a);
	if(header==NULL)
	{
		p->data=a;
		p->link=NULL;
		header=p;
	}
	else
	{
		p1=header;
		while(p1->link!=NULL)
		{
		   p1=p1->link;
      	}
      	p->data=a;
      	p1->link=p;
      	p->link=NULL;
		
	}
	printf("ENQUEUE IS SUCCESSFULLY DONE\n");
}
void dequeue2()
{
	struct node *p1;
	int a;
	p1=header;
	if(header==NULL)
	{
		printf("QUEUE IS EMPTY....DEQUEQE IS NOT POSSIBLE..........\n");
		return;
	}
	else
	{
		a=p1->data;
		header=p1->link;
		free(p1);
		
	}
	printf("\n Dequeue is successful\n ");
	printf("Deleted element=%d",a);
	
}
void display3()
{
	int count=0;
	struct node *p1;
	p1=header;
	if(header==NULL)
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	if(header->link==NULL)
	{
		printf("contain one element\n");
	}
	while(p1!=NULL)
	{
		
		count++;
		printf("%d \t",p1->data);
		p1=p1->link;
	}
	printf("\nNO. OF ELEMENTS=%d \n",count);
	
}

int main()
{
	int p=10;
	while(p!=4)
	{
		printf("\n...................QUEUE OPERATIONS......................\n");
	   	printf("\n ENTER \n 1 FOR ENQUEUE OPERATION \n 2 FOR DEQUEUE OPERATION \n 3.FOR DISPLAY\n 4.FOR EXIT\n");

     	scanf("%d",&p);
	    if(p==1)
	    {
	       enqueue1();	
		}
	   		
	   	else if(p==2)
		  {
		  	dequeue2();
		  }	
	   		
	   	else if(p==3)
	   	{
	   		display3();
		   }
	   		
	   	else if(p==4)
	   	{
	   		printf("...............exit..............");
	   		
		   }
	   	else
	   	{
		
	   		printf("......................YOU ENTER WRONG INPUT.....................\n");
	   		
	   }
	}
}

