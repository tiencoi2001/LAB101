#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	char str[50];
	char * p;
	
	while(true){
		fflush(stdin);
		printf("Please enter any string: ");
		gets(str);
		
		if(strlen(str) == 0){ // if input empty string --> re-enter
			printf("String can't empty. Please enter again!\n");
			continue;
		}
		
		p = strtok(str, " "); // Split the substring for the first time
		int max = strlen(p);
		
		char result[20];
		strcpy(result, p);
		while(p != NULL) { // If p not null --> continue
		    p = strtok(NULL, " \n");
		    if(p != NULL) {
		        if(strlen(p) > max){
		        	strcpy(result, p);
		        	max = strlen(p);
				}
		    }
		}
		printf("The longest substring: %s [%d]\n" , result, max);
		
		printf("Press any key to continue\n");
		getch();
		printf("\n");
	}
return 0;
}

