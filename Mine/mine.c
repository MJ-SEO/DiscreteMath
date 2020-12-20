#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void sort(int * arr, int size){
    int i, j;
    int key;
 
    for(i=1; i<size*size; i++){
        key = arr[i];
        
        for(j=i-1; j>=0; j--){
        
            if(arr[j] > key){      
                arr[j+1] = arr[j];  
            }else{                  
                break;
            }
        }
        arr[j+1] = key;        
    }
}


int
main ()
{
	FILE * fp = fopen("minesweeper", "w") ;

	int i, j, n;
	int size;
	scanf("%d", &size);
	char buf[128];
	scanf("%c", buf);
	

	for (i = 1 ; i <= size ; i++){
		for (j = 1 ; j <= size ; j++){
			for(n=0; n<=9; n++){
				fprintf(fp,"(declare-const p%d%d%d Bool)\n", i, j, n) ;
			}
		}
	}

	char map[size][size];

	for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
				scanf("%c ", &map[i][j]);	
		}
        }
/*       	
	for(int i=0; i<10; i++){
                for(int j=0; j<10; j++){
				printf("%c ", map[i][j]);	
		}
		printf("\n");
        }
*/

	// Q1 -  값 할당
	fprintf(fp,"; Q1\n") ;
	fprintf(fp,"(assert (and ") ;
	for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                        if(isdigit(map[i][j])){
                               fprintf(fp,"(and p%d%d%d)", i+1,j+1, map[i][j]-48);
//			       printf("[DEBUG] p%d%d%d)\n", i+1, j+1, map[i][j]-48);
                        }
                }
        }
	fprintf(fp,"))\n") ;

	// Q2 - 모든 셀에 값이 할당되어야 한다.
	fprintf(fp,"; Q2\n") ;
		fprintf(fp,"(assert (and ") ;
		for (i = 1 ; i <= size; i++) {
			fprintf(fp,"(and ") ;
			for(j = 1; j <= size; j++){
				fprintf(fp, "(or ");
				for(n = 0; n<=9; n++){
					fprintf(fp,"p%d%d%d ", i, j, n);
				}
				fprintf(fp, ")");
			}
			fprintf(fp,")");
		}
	fprintf(fp,"))\n") ;

	// Q3 - 모든 셀은 오직 하나의 값만 할당 되어야 한다.
	fprintf(fp,"; Q3\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= size; i++) {
		fprintf(fp,"(and ") ;
		for(j = 1; j <= size; j++){
			fprintf(fp, "(and ");
			for(n = 0; n<=8; n++){
				fprintf(fp,"(and ");
				for(int m=n+1; m<=9; m++){
					fprintf(fp,"(not (and p%d%d%d p%d%d%d))", i, j, n, i, j, m);
				}
				fprintf(fp,")");
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q4 - Q1에서 값을 할당받지 않은 셀은 0이거나 9이다.
	fprintf(fp,"; Q4\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 0 ; i < size; i++) {
		for(j = 0; j < size; j++){
			if(!isdigit(map[i][j])){	
			//	fprintf(fp,"(or p%d%d%d p%d%d%d)", i+1,j+1,0, i+1,j+1,9);
				fprintf(fp,"(or p%d%d%d)", i+1,j+1,0);
			}
		}
	}
	fprintf(fp,"))\n") ;

	// Q5 - Q1에서 N의값을 할당받은 셀의 주위에는 N개의 지뢰가 있어야 한다.
	fprintf(fp,"; Q5\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 0 ; i < size; i++) {
		for(j = 0; j < size; j++){
			if(isdigit(map[i][j])){
				for(int f=0; f<map[i][j]-48; f++){	
					if(i==0 && j==0){
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d )",i+2,j+1,9, i+1,j+2,9, i+2, j+2,9);
					//	map[i+1][j]
					//	map[i][j+1]
					//	map[i+1][j+1] 
					}
					else if(i==0 && j==size-1){	
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d )",i+1,j,9, i+2,j,9, i+2,j+1,9);
					}
					else if(i==size-1 && j==0){
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d )",i,j+1,9, i,j+2,9, i+1,j+2,9);
					}
					else if(i==size-1 && j==size-1){
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d )",i+1,j,9, i,j+1,9, i, j ,9);
					} 	
					else if(i==0){	
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d)", i+1,j,9, i+2,j,9, i+2,j+1,9, i+2,j+2,9, i+1,j+2,9);
					} 
					else if(i==size-1){
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d)", i+1,j,9, i,j,9, i,j+1,9, i,j+2,9, i+1,j+2,9);
					} 
					else if(j==0){
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d)", i,j+1,9, i,j+2,9, i+1,j+2,9, i+2,j+2,9, i+2,j+1,9);
					} 
					else if(j==size-1){
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d)", i,j+1,9, i,j,9, i+1,j,9, i+2,j,9, i+2,j+1,9);
					} 
					else{
						fprintf(fp, "(or p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d p%d%d%d)",i,j,9, i,j+1,9, i,j+2,9, i+1,j+2,9, i+2,j+2,9, i+2,j+1,9, i+2,j,9, i+1,j,9);
					}
				}
			}
		}
	}
	fprintf(fp,"))\n") ;
	
	fprintf(fp,"(check-sat)\n(get-model)\n") ;
	fclose(fp) ;

	FILE * fin = popen("z3 minesweeper", "r") ;

	char num[128] ;
	char p[10];
	
	fscanf(fin, "%s %s", buf, buf) ;

 	int store[size*size];
	int number;
	int result[size][size];
	int k=0;
	
	while (!feof(fin)) {
		fscanf(fin, "%s", buf) ; 

		fscanf(fin, "%c %c", p, p);
			
		fscanf(fin, "%s", num) ; 
		number = atoi(num);
		
		fscanf(fin, "%s", buf) ; 
		
		fscanf(fin, "%s", buf) ; 
		
		fscanf(fin, "%s", buf) ;	
			if(strchr(buf,'t')!=NULL){
				store[k] = number;
				//printf("DEBUG: number:%d, store[k]:%d\n", number, store[k]);
				k++;
		}		 
	}

	sort(store, size);
	int nn=0;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("%d ", store[nn]%10);
			nn++;
		}
		printf("\n");
	}
	
	fclose(fin) ;


}
