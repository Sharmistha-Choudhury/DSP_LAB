//..............hashing with quadratic Probing.....................//
#include<stdio.h>
#define size 10
	
	void input();
	void hashTableInitial();
	void hash_insert();
	void hashTableInsertProcess();
	int search();
	void display();
	void hash_delete();
	void load_factor();
	void halt();
	int nextIndex(int curIndex,int p);
	int findNextEmptyIndex(int curIndex);
	void updateHashAfterDelete(int key, int deletedIndex);
	
	int hash[size];
	int key,count=0;

void main(){
		hashTableInitial();
		int choice=0;
		while(choice<=5){
			printf("....................HASHING OPERATION(PROBING DOUBLE HASHING)...............\n\n");
			printf("Select Operation--- \n1.\tInsert \n2.\tDisplay\n3.\tSearch\n4.\tDelete\n5.\tLoad factor\n\t*Any other number for quit\nEnter Your Choice : ");
			scanf("%d",&choice);
			if(choice==1){
				hashTableInsertProcess();
				
			}
			else if(choice==2){
				display();
				halt();
			}
			else if(choice==3){
				printf("\nElement for search\n");
				input();
				int index = search();
				if(index == -1)
					printf("Key(%d) is not found\n",key);
				else
					printf("Key(%d) is found at position, %d\n",key,index);
				halt();
			}
			else if(choice==4){
				printf("\nElement for delete\n");
				//input();
				hash_delete();
				halt();
			}
			else if(choice==5){
				load_factor();
				halt();
			}
			else{
				printf("\n\n\t\tQUIT");
			}
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
	

void input(){
		printf("\nENTER KEY:\n");
		scanf("%d",&key);
	}
	
	void hashTableInitial(){
		int i;
		for(i=0;i<size;i++)
		{
			hash[i]=-1;
		}
	}
	
	void display(){
		int i;
		printf("\nelements into hash table are........\n");
		printf("\nelement\t index of element_in_hash_table\n");
		printf("..........................................\n");
		for(i=0;i<size;i++)
		{
			printf("%d\t%d\n",hash[i],i);
		}
		printf("\nNo of elements  : %d\n",count);
	}
	
	int search(){
		int keyIndex = key%size;
		int curIndex=keyIndex;
		int searchCount = 0;
		int p=0;
		//printf("\n\n\nKey : %d, Size : %d, keyIndex: %d",key,size,keyIndex);
		while(searchCount < size){
			//printf("\n\nKey Index: %d, Search Count : %d",keyIndex,searchCount);
			if(hash[keyIndex] == key){
				return keyIndex;
			}
		//	if(hash[keyIndex] == -1){
				//searchCount =size-1;
				
		//	}
		     p++;
			keyIndex = nextIndex(curIndex,p);
			searchCount++;
		}
		return -1;
	}
	
	
	int nextIndex(int curIndex,int p){
		return ((curIndex+p*p)%size);
	}
	
	int findNextEmptyIndex(int curIndex){
		int p=1;
		if(hash[curIndex] == -1) return curIndex;
		else{
			int i = nextIndex(curIndex,p);
			while(i != curIndex){
				if(hash[i] == -1) return i;
				p++;
				
				i = nextIndex(curIndex,p);
			}
			return -1;
		}
	}
	
	void hash_insert(){
		int index = findNextEmptyIndex(key%size);
		//index=key%size;
		if(index != -1){
			hash[index]=key;
			count++;
			printf("\nInsertion is successful\n");
		}
		else{
			printf("\nHash Table full. Insertion not posssible\n");
		}
	}
	
void hashTableInsertProcess(){
	int n,i;
	printf("\nEnter total elements You want to insert... ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		input();
		hash_insert();
	}   			
	halt();
}

void hash_delete(){
		input();
		int deletedIndex = search();
		printf("\n\nIndex, %d of Deleted Element, %d",deletedIndex,key);
		int deletedElement;
		if(deletedIndex == -1){
			printf("Key(%d) is not found, deletion is not possible\n",key);
			return;
		}
		deletedElement = hash[deletedIndex];
		//new
		count--;
		//end
		
		updateHashAfterDelete(key, deletedIndex);
		printf("\nKey,(%d) is deleted successfully",deletedElement);
	}
	
	void load_factor(){
		float l, m=count;
		l=m/size;
		printf("\nCount=%d load factor=%f\n",count,l);
	}
	
	void updateHashAfterDelete(int key, int deletedIndex){
		int keyIndex = key % size;
		int deletedFromIndex = deletedIndex;
		//For all key with same as index
		int i = deletedFromIndex;
		hash[i] = -1;
		int p=1;
		int j = nextIndex(i,p);
		while(j != keyIndex){
			if((hash[j]%size) == keyIndex){
				hash[i] = hash[j];
				i = j;
				hash[i] = -1;
			}
			p++;
			j = nextIndex(j,p);
		}
	
}

