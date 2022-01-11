//...............Implement priority queue..........................//
#include<stdio.h>
#include<string.h>
#define n1 1000
#define m1 1000
char q[n1][m1];//This 2D array is used for store name.
int prio[n1];//this 1D array is used for store Gate Score.
int fr=-1,re=-1;
int size;

void insert(char *name,int pr);
void delete();
void display();

void main()
{
	int p=0;
	int n;
	char name[n1];
	printf("ENTER THE SIZE OF QUEUE....\n");
	scanf("%d",&size);
		while(p!=4)
	{
		printf("\n...................PRIORITY QUEUE OPERATIONS......................\n");
	   	printf("\n ENTER \n 1 FOR INSERT DATA \n 2 FOR DELETE OPERATION \n 3.FOR DISPLAY\n 4.FOR EXIT\n");

        scanf("%d",&p);
	   if(p==1)
	   {
	   	     printf("Enter name & Gate score\n");
	   	     scanf("%s",name);
	   	     scanf("%d",&n);
	   		 insert(name,n);
	   }
	   	else if(p==2)
	   	{
		   
	   		delete();
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
	   		return;
		}
	   		
	   		
	   
	   
    }  
	
}


void insert(char *name,int pr)
{
	int i,j,pos,count=0;
	if(re==(size-1))
	{
	   printf("QUEUE IS FULL....INSERTION IS NOT POSSIBLE........\n");
	   return;	
	}
	else if(re==-1 && fr==-1)    //if queue is empty,just insert the elements into queue
	{
		fr=0;
		re=re+1;
		for(j=0;name[j]!='\0';j++)
		{
		    q[re][j]=name[j];	
		}
		
		prio[re]=pr;
		
	}
	
	else     //If queue is contain atleast one element.
	{
	
	for(i=fr;i<=re;i++)  //this loop is used for finding the position where to insert the element
	{
	  if(pr>prio[i])    //check if current person gate score(pr) is greater than any gate score of previous person then system find current position to store the current element
	  {
	  	pos=i;
	  	count=100;
	  	break;
	  }
    }
    if(count==100) //if count=100 means the postion is occupied by other person.so we should shift other person
    {
	
    for(i=re;i>=pos;i--)   //This loop is used to shiftthe name & gatescore from rear to postion.
    {
    	for(j=0;q[i][j]!='\0';j++)
    	{
		
    	q[i+1][j]=q[i][j];
        }
        q[i+1][j]='\0';
    	prio[i+1]=prio[i];
	}
	for(j=0;name[j]!='\0';j++) //After shifting position is empty.Now current person name & Gate score is stored into current postion
		{
		    q[pos][j]=name[j];	
		}
		q[pos][j]='\0';
	
	    prio[pos]=pr;
	    re=re+1;
		
   }
   else     //else is executed when the person gate score is less than all other person gate score which was store earlier.
   {
   	re=re+1;
   	for(j=0;name[j]!='\0';j++)
		{
		    q[re][j]=name[j];	
		}
		q[re][j]='\0';
   	   prio[re]=pr;
   		
   }
}
	
	printf("SUCCESSFULLY INSERTION IS DONE..\n");
	
}
void delete()
{
	
	int t,i,j;
	if(fr==-1)
	{
		printf("QUEUE IS EMPTY...DELETION IS NOT POSSIBLE\n");
		return;
	}
	if(fr==re) //Queue contain only 1 element
	{
		
		
		fr=-1;
		re=-1;
		
		
	}
	else
	{
		
		for(i=fr;i<=re;i++)  //after Deletion the front is vacant.so elements are shifted to the vacant place.
		{
			for(j=0;q[i+1][j]!='\0';j++)
			{
			
		    	q[i][j]=q[i+1][j];
		    }
		    q[i][j]='\0';
			prio[i]=prio[i+1];
		}
		fr=0;
		re=re-1;
		
	}
	printf("SUCCESSFULLY DELETION IS DONE..\n");
	
	
}

void display()
{
 int i,j; 
 if(fr==-1 && re==-1  )
 {
 	printf("QUEUE IS EMPTY\n");
 	return;
  }
  if(re==(size-1) && fr==0)
  {
  	printf("Queue is full\n ");
  	
  }
  printf("GATE SCORE\tNAME\n");
  printf("..........\t....\n");
  for(i=fr;i<=re;i++)
  {
  	printf("%d\t\t",prio[i]);
  	printf("%s\n\n",q[i]);
  	
  	
	  
  	 
  	 
   }
   	
	
}

