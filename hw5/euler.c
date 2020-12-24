#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

/*TODO: you can add functions as you want */

int euler(graph_t * g){
	int check[64];
	memset(check, 0, sizeof(int)*64);
	int a=0;
	
	for(int i=0; i < g->n_vertices; i++){
		for(int j=0; j < g->n_vertices; j++){
			if(g->m[i][j] > 0){
				if(g->m[i][j] > 1){
					for(int k=0; k< g->m[i][j]; k++){
						if(i==j){
							check[i] = check[i] + 2;		
						}
						else{
							check[i] = check[i] + 1;		
						}
					}
				}
				else{
//				printf("check[%d]: %d\n", i, check[i]);
					if(i==j){
						check[i] = check[i] + 2;		
					}
					else{
						check[i] = check[i] + 1;		
					}
				}
			}
		}
	}
	for(int i=0; i<64; i++){
//		printf("check[%d]: %d\n", i, check[i]);
		if(check[i]%2 != 0){
			a++;
		}
	}	
	if(a==0){
		return 1;
	}
	else if (a==2){
		return 2;
	}
	else{
		exit(1);	
	}
}

int stack[64];
int result[64];
int top=0;
int top2=0;

void tour(graph_t * g, int start)
{
	int n_edges, next;
	int curr = start;


	do{
//		printf("[DEBUG] curr: %d  ", curr);
		for(next=0; next < g->n_vertices; next++){
			if(g->m[curr][next] > 0){
				break;
			}
		}
		if(next < g->n_vertices){
//			printf("[DEBUG] next: %d\n", next);
			graph_remove_edge(g, curr, next, g->w[curr][next][0]);
			stack[top] = curr;
//			printf("[DEBUG] top: %d, stack[top]: %d\n", top, stack[top]);
			top++;
			curr = next;
		}
		else{
//			printf("no edge\n");
			stack[top] = curr;
//			printf("[DEBUG] top: %d, stack[top]: %d\n", top, stack[top]);
			result[top2] = stack[top];
			top--;
			top2++;	
			if(top>0){	
				tour(g, stack[top]);
			}
		}	
	}while(next != g->n_vertices);
	
}

int
main ()
{
	graph_t * g ; 

	g = graph_read_stdin() ;
	
	memset(stack, 1, sizeof(int) * 64);
	memset(result, 1, sizeof(int) * 64);
	int check = euler(g);

	tour(g, 1);
	result[top2] = stack[top];
		
	printf("path: ");
	
	for(int i=0; i<64; i++){
		if(result[i]<65){
			printf("%d ", result[i]);
		}
	}
	
	printf("\n");
	/* TODO: implement here */

	graph_free(g) ;
	return 0 ;
}
