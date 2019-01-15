/* CS 153 PROGRAM ASSIGNMENT #9

Functions that count the frequency of 
a target value, find the minimum value in
a list, and delete the first node.


Mark Schuberth 
 
11/20/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

/* counts the frequency of a given target int */
int countTarget(Node *start, int target)
{
 /* count initialized to 0 */
 int count = 0;
 /* while list is not empty continue */
 while(start != NULL)
 {
  /* counts frequency of target int value */
  /* while traversing the list */
  if(start->value == target)
   count++;
  start = start->link;
 }
 return count;
}

/* finds the minimum element in the list */
/* min starts at int_MAX and compares each */
/* int in the list to this number */
int findMin(Node *start, int min)
{
 /* min starts at int_max */
 min = INT_MAX;
 /* loops from beginning of list */
 while(start != NULL)
 {
  /* if min is great than value */
  /* new value is now new min */
  if(min > start->value)
   min = start->value;
  start = start->link;
 }
 return min;
}

/* function deletes first element */
int deleteFirst(Node **ptrToHeadPtr)
{
 /* sets start pointer to first element */
 /* start is set to ptrToHeadPtr */
 Node *start = *ptrToHeadPtr;
 if(start != NULL && start->value)
 {
  *ptrToHeadPtr = start->link;
  
  free(ptrToHeadPtr);
 }
 /* if list is empty return 0 */
 else if(start == NULL)
 {
  return 0;
 }
}
