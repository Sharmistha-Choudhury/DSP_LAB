///...................TOWER OF HANOI WITHOUT RECURSION...................//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
 

struct arr1
{
unsigned capacity;
int *arr;
int top;
};

struct arr1* createStack(unsigned capacity);
int isFull(struct arr1* st);
int isEmpty(struct arr1* st);
void push(struct arr1 *st, int item);
int pop(struct arr1* st);
void moveDisk1(char fromPeg, char toPeg, int disk);
void moveDisks2(struct arr1 *src,struct arr1 *dest, char s, char d);
void toh(int num_of_disks, struct arr1 *src, struct arr1 *aux,struct arr1 *dest);



int main()
{
   
    unsigned disks = 3;
 
    struct arr1 *src, *dest, *aux;
 
    
    src = createStack(disks);
    aux = createStack(disks);
    dest = createStack(disks);
 
    toh(disks, src, aux, dest);
    return 0;
}


struct arr1* createStack(unsigned capacity)
{
    struct arr1* st =
        (struct arr1*) malloc(sizeof(struct arr1));
    st -> capacity = capacity;
    st -> top = -1;
    st -> arr =
        (int*) malloc(st -> capacity * sizeof(int));
    return st;
}
 

int isFull(struct arr1* st)
{
return (st->top == st->capacity - 1);
}
 

int isEmpty(struct arr1* st)
{
return (st->top == -1);
}
 

void push(struct arr1 *st, int item)
{
    if (isFull(st))
        return;
    st -> arr[++st -> top] = item;
}
 

int pop(struct arr1* st)
{
    if (isEmpty(st))
        return INT_MIN;
    return st -> arr[st -> top--];
}
 
//Display the movements
void moveDisk1(char fromPeg, char toPeg, int disk)
{
    printf("Move the disk %d from \'%c\' to \'%c\'\n",
        disk, fromPeg, toPeg);
}
 
//movements of the disk
void moveDisks2(struct arr1 *src, struct arr1 *dest, char s, char d)
{
    int pole1 = pop(src);
    int pole2 = pop(dest);
 
    
    if (pole1 == INT_MIN)
    {
        push(src, pole2);
        moveDisk1(d, s, pole2);
    }
 

    else if (pole2 == INT_MIN)
    {
        push(dest, pole1);
        moveDisk1(s, d, pole1);
    }
 
    else if (pole1 > pole2)
    {
        push(src, pole1);
        push(src, pole2);
        moveDisk1(d, s, pole2);
    }
 
    
    else
    {
        push(dest, pole2);
        push(dest, pole1);
        moveDisk1(s, d, pole1);
    }
}
 

void toh(int num_of_disks, struct arr1 *src, struct arr1 *aux,struct arr1 *dest)
{
    int i, total_moves;
    char s = 'S', d = 'D', a = 'A';
 
    
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_moves = pow(2, num_of_disks) - 1;
 
    
    for (i = num_of_disks; i >= 1; i--)
        push(src, i);
 
    for (i = 1; i <= total_moves; i++)
    {
        if (i % 3 == 1)
        moveDisks2(src, dest, s, d);
 
        else if (i % 3 == 2)
        moveDisks2(src, aux, s, a);
 
        else if (i % 3 == 0)
        moveDisks2(aux, dest, a, d);
    }
}
 


