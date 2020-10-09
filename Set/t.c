#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

#include "intset.h"

int main(){
	intset *s = intset_alloc();

	int n;
	n = intset_size(s);
//	printf("memory size of s: %d\n", _msize(s));	
	intset_add(s, 2);
	intset_add(s, 4);
	intset_add(s, 6);
	intset_add(s, 8);

	intset_add(s, 6);

	intset_remove(s, 5);
	
	intset_remove(s, 4);

//	intset_contains(s, 4);
//	intset_contains(s, 6);

	intset_print(stderr, s); fprintf(stderr, "\n");

	intset *s2 = intset_alloc();

	intset_add(s2, 5);
	intset_add(s2, 2);
	intset_add(s2, 8);
	int e;
	intset_print(stderr, s2); fprintf(stderr, "\n");
 	
	e = intset_equals(s, s2);

	intset *s3 = 0x0;		
	s3 = intset_union(s, s2);
	intset_print(stderr, s3); fprintf(stderr, "\n");

	s3 = intset_intersection(s, s2);	
	intset_print(stderr, s3); fprintf(stderr, "\n");

	s3 = intset_difference(s, s2);	
	intset_print(stderr, s3); fprintf(stderr, "\n");
	return 0;
}
