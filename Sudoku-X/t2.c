#include <stdio.h>

int main(){
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int *p_arr;
	p_arr = arr;

	printf("[DEBUG] arr[0]: %d\n", arr[0]);	
	printf("[DEBUG] pointer arr[0]: %p\n", arr);

	printf("[DEBUG] p_arr *: %d\n", *p_arr);
	printf("[DEBUG] pointer p_arr: %p\n", p_arr);
	printf("[DEBUG] p_arr &: %p\n", &p_arr);

	p_arr++;	
	printf("[DEBUG] p_arr ++: %d\n", *p_arr);
	p_arr++;
	printf("[DEBUG] p_arr ++2: %d\n", *p_arr);
	p_arr--;
	printf("[DEBUG] p_arr --: %d\n", *p_arr);
	return 0;
}
