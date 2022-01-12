//.......................QUEUE IMPLEMENTATION USING ARRAY...........................//
#include<stdio.h>
int arr[1000];
int fr=-1;
int re=-1;
int size;

int enqueue1();
int deque2();
void display();

int main()
{
	int p=1;
	int a;
	printf("ENTER THE SIZE OF QUEUE.......\n");
	scanf("%d",&size);
	if(size<=0)
	{
		printf("\n Invalid size & try again later");
		return;
	}
	while(p!=4)
	{
		printf("\n...................QUEUE OPERATIONS......................\n");
	   	printf("\n ENTER \n 1 FOR ENQUEUE DATA \n 2 FOR DEQUEUE OPERATION \n 3.FOR DISPLAY\n 4.FOR EXIT\n");

        scanf("%d",&p);
	   if(p==1)
	   {
	   	
	   		
	   		enqueue1();
	   }
	   	else if(p==2)
	   	{
		   
	   		deque2();
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
//insert element into queue
int enqueue1()
{
	int a;
	if(re==(size-1))
	{
	   printf("QUEUE IS FULL....ENQUEUE IS NOT POSSIBLE........\n");
	   return;	
	}
	if(re==-1 && fr==-1)
	{
		fr=0;
	}
	printf("ENTER THE ELEMENT...\n");
	scanf("%d",&a);
	re=re+1;
	arr[re]=a;
	printf("SUCCESSFULLY ENQUEUE IS DONE..\n");
}
//Delete element from queue
int deque2()
{
	int a;
	if(fr==-1)
	{
		printf("QUEUE IS EMPTY...DEQUEUE IS NOT POSSIBLE\n");
		return;
	}
	if(fr==re)  //only 1 element present into the list
	{
		a=arr[fr];
		fr=-1;
		re=-1;
		
		
	}
	else
	{
		a=arr[fr];
		fr=fr+1;
	}
	printf("SUCCESSFULLY DEQUE IS DONE..\n");
	printf("Deleted element=%d\n",a);
	
}
//display status & elements
void display()
{
 int i; 
 if(fr==-1 && re==-1  )
 {
 	printf("QUEUE IS EMPTY\n");
 	return;
  }
  if(re==(size-1) && fr==0)
  {
  	printf("Queue is full\n ");
  	
  }
  printf(".....................ELEMENTS ARE...............\n");
  for(i=fr;i<=re;i++)
  {
  	 printf("%d\t",arr[i]);
   }
   printf("\n");	
	
}

