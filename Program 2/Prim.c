/* Marrah Delmont
Algorithms and Data Structures 
Due Friday, February 22
*/
#include<stdio.h>
#define INFINITY 9999
int main(void)
{
	//1. Initialize and print the matrix 
	int matrix[5][5] = {{0,2,0,6,0}, 
                    {2,0,3,8,5}, 
                    {0,3,0,0,7}, 
                    {6,8,0,0,9}, 
                    {0,5,7,9,0}};
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
	int span[5][5]; 
	int cost[5][5];//same as the matrix, just changeable 
	int distance[5];//keeps track of cost between nodes
	int prev[5];//keeps track of previously visited nodes
	int visited[5];//1 if visited; 0 if not visited
	int shortestPath;//variable used to traverse through matrix to find shortest path
	int next;//will be used to check next node in matrix to see if shorter path exists
	int start;//where the path starts at (is 0,0 in this case but could be modified)
	int minCost;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			if(matrix[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=matrix[i][j];
				span[i][j]=0;
		}
		distance[0]=0;
		visited[0]=1;
		
		for(i=1;i<5;i++)
		{
			distance[i]=cost[0][i];
			prev[i]=0;
			visited[i]=0;
		}
	
	minCost=0;		//cost of spanning tree
	int vertices = 4; //5-1
	int u;
	
	while(vertices>0)
	{
		//find the vertex at minimum distance from the tree
		shortestPath=INFINITY;
		for(i=1;i<5;i++)
			if(visited[i]==0&&distance[i]<shortestPath)
			{
				next=i;
				shortestPath=distance[i];
			}
			u=prev[next];
		
		//insert the edge in spanning tree
		span[u][next]=distance[next];
		span[next][u]=distance[next];
		vertices--;
		visited[next]=1;
		
		//updated the distance[] array
		for(i=1;i<5;i++)
			if(visited[i]==0&&cost[i][next]<distance[i])
			{
				distance[i]=cost[i][next];
				prev[i]=next;
			}
		
		minCost=minCost+cost[u][next];
	}
	
	printf("\nPrim's Matrix:\n");
	
	for(i=0;i<5;i++)
	{
		printf("\n");
		for(j=0;j<5;j++)
			printf("%d\t",span[i][j]);
	}
	printf("\n\nTotal cost of spanning tree=%d",minCost);
	printf("\n");
}//end main

/*Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5 */

