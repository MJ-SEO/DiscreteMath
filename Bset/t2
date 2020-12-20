#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Bset.h"

int main(){
	int univ[4] = {5,28,9,2};

	intset *s = intset_alloc(univ, 4);	
	intset *s2 = intset_alloc(univ, 4);
	intset *s3 = 0x0;

	intset_print(stderr, s) ; fprintf(stderr, "\n") ;	

	intset_add(s, 28);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");
	
	intset_add(s, 5);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");

	intset_add(s, 9);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");

	intset_add(s, 2);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");
	
	intset_remove(s, 28) ;
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");
	
	intset_remove(s, 9) ;
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");
	
	intset_remove(s, 28) ;
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	printf("\n");
	
	intset_contains(s, 28);
	intset_contains(s, 9);
	
	intset_add(s2, 28);
	printf("size: %d\n",intset_size(s2));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s2->bitvect[i]);
	}
	printf("\n");
	
	intset_add(s2, 5);
	printf("size: %d\n",intset_size(s2));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s2->bitvect[i]);
	}
	printf("\n");
	
	int e;
	e = intset_equals(s,s2);
	printf("equal: %d\n", e);

	s3 = intset_union(s,s2);	
	printf("size: %d\n",intset_size(s3));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s3->bitvect[i]);
	}
	printf("\n");

	s3 = intset_intersection(s,s2);	
	printf("size: %d\n",intset_size(s3));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s3->bitvect[i]);
	}
	printf("\n");

	s3 = intset_difference(s,s2);	
	printf("size: %d\n",intset_size(s3));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s3->bitvect[i]);
	}
	printf("\n");


	return 0;
}
