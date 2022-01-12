//...............PERFORMANCE OF QUICK SORT WITH 4 DIFFERENT PIVOTS FOR PARTITIONING & MERGE...............//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void type_input();
void type_input1();
int fst_pivot(int *arr,int l,int h);
void quicksort1(int *arr,int l,int h,int choose);
int quicksort2(int *arr,int l,int h);
void display(int *arr,int size);
void pivot_selection(int *arr,int l,int h);
void rand_partition ( int *arr, int l , int h );
void swap(int *a,int *b);
void median_partition(int *arr,int *f,int *s,int *t,int l);
void halt();
void mergesort(int *ptr,int I,int r);
void merge(int *ptr,int I,int mid,int r);

void main()
{
	clock_t start,end;
	float t;
	start=clock();
	printf(".........................WORLD OF SORT..........................\n");
	int choose=0;
	printf("\n\n\tENTER\n\t1.QUICK SORT\n\n\t2.MERGE SORT\n\n\tany number for exit\n\n\t");
	scanf("%d",&choose);
	if(choose==1)
	    {
	    	type_input();
	    	
	
     	}	
     	else if(choose==2)
     	{
     		type_input1();
		 }
		 else
		 {
		 	printf("\n\n\tQUIT");
		 	
		 }
	end=clock();
	t=(end-start)/CLOCKS_PER_SEC;
	printf("\n\n\t time required:%f\n\n\t",t);
}

void type_input()
{
	FILE *fp;
	FILE *fr;
	
	int choose=0,r;
	int *arr,i,size,k,l=0,h;
	while(choose<=3)
	{
	
        printf("\n\n\tENTER\n\t1.RANDOM NUMBER OF INTEGER IN THE RANGE 0 TO 10^KT\n\n\t2.SORTED ARRAY OF 1\n\n\t3.ALMOST SORTED OF 1\n\n\tpress any key for exit\n\n\t");
	    scanf("%d",&choose);
	    
	    if(choose==1)
	    {
	    	printf("\tenter the limt for k\n\t");
	    	scanf("%d",&k);
	    	size=pow(10,k);
	    	h=size-1;
	    	arr=(int *)malloc(size*sizeof(int));
	    	for(i=0;i<size;i++)
	    	{
	    		arr[i]=rand()%size;
			}
			display(arr,size);
			pivot_selection(arr,l,h);
			//printf("after sorting\n");
	        //display(arr,size);
			 free(arr);
			 return;
	    	
	    	
	
     	}	
     	else if(choose==2)
     	{
     		//fp=fopen("E:\\number file\\num.txt","r+");
     		printf("\tenter the number of element k\n\t");
	    	scanf("%d",&k);
	    	h=k-1;
	    	arr=(int *)malloc(k*sizeof(int));
	    	
	    	for(i=0;i<k;i++)
	       {
		         //fscanf(fp,"%d",&arr[i]);
		         scanf("%d",&arr[i]);
         	}
         	display(arr,k);
			pivot_selection(arr,l,h);
			//fclose(fp);
			free(arr);
     		return;
		 }
		 else if(choose==3)
		 {
		 	//fr=fopen("E:\\number file\\allmost_sorted.txt","r+");
     		printf("\tenter the number of element k\n\t");
	    	scanf("%d",&k);
	    	h=k-1;
	    	arr=(int *)malloc(k*sizeof(int));
	    	
	    	for(i=0;i<k;i++)
	       {
		         //fscanf(fr,"%d",&arr[i]);
		         scanf("%d",&arr[i]);
         	}
         	display(arr,k);
			pivot_selection(arr,l,h);
			//fclose(fr);
			free(arr);
     		return;
		
		 }
		 else
		 {
		 	printf("QUIT\n");
		 	break;
		 }
	}
	
}
void type_input1()
{
	FILE *fp;
	FILE *fr;
	
	int choose=0,r;
	int *arr,i,size,k,l=0,h;
	while(choose<=3)
	{
	
        printf("\n\n\tENTER\n\t1.RANDOM NUMBER OF INTEGER IN THE RANGE 0 TO 10^KT\n\n\t2.SORTED ARRAY OF 1\n\n\t3.ALMOST SORTED OF 1\n\n\tpress any key for exit\n\n\t");
	    scanf("%d",&choose);
	    
	    if(choose==1)
	    {
	    	printf("\tenter the limt for k\n\t");
	    	scanf("%d",&k);
	    	size=pow(10,k);
	    	h=size-1;
	    	arr=(int *)malloc(size*sizeof(int));
	    	for(i=0;i<size;i++)
	    	{
	    		arr[i]=rand()%size;
			}
			display(arr,size);
			mergesort(arr,l,h);
			printf("\n\n\t After sorting....\n\n\t");
			display(arr,size);
			halt();
			//printf("after sorting\n");
	        //display(arr,size);
			 free(arr);
			 return;
	    	
	    	
	
     	}	
     	else if(choose==2)
     	{
     		//fp=fopen("E:\\number file\\num.txt","r+");
     		printf("\tenter the number of element k\n\t");
	    	scanf("%d",&k);
	    	h=k-1;
	    	arr=(int *)malloc(k*sizeof(int));
	    	
	    	for(i=0;i<k;i++)
	       {
		         //fscanf(fp,"%d",&arr[i]);
		         scanf("%d",&arr[i]);
         	}
         	display(arr,k);
			mergesort(arr,l,h);
			printf("\n\n\tAfter sorting\n\n\t");
			display(arr,k);
			halt();
			fclose(fp);
			free(arr);
     		return;
		 }
		 else if(choose==3)
		 {
		 	//fr=fopen("E:\\number file\\num.txt","r+");
     		printf("\tenter the number of element k\n\t");
	    	scanf("%d",&k);
	    	h=k-1;
	    	arr=(int *)malloc(k*sizeof(int));
	    	
	    	for(i=0;i<k;i++)
	       {
		         //fscanf(fr,"%d",&arr[i]);
		         scanf("%d",&arr[i]);
         	}
         	display(arr,k);
			mergesort(arr,l,h);
			printf("\n\n\tAfter sorting\n\n\t");
			display(arr,k);
			halt();
			fclose(fr);
			free(arr);
     		return;
		
		 }
		 else
		 {
		 	printf("QUIT\n");
		 	break;
		 }
	}
	
}

void display(int *arr,int size)
{
	int i;
	printf("\n\tYOUR LIST IS:\n\n\t");
	for(i=0;i<size;i++)
	{
	   printf("%d ",arr[i]);
	}
	printf("\n\t");
	
}
void pivot_selection(int *arr,int l,int h)
{
	int choose=0,r;
	while(choose<=4)
	{
	
        printf("\n\n\tENTER\n\t1.Choose the first element as pivot\n\n\t2.Choos the randomly the pivot element\n\n\t3.Median of 1st element,middle element,last element\n\n\t4.median of n/4th,mid,3n/4element\n\n\tpress any key for exit\n\n\t");
	    scanf("%d",&choose);
	
	    
	    if(choose==1)
	    {
	    	//type_input();
	    	quicksort1(arr,l,h,1);
	    	printf("\n\tafter sorting:\n\t");
	    	display(arr,h+1);
	    	halt();
	    	return;
	
     	}	
     	else if(choose==2)
     	{
     		//type_input();
     		quicksort1(arr,l,h,2);
	    	printf("\n\tafter sorting:\n\t");
	    	display(arr,h+1);
     		
     		halt();
     		return;
     		
		 }
		 else if(choose==3)
		 {
		 	//type_input();
		 	quicksort1(arr,l,h,3);
	    	printf("\n\tafter sorting:\n\t");
	    	display(arr,h+1);
	    	halt();
	    	return;
		
		 }
		 else if(choose==4)
		 {
		 	quicksort1(arr,l,h,4);
	    	printf("\n\tafter sorting:\n\t");
	    	display(arr,h+1);
	    	halt();
	    	return;
		 	
		 	
		 }
		 else
		 {
		 	printf("\n\tQuit\n");
		 	break;
		 }
	}
	
}
void quicksort1(int *arr,int l,int h,int choose)
{
	if(choose==1)
	{
	
	   if(l<h)
	  {
		int q;
        q = fst_pivot(arr, l, h);
        quicksort1(arr, l, q-1,1);
        quicksort1(arr, q+1, h,1);
    
		
	  }
   }
   else if(choose==2)
   {
   	    rand_partition (  arr ,  l ,  h );
   	    printf("after swapping rand\n");
   	    display(arr,h+1);
   	    int q;
        q = fst_pivot(arr, l, h);
        quicksort1(arr, l, q-1,1);
        quicksort1(arr, q+1, h,1);
   }
   else if(choose==3)
   {
   	    int m;
   	    if((h+1)%2==0)
   	    {
   	        m=h/2;	
		}
		else
		{
			m=h/2+1;
		}
   	     median_partition(arr,&arr[l],&arr[m],&arr[h], l);
   	     printf("after swapping median\n");
   	    display(arr,h+1);
   	    int q;
        q = fst_pivot(arr, l, h);
        quicksort1(arr, l, q-1,1);
        quicksort1(arr, q+1, h,1);
   }
   else
   {
   	    int x,y;
   	    x=(h+1)/4;
   	    y=(3*(h+1))/4;
   	    int m;
   	    if((h+1)%2==0)
   	    {
   	        m=h/2;	
		}
		else
		{
			m=h/2+1;
		}
   	     median_partition(arr,&arr[x],&arr[m],&arr[y], l);
   	     printf("after swapping median 2\n");
   	    display(arr,h+1);
   	    int q;
        q = fst_pivot(arr, l, h);
        quicksort1(arr, l, q-1,1);
        quicksort1(arr, q+1, h,1);
   }
	
	
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


//function for select 1st element for pivot.....
int fst_pivot(int *arr,int l,int h)
{
	int i = l + 1;
    int piv = arr[l],j ;            
    for(j =l + 1; j <=h ; j++ )  {
    
          if ( arr[ j ] < piv) {
                 swap (&arr[ i ],&arr[ j ]);
            i += 1;
        }
   }
   swap ( &arr[ l ] ,&arr[ i-1] ) ;  
   return i-1;            
}


void halt(){
		char ch='a';
		printf("\n\t\tPress \"c\" to continue...");
	
		while(1){
			scanf("%c",&ch);
			if(ch=='c' || ch == 'C')break;
		}
	}
	
	
	void rand_partition ( int *arr , int l , int h ) {
    //chooses position of pivot randomly by using rand() function .
     int random = l + rand( )%(h-l +1 ) ;

      swap ( &arr[random] ,&arr[l]) ;   
}

void median_partition(int *arr,int *f,int *s,int *t,int l)
{
	if(*t>=*s && *s>=*f || *f>=*s && *s>=*t)
	{
		swap(&arr[l],s);
	}
		if(*s>=*f && *f>=*t || *t>=*f && *f>=*s)
	{
		swap(&arr[l],f);
	}
	else
	{
		swap(&arr[l],t);
	}
}


void mergesort(int *ptr,int I,int r)
{
	int mid;
	if(I>=r) return;
		mid=(I+r)/2;
		mergesort(ptr,I,mid);
		mergesort(ptr,mid+1,r);
        merge(ptr,I,mid,r);
}
void merge(int *ptr,int I,int mid,int r)
{
	int n1,n2,i,k,j;
	n1=mid-I+1;
	n2=r-mid;
	int L[n1],R[n2];
	k = 0; 
	for(i=I;i<=mid;i++)
	{
		L[k++]=ptr[i];
	}
	k=0;
	for(j=mid+1;j<=r;j++)
	{
		
		R[k++]=ptr[j];
	}
	i=0,j=0;
    for(k=I;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			ptr[k]=L[i];
			i++;
			
			if(i == n1) {
				while (j < n2) {
        			ptr[++k] = R[j];
        			j++;
        			
    			}
				break; 
			}
			
		}
		else
		{
		    ptr[k]=R[j];
			j++;
			
			if(j == n2) {
				while (i < n1) {
        			ptr[++k] = L[i];
        			i++;
        		
    			}
				break; 	
			}
			
		}
		
	
}
}


