#include <stdio.h>
//..............BINARY TO DECIMAL CONVERSION............//

#include <math.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;
void insertatbeg(int num);
void output();
void decimal(int p);


int main()
{
	int n,i,a;
	printf("ENTER THE NUMBER OF ELEMENT.........\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		
			printf("\n..............Please enter either 0 or 1.....................\n");
			scanf("%d",&a);
		
			 if((a==0) || (a==1))
			{
				
							insertatbeg(a);
						
			}
			else
				{
					printf("\n Invalid Input. Retry \n");
					return;
				
				}
			
		}
		output();
		
		decimal(n);
		
		
	}


void insertatbeg(int num)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node*));
	struct node *ptr;
	if(newnode==NULL)
		printf("\nUNABLE TO CREATE MEMORY\n");
	else
	{
			newnode->data=num;
			newnode->next=head;
			head=newnode;
			
	}
}

void output()
{
  struct node *ptr;
	ptr=head;
	printf("\n YOUR ELEMENTS ARE............\n");

	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	
}
void decimal(int p)
{
	struct node *ptr;
	int i,d=0;
	if(head==NULL)
	{
		printf("\nList is Empty\n");
		exit(1);
	}
	ptr=head;
	p=p-1;
	for(i=p;p>=0;p--)
	{
		d= d + (ptr->data * (pow(2,p)));
		ptr=ptr->next;
	}
	printf("\n The equivalent decimal number is %d \n", d);
}
 	 

