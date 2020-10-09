#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intset.h"

intset *
intset_alloc ()
{	
	intset * s = (intset *) malloc(sizeof(intset)) ;
	s->n_elems = 0 ;
	s->elems = 0x0 ;
	return s ;
}

intset * 
intset_clone (intset * orig) 
{
	if (orig == 0x0)
		return 0x0 ;

	intset * s = intset_alloc() ;
	
	s->n_elems = orig->n_elems ;
	s->elems = 0x0 ;
	if (s->n_elems > 0) {
		s->elems = (int *) calloc(s->n_elems, sizeof(int)) ;
		memcpy(s->elems, orig->elems, s->n_elems * sizeof(int)) ;
	}
	return s ;
}

void
intset_print (FILE * fp, intset * s)
{
	fprintf(fp, "{") ;
	for (int i = 0 ; i < s->n_elems ; i++) {
		char * delim = (i > 0) ? ", " : "" ;
		fprintf(fp, "%s%d", delim, s->elems[i]) ;
	}
	fprintf(fp, "}") ;
}

void
intset_free (intset * s) 
{
	free(s->elems) ;
	free(s) ;
}

int
intset_size (intset * s) 
/*
 * returns the number of elements contained in s.
 */
{
	int n;
	n = s->n_elems;
	return n;
}

int
intset_add (intset * s, int e) 
/*
 * insert a new integer value e to s.
 * return 0 if succeeded. return 1 if it fails.
 * 
 * hint: use realloc. note that s->elems is NULL when it has no element.
 */
{
	for(int i=0; i < s->n_elems; i++){
		if(s->elems[i] == e){
			printf("[DEBUG] ADD %d,  %d는 중복입니다.\n",e,e);
			return 1;
		}
	}

	s->elems = (int *) realloc(s->elems, s->n_elems+1);
	s->elems[s->n_elems] = e;
	s->n_elems += 1;
	printf("[DEBUG] ADD %d\n", e);
	return 0;
}

int
intset_remove (intset * s, int e) 
/*
 * remomve e from s.
 * return 0 if succeeded. return 1 if failed.
 *
 * s->elems must be set to NULL if s->n_elems == 0.
 *
 * hint: use realloc.
 */
{	
	for(int i=0; i < s->n_elems; i++){
		if(s->elems[i] == e){
			printf("[DEBUG] remove %d\n", e);
			s->elems = (int *) realloc(s->elems, s->n_elems);
			s->elems[i] = s->elems[s->n_elems-1];
			s->n_elems -= 1;			
			if(s->n_elems == 0){
				s->elems = 0x0;
			}
			return 0;
		}
	}

	printf("[DEBUG] %d는 존재하지 않습니다.\n", e);	
	return 1;
}


int
intset_contains (intset * s, int e) 
/*
 * return 1 if e is contained in s. return 0 otherwise.
 */
{
	for(int i=0; i < s->n_elems; i++){
		if(s->elems[i] == e){
			printf("[DEBUG] %d is in set\n", e);
			return 1;
		}
	}
	
	printf("[DEBUG] %d is not in set\n", e);
	return 0;
}


int
intset_equals (intset *s1, intset *s2) 
/*
 * return 1 if two sets s1 and s2 are equivalent.
 * return 0 otherwise.
 */
{
	if(s1->n_elems != s2->n_elems){
		printf("두 set은 다름,(크기)\n");
		return 0;
	}

	int a=0, b=0;

	for(int i=0; i< s1->n_elems; i++){
		for(int j=0; j< s2->n_elems; j++){
			if(s1->elems[i] == s2->elems[j]){
				a++;
				break;
			}
		}
	}
	
	if(a == s1->n_elems && a == s2->n_elems){
		printf("두 set은 같음\n");
		return 1;
	}
	else{
		printf("두 set은 다름(구성)\n");
		return 0;
	}
}


intset *
intset_union (intset *s1, intset *s2) 
/*
 * return a new intset object that contains the result of
 * the union of s1 and s2.
 *
 * return NULL if the operation fails.
 */
{
	if(s1->n_elems == 0 && s2->n_elems == 0){
		return 0x0;
	}	

	intset *s3 = intset_alloc(); 
	for(int i=0; i< s1->n_elems; i++){
		intset_add(s3, s1->elems[i]);
	}
	for(int i=0; i< s2->n_elems; i++){
		intset_add(s3, s2->elems[i]);
	}
	return s3;
}


intset *
intset_intersection (intset *s1, intset *s2) 
/*
 * return a new intset object that contains the result of
 * the intersection of s1 and s2.
 *
 * return NULL if the operation fails.
 */
{

	intset *s3 = intset_alloc(); 
	intset *s4 = intset_alloc();	
	for(int i=0; i< s1->n_elems; i++){
		intset_add(s3, s1->elems[i]);
	}
	for(int i=0; i< s2->n_elems; i++){
		if(intset_add(s3, s2->elems[i])==1){
			intset_add(s4, s2->elems[i]);
		}
	}
	return s4;	
}


intset *
intset_difference (intset *s1, intset *s2) 
/*
 * return a new intset object that contains the result of
 * the set difference of s1 and s2 (i.e., s1 \ s2).
 *
 * return NULL if the operation fails.
 */
{
	intset *s3 = intset_alloc();	
	intset *s4 = intset_alloc();
	for(int i=0; i< s1->n_elems; i++){
		intset_add(s3, s1->elems[i]);
		intset_add(s4, s1->elems[i]);
	}
	for(int i=0; i< s2->n_elems; i++){
		if(intset_add(s3, s2->elems[i])==1){
			intset_remove(s4, s2->elems[i]);
		}
	}
	return s4;
}


intset **
intset_subsets (intset * s, size_t k , size_t * n_subsets) 
/*
 * return a new intset array that contains all distinct subsets
 * of s having k elements. The size of the result array must be
 * given to n_subsets.
 * 
 * this operation must be implemented with a recursion.
 *
 * return NULL if the operation fails.
 */
{
	/* TODO*/
}


intset ** 
intset_powerset (intset * s, size_t * n_subsets) 
/*
 * return a new intset array that contains all distinct subsets
 * of s having. The size of the result array must be given to
 * n_subsets.
 * 
 * this operation must be implemented with a recursion.
 *
 * return NULL if the operation fails.
*/
{
	/* TODO*/
}
