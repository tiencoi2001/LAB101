#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int inputInteger(){
	char s[10];
	while(true){
		bool flag = true;
		fflush(stdin); 
		scanf("%s", &s);
		int i;
		if(s[0] == '-'){
			for(i = 1; i < strlen(s); i++){ // if constain character then flag = false to re-enter
				if(s[i] < '0' || s[i] > '9'){
					flag = false;
					break;
				}
			}
		}else{
			for(i = 0; i < strlen(s); i++){ // if constain character then flag = false to re-enter
				if(s[i] < '0' || s[i] > '9'){
					flag = false;
					break;
				}
			}
		}
		
		if(flag){
			int a = atoi(s);
			return a;
		}else{
			printf("Must enter integer. Please enter again!\n");
		}	
	}
}

void menu(){
	printf("\n___MENU___\n");
	printf("1. Add a value\n");
	printf("2. Search a value\n");
	printf("3. Print out the array\n");
	printf("4. Print out values in a range of inputted min and max values, inclusively.\n");
	printf("5. Sort the array in ascending order\n");
	printf("Others- Quit\n");
	printf("=> Choose an option: ");
	
}

int inputSizeOfArray(char s[]){
	while(true){
			printf("%s", s);
		int n = inputInteger();
		if(n > 0 && n <= 100){
			return n;
		}else{
			printf("Size of array must positive number! Re-enter");
		}
	}
}


int main(){
	int i, j = 0;
	int n;
	int arr[100];
	
	while(true){
		menu();
		char option;
		fflush(stdin);
		scanf("%c", &option);
		switch(option){
			case '1':
				n = inputSizeOfArray("Size of array: ");
				printf("Enter array: \n");
				for(i = 0; i < n; i++){
					printf("a[%d]: ", i);
					arr[i] = inputInteger();
				}
				printf("\n");
				break;
			case '2':
				printf("Enter number to find index in array: "); 
				int number = inputInteger();
				bool flag = false; // use for check number constain in array?
				for(i = 0; i < n; i++){
					if(arr[i] == number){
						flag = true;
						printf("Number %d at position: %d ",number, i);
					}
				}
				
				if(!flag){
					printf("Not constain in array.");
				}
				printf("\n");
				break;
			case '3':
				printf("All the elements of array:\n");
				for(i = 0; i < n; i++){
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			case '4':
				printf("Enter min value: "); // enter max-min value
				int min = inputInteger();
				int max;
				while(true){
					printf("Enter max value: ");
					max = inputInteger();
					if(max > min){
						break;
					}else{
						printf("=>Max value must bigger than min value! Re-enter.\n");
					}
				}
				
				printf("Elements of array in range [%d, %d]: \n", min, max); // print elements in [min,max]
				for(i = 0; i < n; i++){
					if(arr[i] >= min && arr[i] <= max){
						printf("%d ", arr[i]);
					}
				}
				
				printf("\n");
				break;
			case '5':
			    for (i = 0 ; i < n - 1; i++){ // bubble sort
				    for (j = 0 ; j < n - i - 1; j++){
				      	if (arr[j] > arr[j+1]){ /* for decreasing order use '<' instead of '>' */				      
				        	int swap = arr[j];
				        	arr[j] = arr[j+1];
				        	arr[j+1] = swap;
				      	}
				    }
				}
				printf("___Sort successful__\n");
				printf("\n");
				break;
			default:
				return 0;
		}	
	}
}
