#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int min(int dis[], int vit[]){
	int min=100000;
	int i;
	int m;

	for(i=0; i<64; i++){
		if(dis[i] < min && dis[i]>0 && vit[i] == 0){
			min = dis[i];
			m = i;			
		}	
	}
	return m;
}

int bfs (graph_t * g, int start, int end){
	int n_queue = 0;
	int queue[64];
	int head = 0;
	int tail = 0;
	int result=0;
	int length=0;
	int r=1;
	int w;
	
	int* distance = (int*)malloc(sizeof(int)*64);	
	memset(distance, 10000, sizeof(int)*64);
	distance[start] = 0;

	int visited[64];
	memset(visited, 0, sizeof(int)*64);	

	queue[tail++] = start; n_queue++; visited[start] = 1;    // enqueue
	
	while(n_queue > 0){
		int curr = queue[head++];
		n_queue--;                        // dequeue
		printf("[DEBUG] curr: %d \n", curr);

		for(int neighbor=0; neighbor < g->n_vertices; neighbor++){
			if(g->m[curr][neighbor] > 0){	
				if(r==1){
					if(g->m[curr][neighbor] > 1){
						int min = 1000000000;
						int c;
						for(int i=0; i < g->m[curr][neighbor]; i++){
							if(g->w[curr][neighbor][i] < min && curr != neighbor){
								min = g->w[curr][neighbor][i];
								c=i;
					//			printf("DEBUG min: %d\n", min);
							}		
						}
						distance[neighbor] = g->w[curr][neighbor][c];
					//	printf("[DEBUG] distance[XMR][%d]:%d\n", neighbor, distance[neighbor]);

					} 
					else{
						distance[neighbor] = g->w[curr][neighbor][0];
						printf("[DEBUG] distance[%d]:%d\n", neighbor, distance[neighbor]);
					}
				}
				else{
					if(g->m[curr][neighbor] > 1){
						int min = 1000000000;
						int c;
						for(int i=0; i < g->m[curr][neighbor]; i++){
							if(g->w[curr][neighbor][i] < min && curr != neighbor){
								min = g->w[curr][neighbor][i];
								c=i;
					//			printf("DEBUG min: %d\n", min);
					//			printf("DEBUG c: %d\n", c);
							}		
						}
						if(distance[curr] + g->w[curr][neighbor][c] < distance[neighbor]){
							distance[neighbor] = distance[curr] + g->w[curr][neighbor][c];	
					//		printf("[DEBUG] distance[XMR][%d]:%d\n", neighbor, distance[neighbor]);
						}
					} 
					else{
					if(distance[curr] + g->w[curr][neighbor][0] < distance[neighbor]){
						distance[neighbor] = distance[curr] + g->w[curr][neighbor][0];	
						printf("[DEBUG] distance[%d]:%d\n", neighbor, distance[neighbor]);
					}
					}
				}
			}
		}
		r++;		

		int k = min(distance, visited);	
//		printf("[DUBUG] k: %d\n", k);
			
		if(visited[k]==0){
			queue[tail++] = k;
			n_queue++;
			visited[k]=1;
//			w = g->w[curr][k][0];
			printf("[DEBUG] enqueue %d\n", k); // enqueue
		}			
	}
//	for(int p=0; p<64; p++){
//		printf("[DEBUG] distance[%d]: %d\n", p, distance[p]);
//	}	
//	printf("[DEBUG] Return: distance[%d] %d\n",end, distance[end]);
	return distance[end];
}

/*TODO: you can add functions as you want */

int
main (int argc, char ** args)
{
	graph_t * g ; 

	g = graph_read_stdin() ;

	if (argc != 3) { 
		fprintf(stderr, "Too few arguments\n") ;
		return 1 ;
	}

	int start, end ;

	start = atoi(args[1]) ;
	end = atoi(args[2]) ;

	if (start < 0 || g->n_vertices <= start ||
		end < 0 || g->n_vertices <= end) {
		fprintf(stderr, "Wrong arguments\n") ;
		return 1 ;
	}

	int result;
	result = bfs(g, start, end);
	
	if(start==end){
		printf("0\n");
	}
	else if(result > 256000000){
//		printf("도달할 수 없는 vertex");
		return 0;
	}
	else { 
		printf("%d\n", result);
	}

//	printf("%d\n", result);
	graph_free(g) ;
	return 0;
}
