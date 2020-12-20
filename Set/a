#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	unsigned char *bit;
	bit = (unsigned char *) malloc(1);
	memset(bit, 5, 1);
	
 	for(int i=0 ; i< 30; i++){
                printf("%d ", bit[i]);
        }
	
        printf("\n----------------\n");
	
	int a=9;
	int b=3;

	printf("a: %d\n", a);	
	printf("b: %d\n", b);
	printf("a<<3: %d\n", a<<3);	
	printf("b<<3: %d\n", b<<3);
	printf("a>>3: %d\n", a>>3);	
	printf("b>>3: %d\n", b>>3);
	printf("a&b: %d\n", a&b);	
	printf("a|b: %d\n", a|b);

        printf("\n----------------\n");
	
	unsigned char bit1[4] = {1, 0, 1, 0};
	unsigned char bit2[4] = {0, 1, 0, 0};
	unsigned char *bit3;

	for(int i=0; i<4; i++){
		printf("bit1: ");
		printf("%d ", bit1[i]);
	}
	printf("\n");

	for(int i=0; i<4; i++){
		printf("bit2: ");
		printf("%d ", bit2[i]);
	}
	printf("\n");
	
	for(int i=0; i<4; i++){
		printf("bit3: ");
		printf("%d ", bit1[i] | bit2[i]);
	}
	
	return 0; 
}
