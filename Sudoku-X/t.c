#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void strlwr(char *s1)
{
  while(*s1!=' ')
  {
        if(*s1>=65 && *s1<=90){
           *s1+=32;
           s1++;
        }
        else{
           *s1==126;
           s1++;
        }
  }
}

void token(char *s1){;
int n=0;
while(*s1!='\0'){
        if(*s1>=97 && *s1<=122){
            s1++;
        }
        else if(*s1>=65 && *s1<=90){
           *s1+=32;
            s1++;
        }
        else{
 	   strcpy(s1, s1+1);
	}
//	n++;
	//printf("[DEBUG] n:%d\n", n);
  }
}

int main(){
	char a[10] = "heHlLo Mj";
	char b[30] = "MJ@se#1--o... 12Flo2!!";
	char c[20] = "@MJMJMJ2 mtb..!";
	char d[30] = "@#TWOCLSL..!";
	printf("first: %s\n", a);
	token(a);
	printf("second: %s\n", a);

	printf("str: %s\n", b); 
	token(b);
	printf("T_str1: %s\n", b);
	
	printf("str2: %s\n", c); 
	token(c);
	printf("T_str2: %s\n", c);
	
	printf("str3: %s\n", d); 
	token(d);
	printf("T_str3: %s\n", d);

/*	for(int i=0; i<strlen(b); i++){		
		if(isalnum(b[i])){
			printf("[DEBUG] str[%d] 숫자나 문자임\n", i);
		}
	}
*/

	return 0;
}
