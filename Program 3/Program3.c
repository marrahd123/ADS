/* Marrah Delmont
Algorithms and Data Structures
Due 3/8/19
Program 3 */ 

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
 
struct node
{
  char * word;
  struct node * next;
};//struct node

int enqueue (char * string, struct node ** front, struct node ** tail);
char * dequeue (struct node ** front, struct node ** tail);

main()
{
  srand(time(NULL));
  struct node *front=NULL;
  struct node *tail=NULL;
  int stringLength=1000000;
  char * ptr;
  char * ptr2;
  //enqueue 10 nodes
  int i;
  int m;
  for(i = 0; i < 10; i++)
  {
    ptr = (char *)malloc(stringLength * sizeof(char));
    for (m=0; m<stringLength; m++)
    {
      ptr[m] = rand()%26+65;
    }
    enqueue(ptr, &front, &tail);
  }//10 nodes enqueued
    printf("%s", "Nodes: ");
    printf("%d\n",i);
  int j;
  for(j = 0; j < 100000; j++)//loop that will iterate 100,000 times
  {
    ptr = (char *)malloc(stringLength * sizeof(char));
    for (i=0; i<stringLength; i++)
    {
      ptr[i] = rand()%26+65;
    }
    enqueue(ptr, &front, &tail); //loop that will enqueue/dequeue/print x number of times
    ptr2 = dequeue(&front, &tail);
    free(ptr2);
  }
  printf("%s", "Iterations: ");
  printf("%d\n",j);
  int k;
  for(k = 0; k < 12; k++ )//dequeues 12 nodes
  {
    ptr2= dequeue(&front, &tail);
    free(ptr2);
  }//dequeue 12 nodes
}//main

int enqueue (char * string, struct node ** front, struct node ** tail)
{
  struct node * temp = (struct node *) malloc (sizeof(struct node));
  if (temp == NULL)
  {
    printf("Allocation failure!!!\n");fflush(stdout);
    return 0;
  }
  (*temp).word = string; //can add a print after this to test
  if((*front) == NULL)
  {
    temp->next = NULL;//same as (*temp). 
    *front = temp;
  }else
  {
    temp->next = NULL;
    (*tail)->next = temp;
  }
  *tail = temp;
  return 1;
}
char * dequeue (struct node ** front, struct node ** tail)
{
  struct node * temp=NULL;
  char * string = NULL;//that way, if you don't have a string, you can return the NULL instead
  if (*front != NULL)//means there is something in there
  {
    temp = *front;//so you remember where the node is
    string = (*front) -> word;//so you rememeber where its data is
    if((*front) -> next == NULL)
    {
      *tail = NULL;
    }
    (*front) = (temp) -> next;
    free(temp);//no matter what, you want to get rid of that node
  }
  return string;
}//dequeue


