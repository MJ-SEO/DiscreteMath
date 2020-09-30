#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void sort(int * arr){
    int i, j;
    int key;
 
    for(i=1; i<81 ; i++){
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
	FILE * fp = fopen("sudoku", "w") ;

	int i, j, n;

	for (i = 1 ; i <= 9 ; i++)
		for (j = 1 ; j <= 9 ; j++)
			for(n=1; n<=9; n++)
				fprintf(fp,"(declare-const p%d%d%d Bool)\n", i, j, n) ;

	char Q3[9][9];

	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
				scanf("%c ", &Q3[i][j]);	
		}
        }
       	
	for(i=0; i<9; i++){
		for(j=0; j<8; j++){
			for(int k=j+1; k<9; k++){
				if(Q3[i][j]>=48 && Q3[i][j]<=57){
					if(Q3[i][j]==Q3[i][k]){
						printf("Invalid (row)\n");
						return 0;
					}
				}
			}		
		}
	}
/*
	for(i=0; i<9; i++){
		for(j=0; j<8; j++){
			for(int h=j+1; h<9; h++){
				if(Q3[i][j]>=48 && Q3[i][j]<=57){
					if(Q3[j][i]==Q3[h][i]){
						printf("Invalid (col)\n");
						return 0;
					}
				}
			}		
		}
	}
	
	
	for(i=0; i<9; i++){
		for(j=0; j<8; j++){
			for(int k=j+1; k<9; k++){
				if(Q3[i][j]>=48 && Q3[i][j]<=57){
					if(Q3[j][i]==Q3[k][i]){
						printf("Invalid (dia)\n");
						return 0;
					}
				}
			}		
		}
	}


	for(i=0; i<9; i++){
		for(j=0; j<8; j++){
			for(int k=j+1; k<9; k++){
				if(Q3[i][j]>=48 && Q3[i][j]<=57){
					if(Q3[j][i]==Q3[k][i]){
						printf("Invalid (sub)\n");
						return 0;
					}
				}
			}		
		}
	}
*/
	// Q1
	fprintf(fp,"; Q1\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= 9; i++) {
		fprintf(fp,"(and ") ;
		for (n = 1 ; n <= 9 ; n++){ 
			fprintf(fp,"(or ") ;
			for(j = 1; j <= 9; j++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp,")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;
	
	//Q2
	fprintf(fp,"; Q2\n") ;
	fprintf(fp,"(assert (and ") ;
	for (j = 1 ; j <= 9; j++) {
		fprintf(fp,"(and ") ;
		for (n = 1 ; n <= 9 ; n++){ 
			fprintf(fp,"(or ") ;
			for(i = 1; i <= 9; i++){
				fprintf(fp,"p%d%d%d ", i, j, n);			}
			fprintf(fp,")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	//Q3
	int v=0;
	fprintf(fp,"; Q3\n") ;
	fprintf(fp,"(assert (and ") ;
	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                        if(isdigit(Q3[i][j])){
                               fprintf(fp,"(and p%d%d%d)", i+1,j+1,Q3[i][j]-48);
			       v++;
			       // printf("[DEBUG] p%d%d%d)", i+1, j+1, Q3[i][j]-48);
                        }
                }
        }
	fprintf(fp,"))\n") ;

	if(v<=16){
		printf("Invalid\n");
		return 0;
	}

	
	//Q4
	fprintf(fp,"; Q4\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= 9; i++) {
		fprintf(fp,"(and ") ;
		for (j = 1 ; j <= 9 ; j++){ 
			fprintf(fp,"(or ") ;
			for(n = 1; n <= 9; n++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp,")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;
	//Q5	
	
	fprintf(fp,"; Q5\n") ;
	fprintf(fp,"(assert ") ;
	fprintf(fp,"(and ") ;
	for (i = 1 ; i <= 9 ; i++) {
		fprintf(fp,"(and ") ;
		for (j = 1 ; j <= 9 ; j++) {
			fprintf(fp,"(and ") ;
			for (n = 1 ; n <= 8; n++) {
				fprintf(fp, "(and ");
				for(int m = n+1; m<=9; m++){
					fprintf(fp, "(not (and p%d%d%d p%d%d%d))", i, j, n, i, j, m);		
				}
				fprintf(fp,") ");
			}
			fprintf(fp,") ") ;
		}
		fprintf(fp,") ") ;
	}
	fprintf(fp,"))\n") ;


	//Q6
	fprintf(fp,"; Q6\n") ;
	fprintf(fp,"(assert (and ") ;
	for (int r = 0 ; r <= 2; r++) {
		fprintf(fp,"(and ") ;
		for (int s = 0 ; s <= 2 ; s++){ 
			fprintf(fp,"(and ") ;
			for(n = 1; n <= 9; n++){
				fprintf(fp, "(or ");
					for(i = 1; i<=3; i++){
						fprintf(fp, "(or ");
						for(j = 1; j<=3; j++){
							fprintf(fp, "p%d%d%d ", 3*r+i, 3*s+j, n);
						}	
						fprintf(fp,")");
					}
					fprintf(fp,")");
				}
				fprintf(fp,")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;
	
	//Q7
	fprintf(fp,"; Q7\n") ;
	fprintf(fp,"(assert (and ") ;
	for (n = 1 ; n <= 9; n++) {
		fprintf(fp,"(or ") ;
		for (i = 1 ; i <= 9 ; i++){ 	
			fprintf(fp,"p%d%d%d ", i, i, n);
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n");
	
	//Q8
	fprintf(fp,"; Q8\n") ;
	fprintf(fp,"(assert (and ") ;
	for (n = 1 ; n <= 9; n++) {
		fprintf(fp,"(or ") ;
		for (i = 1 ; i <= 9 ; i++){ 	
			fprintf(fp,"p%d%d%d ", i, 10-i, n);
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n");
		
	fprintf(fp,"(check-sat)\n(get-model)\n") ;

	fclose(fp) ;

	FILE * fin = popen("z3 sudoku", "r") ;

	char buf[128] ;
	char num[128] ;
	char p[10];
	
	fscanf(fin, "%s %s", buf, buf) ;

 	int store[81];
	int number;
	int result[9][9];
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
				k++;
		}		 
	}

	sort(store);
	int nn=0;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			printf("%d ", store[nn]%10);
			nn++;
		}
		printf("\n");
	}
	
	fclose(fin) ;


}
