//..................heap operatiom...............//
#include<stdio.h>
#include<stdlib.h>
void input(int *arr,int k,int n);
void build_heap(int *arr,int c,int n);
void maxheapy(int *arr,int i,int n);
int count=0;
int array_creation(int *arr);
void array_ini(int *arr,int n);
int input1(int *arr1,int n);
int check(int i);
void swap(int *a,int *b);
int display(int *arr,int n);
void operation(int *arr,int n);
int delete_max(int *arr,int n);
int pos(int *arr,int ele,int n);
void sort_max(int *arr,int n);
void input2(int *arr,int k,int n);
void operation_min(int *arr,int n);
void build_heap_min(int *arr,int count,int n);
void minheapy(int *arr,int i,int n);
void array_ini1(int *arr,int n);
int display_min(int *arr,int n);
void sort_min(int *arr,int n);
int delete_min(int *arr,int n);
void halt();
int main()
{
	
	printf("\n..............MAX HEAP & MIN HEAP OPERATION  WITH SORTING..............\n\n\t");
	int choose;
	int *arr,n,k;
	printf("\n\n\tEnter size of array\n\t");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("\n\n\tEnter\n\n\t1.Minheap\n\n\t2.Maxheap\n\t\tfor press any numeric key for exit\n\n\t");
	scanf("%d",&choose);
	if(choose==1)
	{
		printf("\n........world of min heap..............\n\t");
		array_ini1(arr,n);
		k=input1(arr,n);
		if(k==-4)
		{
			return;
		}
		input2(arr,k,n);
		display_min(arr,n);
		operation_min(arr,n);
	}
	else if(choose==2)
	{
		printf("\n................world of max heap..................\n\t");
		array_ini(arr,n);
		k=input1(arr,n);
		if(k==-4)
		{
			return;
		}
		input(arr,k,n);
		display(arr,count);
		operation(arr,n);
	}
	else
	{
		printf("EXIT\n\t");
	}
	
}

	void halt(){
		char ch='a';
		printf("\n\t\tPress \"c\" to continue...");
	
		while(1){
			scanf("%c",&ch);
			if(ch=='c' || ch == 'C')break;
		}
	}
//.....................max heap......................................//
void array_ini(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		arr[i]=-1;
	}
}

int input1(int *arr,int n)
{
	int  p;
	printf("\n\tEnter number(1 to %d ) of element you want to insert into array...\n\n\t",n);
	scanf("%d",&p);
	if(p<=n)
	{
		return p;
	}
	else if(p>n || p<=0)
	{
		printf("\n\n\tInvalid input\n\n\t");
		return -4;
	}
}

void input(int *arr,int k,int n)
{
	int i;
	if(count>=n)
	{
		printf("\n\n\tMemory is full & Insertion is not possible...\n\n\t");
	}
	else
	{
		if(count<0)
		{
			count=0;
		}
	
	printf("\n\n\tEnter %d elements(except -1)....\n\n\t",k);
	for(i=0;i<k && count<n;i++)
	{
		if(arr[count]!=-1)
		{
			count++;
		}
		scanf("%d",&arr[count]);
		build_heap(arr,count,n);
		printf("\n\t element inserted into heap sucessfully\n\n\t");
		printf("\t");
		count++;
		
	}
    }
}

void build_heap(int *arr,int c,int n)
{
	int i=c;
	while(i>=0)
	{
		maxheapy(arr,i,n);
		i=check(i);
	}
}

int check(int i)
{
	if(i%2==0)
	{
		i=i/2-1;
		return i;
	}
	else
	{
		i=i/2;
		return i;
	}
}
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void maxheapy(int *arr,int i,int n)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(i<n && l<n && arr[largest]<arr[l])
	{
		largest=l;
	}
	if(i<n && r<n && arr[largest]<arr[r])
	{
		largest=r;
	}
	if(i!=largest)
	{
		swap(&arr[largest],&arr[i]);
		maxheapy(arr,largest,n);
	}
}

int display(int *arr,int n)
{
	printf("\n\n\tYour list is:\n\n\t");
	int i;
	if(count==-1)
	{
		printf("\n\n\tNo element present in a list\n\n\t");
		return;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]==-1)
		{
			return;
		}
		printf("%d ",arr[i]);
	}
	printf("\n\t");
}

void operation(int *arr,int n)
{
	int choice;
	printf("\n\n.........Operation for MAX heap..............\n\n\t");
	while(1)
{
	
	printf("Enter\n\n\t1.Insert a key into heap\n\n\t2.Delete a key\n\n\t3.Sort a heap\n\n\t4.display\n\t press any numeric key for exit\n\n\t");
	scanf("%d",&choice);
	if(choice==1)
	{
		input(arr,1,n);
		halt();
	}
	else if(choice==2)
	{
		delete_max(arr,n);
		halt();
	}
	else if(choice==3)
	{
		sort_max(arr,n);
		halt();
	}
	else if(choice==4)
	{
		    display(arr,n);
		    halt();
		
	}
	else
	{
		printf("\n\n\t EXIT\n\n\t");
		return;
	}
}
}

int pos(int *arr,int ele,int n)
{
	int i;
	
	    for(i=0;i<n;i++)
		{
			if(arr[i]==ele)
			{
				return i;
			}
		}
		printf("\n\t%d is not present in a list\n\t",ele);
		return -2;
	
}

int delete_max(int *arr,int n)
{
	int i,position,ele;
	if(count==-1)
	{
		printf("\n\n\theap is empty. deletion is not possible\n\n\t");
		return;
	}
	printf("\n\tEnter element which you want to delete\n\t");
	scanf("%d",&ele);
	position=pos(arr,ele,n);
	if(position==-2)
	{
		return;
	}
	if(count==n)
	{
		count=count-1;
		
	}
	printf("\n\tposition=%d\n\n\t",position);
	arr[position]=arr[count];
	arr[count]=-1;
	count=count-1;
	maxheapy(arr,position,n);
	printf("\n\t (%d) element is deleted\n\t",ele);
	
}

void sort_max(int *arr,int n)
{
	int i,p=count;
	if(count==0 || count==-1)
	{
		printf("\n\n\t no elements are present so sort is not possible\n\n\t");
		
	}
	else
	{
		//if p point size.
		if(p==n)
		{
			p=p-1;
		}
		for(i=p;i>0;i--)
		{
			swap(&arr[0],&arr[i]);
			p=p-1;
			maxheapy(arr,0,p);
		}
		printf("\n\n\t..sucessfully sorting done...\n\n\t");
	}
}

//.................................min heap.............................................//

void array_ini1(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		arr[i]=1000000;
	}
}

void input2(int *arr,int k,int n)
{
	int i;
	if(count>=n)
	{
		printf("\n\n\tMemory is full & Insertion is not possible...\n\n\t");
	}
	else
	{
		if(count<0)
		{
			count=0;
		}
	
	printf("\n\n\tEnter %d elements (except 1000000 digit)....\n\n\t",k);
	for(i=0;i<k && count<n;i++)
	{
		if(arr[count]!=1000000)
		{
			count++;
		}
		scanf("%d",&arr[count]);
		build_heap_min(arr,count,n);
		printf("\n\t element inserted into heap sucessfully\n\n\t");
		printf("\t");
		count++;
		
	}
    }
}

void build_heap_min(int *arr,int c,int n)
{
	int i=c;
	while(i>=0)
	{
		minheapy(arr,i,n);
		i=check(i);
	}
}


void minheapy(int *arr,int i,int n)
{
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(i<n && l<n && arr[smallest]>arr[l])
	{
		smallest=l;
	}
	if(i<n && r<n && arr[smallest]>arr[r])
	{
		smallest=r;
	}
	if(i!=smallest)
	{
		swap(&arr[smallest],&arr[i]);
		maxheapy(arr,smallest,n);
	}
}


int display_min(int *arr,int n)
{
	printf("\n\n\tYour list is:\n\n\t");
	int i;
	if(count==-1)
	{
		printf("\n\n\tNo element present in a list\n\n\t");
		return;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]==1000000)
		{
			return;
		}
		printf("%d ",arr[i]);
	}
	printf("\n\t");
}


void operation_min(int *arr,int n)
{
	int choice;
	printf("\n\n.........Operation for MIN heap..............\n\n\t");
	while(1)
{
	
	printf("Enter\n\n\t1.Insert a key into heap\n\n\t2.Delete a key\n\n\t3.Sort a heap\n\n\t4.display\n\t press any numeric key for exit\n\n\t");
	scanf("%d",&choice);
	if(choice==1)
	{
		input2(arr,1,n);
		halt();
	}
	else if(choice==2)
	{
		delete_min(arr,n);
		halt();
	}
	else if(choice==3)
	{
		sort_min(arr,n);
		halt();
	}
	else if(choice==4)
	{
		
		    display_min(arr,n);
		    halt();
		
	}
	else
	{
		printf("\n\n\tEXIT\n\n\t");
		return;
	}
}
}



int delete_min(int *arr,int n)
{
	int i,position,ele;
	if(count==-1)
	{
		printf("\n\n\theap is empty. deletion is not possible\n\n\t");
		return;
	}
	printf("\n\tEnter element which you want to delete\n\t");
	scanf("%d",&ele);
	position=pos(arr,ele,n);
	if(position==-2)
	{
		return;
	}
	if(count==n)
	{
		count=count-1;
		
	}
	printf("\n\tposition=%d\n\n\t",position);
	arr[position]=arr[count];
	arr[count]=1000000;
	count=count-1;
	minheapy(arr,position,n);
	printf("\n\t (%d) element is deleted\n\t",ele);
	
}


void sort_min(int *arr,int n)
{
	int i,p=count;
	if(count==0 || count==-1)
	{
		printf("\n\n\t no elements are present so sort is not possible\n\n\t");
		
	}
	else
	{
		if(p==n)
		{
			p=p-1;
		}
		for(i=p;i>0;i--)
		{
			swap(&arr[0],&arr[i]);
			p=p-1;
			minheapy(arr,0,p);
		}
		printf("\n\n\t..sucessfully sorting done...\n\n\t");
	}
}
