#include<stdio.h>
#define size 30
int adjacency[size][size],visit[size],queue[size];
int front=-1,rear=-1;

void initial_adjacency(int n);
void create_graph(int n);
void halt();

void BFS_traversing(int s,int n);
void initial_visit(int n);
void enque(int item);
int deque();

void DFS_traversing(int source,int n);


int main()
{
	int n,i,j,choice=0,source;
	printf("\t.....Welcome to Graph world....\n");
	printf("\tEnter number of vertex:");
	scanf("%d",&n);
	printf("\n");
	initial_adjacency(n);
	create_graph(n);
	
	while(choice!=4)
	{
		printf("...............MENU...................\n");
		printf("\n\tEnter 1:BFS traversal in graph\n\t2.DFS traversal in graph\n\t3.QUIT\n\t");
		scanf("%d",&choice);
		if(1==choice)
		{
			initial_visit(n);
			printf("\n\tEnter the source vertex for BFS traversing\n\t");
			scanf("%d",&source);
			printf("\n\t...............BFS traversing from source vertex %d is..............\n",source);
			BFS_traversing(source,n);
			printf("\n");
			halt();
		}
		if(2==choice)
		{
		    initial_visit(n);
		    printf("\n\tEnter the source vertex for DFS traversing\n\t");
			scanf("%d",&source);
			printf("\n\t...............DFS traversing from source vertex %d is..............\n",source);
			DFS_traversing(source,n);
			printf("\n");
			halt();
				
		}
		if(3==choice)
		{
			printf("\tExit\n");
			break;
		}
		if(choice>=5)
		{
			printf("\twrong input\n");
			halt();
		}
	}
	
}

void initial_adjacency(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			adjacency[i][j]=0;
		}
	}
}
void initial_visit(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	
}
void create_graph(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\tEnter 1 :(if edge is between %d vertex & %d vertex)\n\tOR\n\tEnter 0 :(if edge is not between %d vertex & %d vertex)\n\t",i,j,i,j);
			scanf("%d",&adjacency[i][j]);
			if(0!=adjacency[i][j] && 1!=adjacency[i][j])
			{
				printf("\n\tEnter wrong input.plz enter correct input\n");
				j=j-1;
			}
		}
	}
	printf("Adjacency matrix is....\n");
	for(i=1;i<=n;i++)
	{
		printf("\t%d",i);
	}
	printf("\n\t");
	for(i=1;i<=n;i++)
	{
		printf("........");
	}
	
	printf("\n");
	
	for(i=1;i<=n;i++)
	{
		printf("%d|",i);
		for(j=1;j<=n;j++)
		{
			printf("\t%d",adjacency[i][j]);
		}
		printf("\n");
	}
	
}

void BFS_traversing(int source,int n)
{
	int present_node,i;
    enque(source);
    visit[source]=1;
    present_node=deque();
    if(present_node!=0)
        printf("\t %d",present_node);
    while(present_node!=0)
    {
        for(i=1;i<=n;i++)
        {
		
            if((adjacency[present_node][i]!=0)&&(visit[i]==0))
            {
                enque(i);
                visit[i]=1;
            }
        }
        present_node=deque();
        if(present_node!=0)
            printf(" %d ",present_node);
    }
    for(i=1;i<=n;i++)
    {
    	if(0==visit[i])
    	{
		
            BFS_traversing(i,n);
        }
	}
        
}

void enque(int item)
{
    if((size-1)==rear)
    printf("\n\t..QUEUE FULL..");
    else
    {
        if(-1==rear)
        {
            queue[++rear]=item;
            front++;
        }
        else
            queue[++rear]=item;
    }
}
int deque()
{
    int node;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        node=queue[front++];
        return(node);
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
	
	
void DFS_traversing(int source,int n)
{
    int i,present_node;
	visit[source]=1;
	printf("\t%d",source);
	for (i=1;i<=n;i++)
	{
	
	  if(adjacency[source][i] && !visit[i]) {
		DFS_traversing(i,n);
	}
    }
    for(i=1;i<=n;i++)
    {
    	if(0==visit[i])
    	{
		
            DFS_traversing(i,n);
        }
	}
      
    
}


