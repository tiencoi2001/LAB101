#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char reverse(char *str){
   if (*str){
       reverse(str+1);
       printf("%c", *str);
   }   
   return *str;
}

int main(){
	char s[10000];
	
	while(true){
		fflush(stdin);
		printf("Please enter any string: ");
		gets(s);
		
		if(strlen(s) == 0){ // if input empty string --> re-enter
			printf("String can't empty. Please enter again!\n");
			continue;
		}
				
		printf("Result: \n");
		reverse(s);
		printf("\n\nPress any key to continue\n");
		getch();
	}
	
	return 0;
}
