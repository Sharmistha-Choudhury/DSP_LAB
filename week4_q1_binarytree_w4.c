//.............................................BINARY TREE....................................................//
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}t;
t *root;
int l=0,r=0;
t* create();
int preorder(t *node);
int inorder(t *node);
int postorder(t *node);
int leftnode(t *node);
int rightnode(t *node);
int height(t *node);
void printlevel(t *node,int h);
int printcurrent(t *node, int level);

void main()
{
	int h;
	root=create();
	printf("........preorder of tree is........\n");
	preorder(root);
	printf("..........inorder of tree is..................\n");
	inorder(root);
	printf(".............postorder of tree is..............\n");
	postorder(root);
	h=height(root);
	printf("\n Height of tree is:%d\n",h);
	printf(".......print tree node........\n");
	printlevel(root,h+1);
	
}


t* create()               //creation of tree
{
	t *new;
	int item,n;
	new=(t *)malloc(sizeof(t));
	printf("press\n1.FOR new node\nany key for no new node\n ");
	scanf("%d",&n);
	if(n==1)
	{
		printf("Enter data for new node\n");
		scanf("%d",&item);
		new->data=item;
		printf("Enter data for left child of %d\n",item);
		new->left=create();
		printf("enter data for right child of %d\n",item);
		new->right=create();
		return new;
	}
	else
	{
		
		return 0;
	}
	
}
//this function used for pre order traversal
 int preorder(t *node)
  {
  	if(node)
  	{
	  
  	printf("%d \n",(node->data));
  	preorder(node->left);
  	preorder(node->right);
  }
  else
  {
  	return 0;
  }
  }
  //this function used for inorder traversal
int inorder(t *node)
  {
  	if(node)
  	{
	  
  	
  	inorder(node->left);
  	printf("%d \n",(node->data));
  	inorder(node->right);
  }
  else
  {
  	return 0;
  }
  }
  // this function used for postorder traversal
  
  int postorder(t *node)
  {
  	if(node)
  	{
	postorder(node->left);
  	postorder(node->right);
  	printf("%d \n",(node->data));
  }
  else
  {
  	return 0;
  }
  }
  //this function used to find height of left subtree
  int leftnode(t *node)
  {
  	if(node->left && node->right)
  	{
  		l++;
  		leftnode(node->left);
  		leftnode(node->right);
  		return 0;
	  }
	  if(!node->left && node->right)
	  {
	  	l++;
	  	leftnode(node->right);
	  	return 0;
	  }
	  if(node->left && !node->right)
	  {
	  	l++;
	  	leftnode(node->left);
	  	return 0;
	  }
	  if(!node->left && !node->right)
	  {
	  	return 0;
	  }
  	
  }
  //this function used to find height of right subtree
  int rightnode(t *node)
  {
  	if(node->left && node->right)
  	{
  		r++;
  		rightnode(node->left);
  		rightnode(node->right);
  		return 0;
	  }
	  if(!node->left && node->right)
	  {
	  	r++;
	  	rightnode(node->right);
	  	return 0;
	  }
	  if(node->left && !node->right)
	  {
	  	r++;
	  	rightnode(node->left);
	  	return 0;
	  }
	  if(!node->left && !node->right)
	  {
	  	return 0;
	  }
  	
  }
  //this function used to find height of tree
  int height(t *node)
  {
  	
  	int max;
  	leftnode(node->left);
  	rightnode(node->right);
  	if(l>r)
  	{
  		max=l;
	  }
	  else if(l<r)
	  {
	  	max=r;
	  }
	  else
	  {
	  	max=r;
	  }
	  return(1+max);
  }
  //this function used to find level order traversal
  void printlevel(t *node,int h)
{
    int i;
    for (i = 1; i <= h; i++)
        printcurrent(node, i);
}
 

int printcurrent(t *node, int level)
{
    if (node == NULL)
        return;
    if (level== 1)
        printf("%d ", node->data);
    else if (level > 1) {
        printcurrent(node->left, level - 1);
        printcurrent(node->right, level - 1);
    }
}
  


