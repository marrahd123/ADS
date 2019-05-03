//Marrah Delmont
//Program 4 - counter Sort
//ADS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_INTS 100

int main () //void main(int argc, char ** argv)
{
 int counter[MAX_INTS];
 char ints[MAX_INTS][MAX_INTS];//distinct integer list
 char number[MAX_INTS];//list of numbers you're reading in 
 printf("Enter integer file: ");
 scanf("%s", number);
 FILE * infile = fopen(number,"r");  //FILE * infile = fopen(argv[1],"r");
 
 // Initialize num counter to 0
 int i;
 for (i=0; i<MAX_INTS; i++)
  counter[i] = 0;

 int isUnique;
 int index;

 while (fscanf(infile, "%s", number) != EOF)
 {
 // Check if number exits in list of all distinct ints
 isUnique = 1;
 for (i=0; i<index && isUnique; i++)
 {
  if (strcmp(ints[i], number) == 0)
   isUnique = 0;
 }
 
 // If number is unique then add it to distinct ints list
 // and increment index. Otherwise increment occurrence 
 // counter of current number.
 if (isUnique) 
 {
 strcpy(ints[index], number);
 counter[index]++;
 index++;
 }
 else
 {
  counter[i - 1]++;
 }
}
 // Close file
 fclose(infile);
 
 printf("\nOccurrences: \n");
 for (i=0; i<index; i++)
 {
  printf("%s-> %d\n", ints[i], counter[i]);
 }
 
 return 0;
}//main