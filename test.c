#include <stdio.h>
#include <ctype.h>

int main(){
	char Q3[9][9];	

	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                        scanf("%c ", &Q3[i][j]);
                }
        }
	
	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                        printf("%c", Q3[i][j]);
                }
		printf("\n");
        }

	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                        if(isdigit(Q3[i][j])){
				printf("p%d%d%d", i+1,j+1,Q3[i][j]-48);
			}
                }
		printf("\n");
        }
	return 0;
}
