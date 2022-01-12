//.............................INPUT STRING IS VALID OR NOT..............................................//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
char pop();
void push(char a);

int main()
{
	int count=0,count1=0, flag=0;
	char arr[100];
	char *ptr,ch;
	printf("\n.............ENTER THE STRING..............\n");
	scanf("%s",&arr);
	ptr=arr;
	while(*ptr != '\0')
	{
		//when we get open braces we push it into stack & count the number of open braces.....//
		if((*ptr == '{') || (*ptr == '[') || (*ptr == '('))
		{
			count++;
			push(*ptr);
		}
		//when we get close braces we pop the top element & matches with the pop element & current elemnt & if it matches then flag is set to 1//
		else if((*ptr == '}') || (*ptr == ']') || (*ptr == ')'))
		{
			count1++;
			ch=pop();
			if( ( ( *ptr==')' ) && ( ch!='(' ) ) || ( ( *ptr == '}' ) && ( ch!='{' ) ) || ( ( *ptr == ']' ) && ( ch!='[' ) ))
			{
				flag = 1;
			}
		}
		//this is for other element except braces
		else
		{
			printf("\n.......INVALID INPUT STRING............\n");
			exit(1);
		}
		ptr++;
	}
	if(count != count1)
	{
		flag = 1;
	}
	if(flag==0)
		printf("\n................INPUTED STRING IS VALID.............\n");
	else
		printf("\n..........INPUTED STRING IS INVALID......................\n");
	return 0;
}


char pop()
{
	char a;
	struct node *t;
	if(head == NULL)
		printf("...................STACK IS EMPTTY....................\n");
	else
	{
		t=head;
		head=head->next;
		a=t->data;
		free(t);
		return a;
	}	
}

void push(char a)
	{
		struct node *new=(struct node*)malloc(sizeof(struct node*));
		if(new==NULL)
			printf("Memory is not allocated for new node........\n");
		else
		{			
				new->data=a;
				new->next=head;
				head=new;
		}
	}









