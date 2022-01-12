//..................TREE PROGRAM...................................//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Frequency_Node{
	int freq,level;
}frequencyNode;

typedef struct word_Node{
	frequencyNode *frequency;
	char *word;
	int level;
	struct word_Node *sibling;
}wordNode;

typedef struct category_Node{
	wordNode *leftChild;
	char *categoryData;
	int categoryKey,level;
	struct category_Node *sibling;
}categoryNode;

typedef struct root_Node{
	categoryNode *leftChild;
	char *rootData;
	int level;
}rootNode;

rootNode *ROOT = '\0';

categoryNode* createCategoryNode(); 
void createRoot();
void createCategory();
wordNode* createWordNode();
void createWord();
frequencyNode* createFrequency();
char* readString(int);


void showMenuOption();
int readUserOperation();
int generateCategoryKey(char *category);
categoryNode* findCategoryOfWord(char *word);
int wordRepeat(wordNode *ptr, char *word);

void displayTree();

int main()
{
	int selectoption;
	//createRoot();
	do{
		showMenuOption();
		selectoption = readUserOperation();
			if(selectoption==1)
			{
			
				createRoot();
				createCategory();
				createWord();
			}
			
			if(selectoption==2)
			{
			
				printf("\nUnder Construction");
	     	}
			if(selectoption==3)
			{
			
				printf("\nUnder Construction");
		     }
			if(selectoption==4)
			{
			
				printf("\nUnder Construction");
		     }
			
			if(selectoption==5)
			{
			
				printf("\nUnder Construction");
		     }
			
			if(selectoption==6)
			{
			
				displayTree();
		    }
				
		
	}while(selectoption != 7);
	
	return 0;
}

char* readString(int type){
	char* str = (char*)malloc(20*sizeof(char));
	fflush(stdin);
	if(!type){ /*For root input type = 0*/ 
		printf("\nEnter root value...\n");
		gets(str);
	}
	else if(type == 1){
		printf("\nEnter Category value...\n");
		gets(str);
	}
	else{
		printf("\nEnter Word value...\n");
		gets(str);
	}
	
	return str;
}
void createRoot(){
	if(ROOT == '\0'){
		ROOT = (rootNode*)malloc(sizeof(rootNode));
		ROOT->rootData = readString(0);
		ROOT->leftChild = '\0';
		ROOT->level = 0;
	}
}
void createCategory(){
	int checkContinue = 0;
	categoryNode* newNode = '\0', *ptr='\0';
	char *category = '\0';
	while(1){
		newNode = createCategoryNode();
		category = readString(1);
		newNode->categoryKey = generateCategoryKey(category);
		newNode->categoryData =category;
		// For insert 1st category node
		if(ROOT->leftChild == '\0'){
			ROOT->leftChild = newNode;
		}
		else{
			// For insert category node from 2nd & more
			ptr = ROOT->leftChild;
			while(ptr->sibling != '\0')
				ptr = ptr->sibling;
			ptr->sibling = newNode;
		}
		newNode = '\0';
		printf("\nFor reading category, enter-- \n\t1 to continue \n\t0 to stop \n\t\t Your Option Please :  ");
		scanf("%d",&checkContinue);
		if(checkContinue != 1) break;
	}
}
void createWord(){
	int checkContinue = 0;
	wordNode* newNode = '\0', *ptr='\0';
	categoryNode *cPtr = '\0';
	char *word = '\0';
	while(1){
		word = readString(2);
		cPtr = findCategoryOfWord(word);
		//if(cPtr) printf("\n\nHELLO: %s\n\n",cPtr->categoryData);
		
		if(cPtr->leftChild){
			ptr = cPtr->leftChild;
			//Check for Repeat if Repeat add frequency
			if(!wordRepeat(ptr, word))
			{
				//If no repeat add at last
				newNode = createWordNode();	// Done
				newNode->word = word;
				while(ptr->sibling != '\0') ptr = ptr->sibling;
				ptr->sibling = newNode;
			}
		}
		else{
			newNode = createWordNode();
			newNode->word = word;
			cPtr->leftChild = newNode;
		}
		newNode = '\0';
		word = '\0';
		cPtr='\0';
		printf("\nFor reading word, enter-- \n\t1 to continue \n\t0 to stop \n\t\t Your Option Please :  ");
		scanf("%d",&checkContinue);
		if(checkContinue != 1) break;
	}
}
frequencyNode* createFrequency(){
	frequencyNode* newNode = (frequencyNode*)malloc(sizeof(frequencyNode));
	newNode->freq = 2;
	newNode->level = 4;
	return newNode;
}

int wordRepeat(wordNode *ptr, char *word){
	while(ptr != '\0'){
		if(!strcmp(strlwr(ptr->word), strlwr(word))){
			if(ptr->frequency == '\0')
				ptr->frequency = createFrequency();
			else
				ptr->frequency->freq += 1; 	
			return 1;
		} 
		ptr = ptr->sibling;
	}
	return 0;
}


int categoryKeyFromWord(char* word){
	if(!(strcmp(strlwr(word),"exercise")&&strcmp(strlwr(word),"football")))return 1;
	if(!(strcmp(strlwr(word),"book")&&strcmp(strlwr(word),"studying")&&strcmp(strlwr(word),"class")&&strcmp(strlwr(word),"assignment")))return 2;
	if(!(strcmp(strlwr(word),"lunch")&&strcmp(strlwr(word),"cake")))return 3;
	if(!(strcmp(strlwr(word),"meeting")&&strcmp(strlwr(word),"project")))return 4;
	if(!(strcmp(strlwr(word),"gardening")&&strcmp(strlwr(word),"book reading")&&strcmp(strlwr(word),"story telling")))return 5;
	if(!(strcmp(strlwr(word),"relative")&&strcmp(strlwr(word),"daughter")))return 6;
	if(!(strcmp(strlwr(word),"god")&&strcmp(strlwr(word),"prayer")))return 7;
}

categoryNode* findCategoryOfWord(char *word){
	//printf("\n\n%s\n\n",word);
	categoryNode* ptr = ROOT->leftChild;
	int key = categoryKeyFromWord(word);
	while(ptr!='\0'){
		if(ptr->categoryKey == key)
			return ptr;
		ptr=ptr->sibling;
	}
	
	printf("\n\nSorry!! Category not found");
	return '\0';		 
}

categoryNode* createCategoryNode(){
	categoryNode* newNode = (categoryNode*)malloc(sizeof(categoryNode));
	newNode-> leftChild = '\0';
	newNode->categoryData = '\0';
	newNode->categoryKey = 0;
	newNode->sibling = '\0';
	newNode->level = 1;
	
	return newNode;
}

wordNode* createWordNode(){
	wordNode* newNode = (wordNode*)malloc(sizeof(wordNode));
	newNode->frequency = '\0';
	newNode->word = '\0';
	newNode->level = 2;
	newNode->sibling = '\0';
	
	return newNode;
}



void showMenuOption(){
	printf("Available Operation:\n");
	printf("\t1.\tCreate Tree.\n");
	printf("\t2.\tDisplay leaf nodes excluding level 4.\n");
	printf("\t3.\tFind depth of a node.\n");
	printf("\t4.\tFind degree of a node.\n");
	printf("\t5.\tDisplay words in frequency descending order.\n");
	printf("\t6.\tDisplay Tree.\n");
	printf("\t7.\tExit.\n\n");
}
int readUserOperation(){
	int operation;
	printf("\n\t\tEnter the operation : ");
	scanf("%d",&operation);
	return operation;
}

void displayTree(){
	rootNode *ptr = ROOT;
	
	if(!ptr){
		printf("\nSorry! no Elemnt in the Tree.");
		return;
	}
	
	printf("\n Root: %s",ptr->rootData);
	categoryNode* cptr = ptr->leftChild;
	
	while(cptr){
		printf("\n\nCategories :");
		printf("\t%s",cptr->categoryData);
		wordNode *wptr = cptr->leftChild;
		while(wptr){
			printf("\n\t\tWords :");
			printf("\t\t%s",wptr->word);
			if(wptr->frequency!='\0'){
				printf("\n\t\t\tFrequency :");
				printf("%d",wptr->frequency->freq);
			}
			
			wptr = wptr->sibling;
		}
		cptr = cptr->sibling;
	}
	int x;
	printf("\n\n\t\tEnter 1 to continue.");
	scanf("%*d",&x);

}

int generateCategoryKey(char *category){
	if(!strcmp(strlwr(category),"physical activity")) return 1;	
	if(!strcmp(strlwr(category),"education")) return 2;
	if(!strcmp(strlwr(category),"food")) return 3;
	if(!strcmp(strlwr(category),"work")) return 4;
	if(!strcmp(strlwr(category),"hobby")) return 5;
	if(!strcmp(strlwr(category),"family")) return 6;
	if(!strcmp(strlwr(category),"worship")) return 7;
}










