#include<stdio.h>
#include<malloc.h>

typedef struct QE{
	int data;
	struct QE *next;
}QueueElement;

typedef struct{
	QueueElement *front, *rear;
	int Qlength;
}QUEUE;
void InsertElement(QUEUE *arr, int Qno, int Qlength);
void CreateArray(QUEUE *arr);
void DisplayArray(QUEUE *arr);
int findIndexOfMinimumNumberQueue(QUEUE *arr);
int findIndexOfMaximumNumberQueue(QUEUE *arr);
void deleteFromQueue(QUEUE *arr);
void insertIntoQueue(QUEUE *arr);

int main(){
	QUEUE arr[4];
	int i;
	CreateArray(arr);
	printf("\n----------------------\n\nFour Queue in an Array : ");
	DisplayArray(arr);
	printf("\n----------------------\n\nPerform 3 Delete Operation : ");
	deleteFromQueue(arr);
	deleteFromQueue(arr);
	deleteFromQueue(arr);
	printf("\n----------------------\n\nPerform 2 Insert Operation : ");
	insertIntoQueue(arr);
	insertIntoQueue(arr);
	printf("\n----------------------\n\nPerform 1 Delete Operation : ");
	deleteFromQueue(arr);
	printf("\n----------------------\n\nQueue After perform all the Operations : ");
	DisplayArray(arr);
	return 0;
}

void InsertElement(QUEUE *arr, int Qno, int Qlength){
	int i,input_data;
	QueueElement *temp;
	printf("\nEnter %d element for Q%d:---\n",Qlength,Qno+1);
	for(i=0;i<Qlength;i++){
		scanf("%d",&input_data);
		temp = (QueueElement*)malloc(sizeof(QueueElement));
		temp->data = input_data;
		temp->next = NULL;
		if(i==0){
			(arr+Qno)->front = temp;
			(arr+Qno)->rear = temp;
			(arr+Qno)->Qlength = 1;
		}
		else{
			(arr+Qno)->rear->next = temp;
			(arr+Qno)->rear = temp;
			(arr+Qno)->Qlength += 1;
		}
		temp = NULL;
	}
}
void CreateArray(QUEUE *arr){
	InsertElement(arr,0,5);
	InsertElement(arr,1,3);
	InsertElement(arr,2,2);
	InsertElement(arr,3,6);
}

void DisplayArray(QUEUE *arr){
	int i;
	QueueElement *ptr = NULL;
	for(i=0;i<4;i++){
		printf("\n\nQueue_%d : ",i+1);
		ptr = (arr+i)->front;
		while(ptr!=NULL){
			printf("\t%d",ptr->data);
			ptr = ptr->next;
		}
		printf(",\tTotal Element: %d",(arr+i)->Qlength);
		
	}
}

int findIndexOfMinimumNumberQueue(QUEUE *arr){
	int min_index = 0, i,min_len = (arr+0)->Qlength;
	for(i=1;i<4;i++){
		if((arr+i)->Qlength < min_len){
			min_len = (arr+i)->Qlength;
			min_index = i;
		}
	}
	
	return min_index;
}
int findIndexOfMaximumNumberQueue(QUEUE *arr){
	int max_index = 0, i=1,max_len = (arr+0)->Qlength;
	for(i=1;i<4;i++){
		if((arr+i)->Qlength > max_len){
			max_len = (arr+i)->Qlength;
			max_index = i;
		}
	}
	
	return max_index;
}

void deleteFromQueue(QUEUE *arr){
	int index = findIndexOfMaximumNumberQueue(arr);
	int deletedElement = (arr+index)->front->data;
	QueueElement *ptr = (arr+index)->front;
	(arr+index)->front = ptr->next;
	ptr->next = NULL;
	free(ptr);
	printf("\n%d is deleted from Q%d.",deletedElement,index+1);
	(arr+index)->Qlength -=1;
	
}
void insertIntoQueue(QUEUE *arr){
	int index = findIndexOfMinimumNumberQueue(arr);
	int inputData;
	printf("\nEnter One Element :---\n");
	scanf("%d",&inputData);
	
	QueueElement *new = (QueueElement*)malloc(sizeof(QueueElement));
	new->data = inputData;
	new->next = NULL;
	if((arr+index)->Qlength == 0){
		(arr+index)->Qlength = 1;
		(arr+index)->front = new;
		(arr+index)->rear = new;
	}
	else{
		(arr+index)->Qlength += 1;
		(arr+index)->rear->next = new;
		(arr+index)->rear = new;
		
	}
	new = NULL;
	printf("\nCongratulations! %d is inserted in Q%d",inputData,index+1);
}
