////......................................SPLIT A CIRCULAR LINKLIST INTO TWO HALVES....................................//
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node *header;
struct node *header1;

int createlist(int n);
void process(int n);
void display(int n);


int main()
{
	int a,m;
	printf("ENTER NUMBER OF NODE YOU WANT TO CREATE.\n");
	scanf("%d",&a);
	m=createlist(a);
	if(m==1)   //when number of element less than 0r equal to zero 
	{
		return;
	}
	if(m==2)   //when number of elements is 1
	{
	  display(1);
	  return;	
	}
	
	display(1);
	process(a);
	printf("..........1st half of list is..........\n");
	display(1);
	printf("................2nd half of the list is...............\n");
	display(2);
	printf("\n");
	
}


int createlist(int n)
{
	int a,i;
	if(n<=0)
	{
		printf("INVALID INPUT...........\n");
		return 1;
	}
	struct node *new,*temp;
	header=(struct node *)malloc(sizeof(struct node));
	if(header==NULL)
	{
		printf("unable to create memory.......\n");
	}
	printf("ENTER  DATA FOR 1ST NODE\n");
	scanf("%d",&a);
	header->data=a;
	header->link=header;
	if(n==1)
	{
		printf("List can not be divided into 2 halves\n");
		return 2;
	}
	temp=header;
	//Insert node at end
	for(i=2;i<=n;i++)
	{
		new=(struct node *)malloc(sizeof(struct node));
		if(new==NULL)
		{
			printf("UNABLE TO CREATE MEMORY.....\n");
		}
			printf("ENTER  DATA FOR %d NODE\n",i);
	        scanf("%d",&a);
	        new->data=a;
	        new->link=header;
	        temp->link=new;
	        temp=temp->link;
		
		
		
	}
	
	
	
}
void process(int n)     //To divide list into 2 parts
{
	int a,i;
	struct node *ptr,*new,*p,*q;
	//if number of elements are even
	if(n%2==0)
	{
		ptr=header;
		a=n/2;
		for(i=1;i<=a;i++)
		{
			p=ptr;
			ptr=ptr->link;
		}
		header1=(struct node *)malloc(sizeof(struct node));      //header1 is head of list 2
		if(header1==NULL)
		{
			printf("UNABLE TO CREATE MEMORY\n");
		}
		header1->data=ptr->data;
		header1->link=header1;
		ptr=ptr->link;
		q=header1;                                            //q is pointing the 2nd list of header.
		for(i=a+2;i<=n;i++)
		{
			new=(struct node *)malloc(sizeof(struct node));
			if(new==NULL)
			{
				printf("Unable to create memory..\n");
				
			}
			 new->data=ptr->data;
	        new->link=header1;
	        q->link=new;                            //q poining the previous node of new node
	        q=q->link;                              //now qis pointing new node.
	        ptr=ptr->link;                          
			
		}
		p->link=header;                    //to make 1st list circular last node is pointing to 1st node.
		
	}
	//If the number of elements are odd
	else
	{
		ptr=header;
		a=(n/2)+1;
		for(i=1;i<=a;i++)
		{
			p=ptr;
			ptr=ptr->link;
		}
		header1=(struct node *)malloc(sizeof(struct node));
		header1->data=ptr->data;
		header1->link=header1;
		ptr=ptr->link;
		q=header1;
		for(i=a+2;i<=n;i++)
		{
			new=(struct node *)malloc(sizeof(struct node));
			if(new==NULL)
			{
				printf("Unable to create memory..\n");
				
			}
			 new->data=ptr->data;
	        new->link=header1;
	        q->link=new;
	        q=q->link;
	        ptr=ptr->link;
			
		}
		p->link=header;
	}
}
void display(int n)
{
	struct node *p,*q;
    if(n==1)                     //when n=1 it will show the 1st half of the list
	{
			
	p=header;
	printf("YOUR list is.........\n");
	while(p->link!=header)
	{
		printf("%d\t",p->data);
		p=p->link;
	}
	printf("%d\n",p->data); 
   }
else                                    //otherwise it print the 2nd half of the list
{
	p=header1;
	printf("YOUR list is.........\n");
	while(p->link!=header1)
	{
		printf("%d\t",p->data);
		p=p->link;
	}
	printf("%d\n",p->data); 
	
}
	
    
}


