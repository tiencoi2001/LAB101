#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int inputIntger(){
	char s[] = "";
	while(true){
		bool flag = true;
		fflush(stdin);
		scanf("%s" , &s);
		int i;
		for(i = 0; i < strlen(s); i++){ // if constain character then flag = false to re-enter
			if(s[i] < '0' || s[i]>'9'){
				flag = false;
				break;
			}
		}
		
		if(flag){
			int a = atoi(s);
			return a;
		}else{
			printf("Must enter positive integer. Please enter again!\n");
		}	
	}
}


int main(){
	int a = 0;
	while(true){
		
		printf("Please enter number: "); // enter size of array
		a = inputIntger();
		
		if(a == 0){
			printf("Size of array must greater than 0. Please enter again!\n");
			continue;
		}
		
		printf("New array: \n"); // enter array
		int arr[a];
		int i;
		for(i = 0; i < a; i++){
			printf("[%d] ", i);
			arr[i] = inputIntger();
		}		
				
		printf("Find letters corresponding to the integer equivalent of letter:\n");
		for(i = 0; i < a; i++ ){ // if there is an ascii character corresponding to a-z or A-Z, print the corresponding character else print the entered number
			if((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122)){
				printf("[%d] %c\n", i, arr[i]);
			}else{
				printf("[%d] %d\n", i, arr[i]);
			}
		}
		
		printf("Press any key to continue");
		getch();
		printf("\n");
	}
}
