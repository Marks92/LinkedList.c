#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct NODE
{
 struct NODE *link;
 int value;
};

typedef struct NODE Node;

#include "myLLfunctions.c"

Node *insertFirst( Node **ptrToHeadPtr, int val )
{
 Node *node = (Node *)malloc( sizeof( Node ) );
 node->value = val;
 node->link = *ptrToHeadPtr;
 *ptrToHeadPtr = node;
 return node;
}

void traverse( Node *p )
{
 while( p != NULL )
 {
  printf("%d ", p->value);
  p = p->link;
 }
}

void freeList( Node *p )
{
 Node *temp;
 while( p != NULL )
 {
  temp = p;
  p = p->link;
  free( temp );
 }
}

int main()
{
 Node *HeadPtr = NULL;
 int j;
 for( j=0; j<13; j++ )
  insertFirst( &HeadPtr, j );
 if(countTarget(HeadPtr,5))
  printf("List contains target %d time(s)\n", countTarget(HeadPtr,5));
 else
  printf("List does not contain that value");
 printf("Minimum value is: %d\n", findMin(HeadPtr, 100));
 printf("List before first element is deleted: \n");
 traverse( HeadPtr );
 freeList( HeadPtr );
 printf("\nList after first element is deleted: \n");
 deleteFirst(&HeadPtr);
 traverse( HeadPtr );
 
 getchar();
 return 1;
}
