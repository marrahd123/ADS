/* Marrah Delmont
Algorithms and Data Structures 
Due Friday, February 8
*/

#include<stdio.h>
#define INFINITY 9999
int main(void)
{
	//1. Initialize and print the matrix 
	int matrix[5][5] = {{0,10,0,30,100},
                        {10,0,50,0,0},
                        {0,50,0,20,10},
                        {30,0,20,0,60},
                        {100,0,10,60,0}};
	printf("Here is the matrix:");
	int i;
	int j;
    for (i = 0;i<5;++i)
    {
        printf("\n");
        for(j=0;j<5;++j)
        {
            printf("%d\t", matrix[i][j]);
        }
    }
	printf("\n");
	//2. Define variables
	int cost[5][5];//same as the matrix, just changeable 
	int distance[5];//keeps track of cost between nodes
	int prev[5];//keeps track of previously visited nodes
	int visited[5];//1 if visited; 0 if not visited
	int shortestPath;//variable used to traverse through matrix to find shortest path
	int next;//will be used to check next node in matrix to see if shorter path exists
	int start;//where the path starts at (is 0,0 in this case but could be modified)
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(matrix[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=matrix[i][j];
	for(i=0;i<5;i++)
	{
		distance[i]=cost[start][i];//initializes distance
		prev[i]=start;//initializes previous, since it's at start then nothing is prev
		visited[i]=0;//sets all nodes to unvisited
	}
	
	distance[start]=0;//sets cost at 0,0 to 0 (since it's the starting node)
	visited[start]=1;//sets the starting node to being visited
	j=1;//won't start at 0,0
	while(j<4)//I got 4 from count being 5-1 since there are 5 nodes and one is itself
	{
		shortestPath=INFINITY;//starts off with highest amount possible until it can be reduced
		for(i=0;i<5;i++)
			if((distance[i]<shortestPath) &&(visited[i]!=1))//if cost is less than the shortest path and has not been visited
			{
				shortestPath=distance[i];//new shortest path is updated to current cost
				next=i; //sets a value to next which will be used next
			}
			visited[next]=1; //sets visited at i to 1 to mark that the node has been visited
			//check if a better path exists 			
			for(i=0;i<5;i++)
			{
				if(visited[i]!=1)//if has not been visited
					if(shortestPath+cost[next][i]<distance[i])
					{
						distance[i]=shortestPath+cost[next][i];//sets value of cost to the sum of shortest path and the cost of the next value
						prev[i]=next;//sets value of previous checked node to "next"
					}
			}//for loop to check for better path
		j++;
	}
	for(i=0;i<5;i++)
		if(i!=start)
		{
			printf("Distance of node%d=%d",i,distance[i]); //prints distance/cost from one node to another
			printf("\n");
			printf("Path=%d",i);//prints the path the nodes take
			
			j=i;
			while(j!=start)
			{
				j=prev[j];
				printf(" comes from %d",j);
			}
			printf("\n");
			printf("Total Cost: %d", distance[i]);//the final cost is the total cost
			printf("\n");
		}
}//end main
