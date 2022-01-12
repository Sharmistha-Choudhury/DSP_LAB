//..........................AVL TREE............................//
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{  int data;
   struct node *left;
   struct node *right;
   int h;
}node;

node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int   height( node *);
int he(node *n1);//find balance factor of a node
node * insert(node *m,int da);
node * delete(node *m,int da);
node *right(node *m);
node *left(node *m);
void preorder(node *g);
void inorder(node *g);
void postorder(node *g);
int sum(struct node *g);


void main()
{
    node *root=NULL;
    int n,choice=0,sum1,x,i;

                    while(choice!=6)
                    {
                    	printf(".......WORLD OF AVL TREE...........\n");
                    	printf("\n..................................\n");
                    	printf("\n1.create\n2.Insert\n3.delete\n4.traversing(pre,in,post)\n5.Sum\n6.EXIT\n");
                     
                        printf("\nEnter Your Choice : ");
                        scanf("%d",&choice);
                    if(choice==1)
                    {
					
                       printf("Enter no.of elements :");
                       scanf("%d",&n);
                       printf("\n Enter tree data :");
                       root=NULL;
                       for(i=0;i<n;i++)
                      {
                        scanf("%d",&x);
                        root=insert(root,x);
                      }
                    }
                    else if(choice==2)
                    {
                                    
                       printf("\nEnter a data : ");
                        scanf("%d",&x);
                        root=insert(root,x);
                    }
                   else if(choice==3)
                    {
					printf("\nEnter a data : ");
                    scanf("%d",&x);
                    root=delete(root,x);
                    }
                   else if(choice==4)
                    {
					printf("\nPreorder sequence :\n");
                    preorder(root);
                    printf("\nInorder sequence :\n");
                    inorder(root);
                    printf("\nPostorder sequence :\n");
                    postorder(root);
                    }
                    else if(choice==5)
                    {
					printf("\nSum:\n");
                    sum1=sum(root->left);
                    printf("\nSum =%d\n",sum1);
                    }
                    else if(choice==6)
                    
                    {
                    	printf("EXIT\n");
                    	break;
					}
					else
					{
						printf("wrong input\n");
					}
                    

    }

}



int he(node *n1)
{
    int l,r;
    if(n1==NULL)
    return(0);
    if(n1->left==NULL)
                l=0;
    else
                l=1+n1->left->h;
    if(n1->right==NULL)
                r=0;
    else
                r=1+n1->right->h;
    return(l-r);
}
node * insert(node *m,int da)
{
    if(m==NULL)
    {
                m=(node*)malloc(sizeof(node));
                m->data=da;
                m->left=NULL;
                m->right=NULL;
    }
    else
                if(da > m->data)                // insert in right subtree
                {
                    m->right=insert(m->right,da);
                    if(he(m)==-2)
                                if(da>m->right->data)
                                    m=RR(m);
                                else
                                    m=RL(m);
                }
                else                //insert in left subtree
                    if(da<m->data)
                    {
                                m->left=insert(m->left,da);
                                if(he(m)==2)
                                    if(da < m->left->data)
                                                m=LL(m);
                                    else
                                                m=LR(m);
                    }
                    m->h=height(m);
                    return(m);
}


node * delete(node *m,int da)
{       node *p;

    if(m==NULL)
    {
                return NULL;
    }
    else

                if(da > m->data)                // insert in right subtree
                {
                    m->right=delete(m->right,da);
                    if(he(m)==2)
                                if(he(m->left)>=0)
                                    m=LL(m);
                                else
                                    m=LR(m);
                }
                else
                    if(da<m->data)
                                {
                                    m->left=delete(m->left,da);
                                    if(he(m)==-2)//Rebalance during windup
                                                if(he(m->right)<=0)
                                                    m=RR(m);
                                                else
                                                    m=RL(m);
                                }
                    else
                      {
                                //data to be deleted is found
                                  if(m->right !=NULL)
                                  {  //delete its inorder succesor
                                      p=m->right;
                                      while(p->left != NULL)
                                      p=p->left;

                                      m->data=p->data;
                                      m->right=delete(m->right,p->data);
                                      if(he(m)==2)//Rebalance during windup
                                                if(he(m->left)>=0)
                                                    m=LL(m);
                                                else
                                                    m=LR(m);
                                   }
                                  else
                                   return(m->left);

                      }
    m->h=height(m);
    return(m);
}


int height(node *m)
{
    int l,r;
    if(m==NULL)
                return(0);
    if(m->left==NULL)
                l=0;
    else
                l=1+m->left->h;
    if(m->right==NULL)
                r=0;
    else
                r=1+m->right->h;
    if(l>r)
                return(l);
    return(r);
}


node *right(node *m)
{
    node *p;
    p=m->left;
    m->left=p->right;
    p->right=m;
    m->h=height(m);
    p->h=height(p);
    return(p);
}
node *left(node *m)
{
    node *p;
    p=m->right;
    m->right=p->left;
    p->left=m;
    m->h=height(m);
    p->h=height(p);
    return(p);
}
node * RR(node *g)
{
    g=left(g);
    return(g);
}
node * LL(node *g)
{
    g=right(g);
    return(g);
}

node * LR(node *g)
{
    g->left=left(g->left);
    g=right(g);
    return(g);
}
node * RL(node *g)
{
    g->right=right(g->right);
    g=left(g);
    return(g);
}

void preorder(node *g)
{
    if(g!=NULL)
    {
                printf(" %d(balance factor=%d)",g->data,he(g));
                preorder(g->left);
                preorder(g->right);
    }
}
void inorder(node *g)
{
    if(g!=NULL)
    {
                inorder(g->left);
                printf(" %d(balance factor=%d)",g->data,he(g));
                inorder(g->right);
    }
}
void postorder(node *g)
{
    if(g!=NULL)
    {
                postorder(g->left);
                postorder(g->right);
                printf(" %d(balance factor=%d)",g->data,he(g));
    }
    
}


int sum(struct node *g){
    int sum1=0;
	int left1=0; 
    int	right1=0;

    //Check whether tree is empty
    if(g == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    else {
        //Calculate the sum of nodes present in left subtree
        if(g->left != NULL)
            left1 =sum(g->left);

        //Calculate the sum of nodes present in right subtree
        if(g->right != NULL)
              right1 = sum(g->right);

        //Calculate the sum of all nodes by adding left1, right1 and root node's data
        sum1 = g->data +left1 +right1;
        return sum1;
  }
}


