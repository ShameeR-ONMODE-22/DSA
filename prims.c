#include<stdio.h>
#include<stdbool.h> 
#include<string.h>

#define INF 9999999
#define V 5
void topo (int G[20][20] ,int size);

int main() {
	int i,j,size,G[20][20];
	printf("ENTER THE SIZE OF THE MATRIX\n");
	scanf("%d",&size);
	printf("ENTER THE ADJACENCY OF THE MATRIX :\n");
	for (i=0;i<size;i++)
	{
    	for (j=0;j<size;j++)
	 	{
	 		scanf("%d",&G[i][j]);
	 	}
	 }
	 
  int no_edge;  
  int selected[V];

  memset(selected, false, sizeof(selected));
  
  no_edge = 0;


  
  selected[0] = true;

  int x;  
  int y;  

  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    

    int min = INF;
    x = 0;
    y = 0;
int i,j;
    for (i = 0; i < V; i++) {
      if (selected[i]) {
        for (j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
