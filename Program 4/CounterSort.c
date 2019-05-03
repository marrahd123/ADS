//Marrah Delmont
//Program 4
//CounterSort
#include<stdio.h>
#include <stdlib.h>
#include <stddef.h>

void main (int argc, char ** argv) //given
{
 if (argc < 3) //given
 {
  printf("Error\n"); //would result if you did not type the in and out files
 }
 FILE * infile = fopen(argv[1],"r"); //first arg entered in run
 FILE * outfile = fopen(argv[2],"w"); //second arg entered in run
 int x = 0;
 int * counter = (int *)malloc(1000*sizeof(int)); //initialiizing the counter pointer in counter array
 while(getc(infile)!= EOF) //while you have not reached the end of file
 {
  fscanf(infile, "%1d", &x);//scanning the file int by int
  counter[x]++; //counting occurrences of ints
 }//end while
 
 counter[x]--; //has an extra, so this is needed to fix that issue
 
 int i,j;
 for (i = 0; i<10; i++) //0 - 9
 {
  for(j=0; j<counter[i]; j++) //takes the numbers stored in the counter array and prints
  fprintf(outfile, "%d ", i);
 }
}//main
    