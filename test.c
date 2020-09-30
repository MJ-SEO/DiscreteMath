#include <stdio.h>
#include <ctype.h>

int main(){
	int size;
	scanf("%d", &size);
	char buf[128];
	char con[size][size];	
	scanf("%c", buf);	

	for(int i=0; i<4; i++){
                for(int j=0; j<size; j++){
                        scanf("%c ", &con[i][j]);
                }
        }
	
	for(int i=0; i<4; i++){
                for(int j=0; j<size; j++){
                        printf("%c ", con[i][j]);
                }
		printf("\n");
        }
/*
	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                        if(isdigit(Q3[i][j])){
				printf("p%d%d%d", i+1,j+1,Q3[i][j]-48);
			}
                }
		printf("\n");
        }
*/
	return 0;
}
