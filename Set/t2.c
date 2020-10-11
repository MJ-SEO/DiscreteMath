#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Bset.h"

int main(){
	int univ[4] = {5,28,9,2};

	intset *s = intset_alloc(univ, 4);
	intset_print(stderr, s) ; fprintf(stderr, "\n") ;	

	intset_add(s, 28);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	
	intset_add(s, 5);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}

	intset_add(s, 9);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}

	intset_add(s, 2);
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	
	intset_remove(s, 28) ;
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	
	intset_remove(s, 28) ;
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	
	intset_remove(s, 5) ;
	printf("size: %d\n",intset_size(s));	
	for(int i=0 ; i< 4; i++){
		printf("%d ", s->bitvect[i]);
	}
	return 0;
}
