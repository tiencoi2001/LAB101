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
		scanf("%s" , &s);
		int i;
		if(s[0] == '-' || s[0] == '+'){
			for(i = 1; i < strlen(s); i++){ // if constain character then flag = false to re-enter
				if(s[i] < '0' || s[i]>'9'){
					flag = false;
					break;
				}
			}
		}else{
			for(i = 0; i < strlen(s); i++){ // if constain character then flag = false to re-enter
				if(s[i] < '0' || s[i]>'9'){
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

int inputSizeOfArray(char s[]){
	while(true){
			printf("%s", s);
		int n = inputInteger();
		if(n>0 && n<=100){
			return n;
		}else{
			printf("Size of array must positive number! Re-enter");
		}
	}
}

bool checkEvenNumber(int a){
	if(a % 2 == 0){
		return true;
	}
	
	return false;
}

int main(){	
	printf("Sum Even Odd program\n");
	int n = inputSizeOfArray("Enter number of element: ");
	int arr[n];
	int i;
	for(i = 0; i <n ; i++ ){
		printf("Element %d = ", i+1);
		arr[i] = inputInteger();
	}
	
	long sumEven = 0, sumOdd = 0;
	
	for(i = 0; i<n; i++){
		if(checkEvenNumber(arr[i])){
			sumEven += arr[i];
		}else{
			sumOdd += arr[i];
		}
	}
	printf("Sum of Even = %d\n", sumEven);
	printf("Sum of Odd = %d", sumOdd);	
	return 0;
}
