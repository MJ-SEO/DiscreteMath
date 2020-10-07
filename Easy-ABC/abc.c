#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sort(int * arr, int size){
    int i, j;
    int key;

    for(i=1; i<size ; i++){
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
	FILE * fp = fopen("ABC", "w") ;

	int i, j, n;

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

	for (i = 1 ; i <= size ; i++)
		for (j = 1 ; j <= size ; j++)
			for(n=0; n<=5; n++)
				fprintf(fp,"(declare-const p%d%d%d Bool)\n", i, j, n) ;
	

	// Q1 - 모든 row에는 0(빈칸)이 들어가야 한다.
	fprintf(fp,"; Q1\n") ;
	fprintf(fp,"(assert (and ") ;
	for(int k=0; k<size-5; k++){
		fprintf(fp, "(and ");
	for (i = 1 ; i <= size; i++) {
		fprintf(fp,"(or ") ;
		for(j = 1; j <= size; j++){
			fprintf(fp,"p%d%d%d ", i, j, 0);
		}
		fprintf(fp,")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;
	
	// Q2 - 모든 column에는 0(빈칸이 들어가야 한다.
	fprintf(fp,"; Q2\n") ;
	fprintf(fp,"(assert (and ") ;
	for(int k=0; k<size-5; k++){
		fprintf(fp, "(and ");
	for (j = 1 ; j <= size; j++) {
		fprintf(fp,"(or ") ;
		for(i = 1; i <= size; i++){
			fprintf(fp,"p%d%d%d ", i, j, 0);
		}
		fprintf(fp,")");
	}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q3 - 모든 row에는 A~E가 있어야 한다.	
	fprintf(fp,"; Q3\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= size; i++) {
		fprintf(fp,"(and ") ;
		for(n = 1; n <= 5; n++){
			fprintf(fp, "(or ");
			for(j = 1; j<=size; j++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q4 - 모든 columne에는 A~E가 있어야 한다.
	fprintf(fp,"; Q4\n") ;
	fprintf(fp,"(assert (and ") ;
	for (j = 1 ; j <= size; j++) {
		fprintf(fp,"(and ") ;
		for(n = 1; n <= 5; n++){
			fprintf(fp, "(or ");
			for(i = 1; i<=size; i++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q5 - 모든 cell에 값이 할당되어야 한다.
	fprintf(fp,"; Q5\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= size; i++) {
		fprintf(fp,"(and ") ;
		for(j = 1; j <= size; j++){
			fprintf(fp, "(or ");
			for(n = 0; n<=5; n++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q6 - 모든 셀은 오직 하나의 값만 할당 되어야 한다.
	fprintf(fp,"; Q6\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= size; i++) {
		fprintf(fp,"(and ") ;
		for(j = 1; j <= size; j++){
			fprintf(fp, "(and ");
			for(n = 0; n<=4; n++){
				fprintf(fp,"(and ");
				for(int m=n+1; m<=5; m++){
					fprintf(fp,"(not (and p%d%d%d p%d%d%d))", i, j, n, i, j, m);
				}
				fprintf(fp,")");
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	fprintf(fp,"(check-sat)\n(get-model)\n") ;

	fclose(fp) ;

	FILE * fin = popen("z3 ABC", "r") ;
	fscanf(fin, "%s %s", buf, buf) ;
	char p[10];
	int store[size*size];
	int number;
	int result[size][size];
	int k=0;	

	while (!feof(fin)) {
		fscanf(fin, "%s", buf) ;
	
		fscanf(fin, "%c %c", p,p);
		
		fscanf(fin, "%s", buf) ;
		number = atoi(buf);
		
		fscanf(fin, "%s", buf) ; 
		
		fscanf(fin, "%s", buf) ; 
		
		fscanf(fin, "%s", buf) ; 
			if(strchr(buf,'t')!=NULL){
				store[k] = number;
				//printf("DEBUG: number:%d, store[k]:%d\n", number, store[k]);
				k++;
			}
	}

	int nn=0;
	sort(store, size*size);

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			if(store[nn]%10 == 0){
				printf("  ");
				nn++;
			}
			else{
				printf("%c ", store[nn]%10+64);
				nn++;
			}
		}
		printf("\n");
	}
/*
	for(i=0; i<size*size; i++){
		printf("%d\n", store[i]);
	}
*/
	fclose(fin) ;

}
