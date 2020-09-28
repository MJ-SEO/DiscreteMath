#include <stdio.h>

int
main ()
{
	FILE * fp = fopen("sudoku", "w") ;

	int i, j, n;

	for (i = 1 ; i <= 9 ; i++)
		for (j = 1 ; j <= 9 ; j++)
			for(n=1; n<=9; n++)
				fprintf(fp,"(declare-const p%d%d%d Bool)\n", i, j, n) ;

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
	fprintf(fp,"; Q3\n") ;
	fprintf(fp,"(assert (and ") ;
	fprintf(fp,"(and p123)(and p148)(and p154)(and p249)(and p335)(and p412)(and p425)(and p467)(and p474)(and p488)(and p531)(and p583)(and p627)(and p633)(and p691)(and p724)(and p838)(and p846)(and p879)(and p919) ");
	fprintf(fp,"))\n") ;
	
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
	char buf[256] ;
	fscanf(fin, "%s %s", buf, buf) ;
	while (!feof(fin)) {
		fscanf(fin, "%s", buf) ; printf("%s ", buf) ;
		fscanf(fin, "%s", buf) ; printf("%s ", buf) ;
		fscanf(fin, "%s", buf) ; printf("%s ", buf) ;
		fscanf(fin, "%s", buf) ; printf("%s ", buf) ;
		fscanf(fin, "%s", buf) ; printf("%s\n", buf) ;
	}
	pclose(fin) ;

}
