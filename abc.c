#include <stdio.h>

int
main ()
{
	FILE * fp = fopen("ABC", "w") ;

	int i, j, n;

	for (i = 1 ; i <= 6 ; i++)
		for (j = 1 ; j <= 6 ; j++)
			for(n=0; n<=5; n++)
				fprintf(fp,"(declare-const p%d%d%d Bool)\n", i, j, n) ;

	// Q1
	fprintf(fp,"; Q1\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= 6; i++) {
		fprintf(fp,"(or ") ;
		for(j = 1; j <= 6; j++){
			fprintf(fp,"p%d%d%d ", i, j, 0);
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;
	
	// Q2	
	fprintf(fp,"; Q2\n") ;
	fprintf(fp,"(assert (and ") ;
	for (j = 1 ; j <= 6; j++) {
		fprintf(fp,"(or ") ;
		for(i = 1; i <= 6; i++){
			fprintf(fp,"p%d%d%d ", i, j, 0);
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q3	
	fprintf(fp,"; Q3\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= 6; i++) {
		fprintf(fp,"(and ") ;
		for(n = 1; n <= 5; n++){
			fprintf(fp, "(or ");
			for(j = 1; j<=6; j++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q4	
	fprintf(fp,"; Q4\n") ;
	fprintf(fp,"(assert (and ") ;
	for (j = 1 ; j <= 6; j++) {
		fprintf(fp,"(and ") ;
		for(n = 1; n <= 5; n++){
			fprintf(fp, "(or ");
			for(i = 1; i<=6; i++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q5	
	fprintf(fp,"; Q5\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= 6; i++) {
		fprintf(fp,"(and ") ;
		for(j = 1; j <= 6; j++){
			fprintf(fp, "(or ");
			for(n = 0; n<=5; n++){
				fprintf(fp,"p%d%d%d ", i, j, n);
			}
			fprintf(fp, ")");
		}
		fprintf(fp,")");
	}
	fprintf(fp,"))\n") ;

	// Q6	
	fprintf(fp,"; Q6\n") ;
	fprintf(fp,"(assert (and ") ;
	for (i = 1 ; i <= 6; i++) {
		fprintf(fp,"(and ") ;
		for(j = 1; j <= 6; j++){
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
	char buf[128] ;
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
