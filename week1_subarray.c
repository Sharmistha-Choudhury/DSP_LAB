//................Smallest subarray with sum greater than the given value.............//
#include<stdio.h>
int arr[1000];
int i,k,s=0,p=1,n,l,u,sum,t,m;

int subarray();

int main()
{
	
	printf("ENTER THE SIZE OF ARRAY.\n");
	scanf("%d",&n);
	printf("ENTER ELEMENTS FOR ARRAY..........\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Your array is.\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nENTER SUM VALUE....\n");
	scanf("%d",&sum);
    subarray();
	
}

  int subarray()
  {
  	for(p=1;p<n;p++)  //for making combinations
	{
	    	
	for(i=0;i<n;i++)
	{
		s=0;
		if(i!=(n-1))
		{
		   l=i;                   //used for find the lower index of the set
		for(k=i;k<=(i+p) && (i+p)<n;k++)     //(i+p) define the maximum limit of this loop & it is used to generate number of combination of elements.
		{
			s=s+arr[k];
		
			
		}
		u=k-1;              //set the higher index of the set
		if(s>sum)
		{
			printf("\nSMALLEST SUBARRAY WITH SUM GREATER THAN THE GIVEN VALUE.....\n");
			for(t=l;t<=u;t++)
			{
				
				printf("%d\t",arr[t]);
				
			}
		     m=u-l+1;   //no of elements present into the subarray
			printf("\nFINAL RESULT IS.....\n");
			for(t=l;t<=u;t++)         //used to add m to each element of the list
			{
				arr[t]=arr[t]+m;
				printf("%d\t",arr[t]);
				
			}
			return 1;
		}
		
			
	}
		
	}
}
 printf("incorrect sum\n");
  	
  }


