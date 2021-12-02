#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int inputInteger(int max){
	char s[10];
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
			if(a > max){
				printf("Index must smaller than %d. Please enter again!\n", max);
				continue;
			}
			return a;
		}else{
			printf("Must enter integer. Please enter again!\n");
		}	
	}
}

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int main(){
	printf ("Please enter size of array: ");
	int a = inputInteger(100);
	
	int arr[a];
	int i;
	for (i = 0; i < a; i++){
		arr[i] = GetRandom(0, 100); // generate array
	}
	
	printf("\nThe original array:\n");
	for (i = 0; i < a; i++){
		printf("%d\t", arr[i]);
	}
	
	printf("\n\nSwap two elements:\n");
	int index1, index2;
	index1 = inputInteger(a);
	index2 = inputInteger(a);
	
	arr[index1-1] = arr[index1-1] + arr[index2-1]; // a = a+b
	arr[index2-1] = arr[index1-1] - arr[index2-1]; // b = a-b
	arr[index1-1] = arr[index1-1] - arr[index2-1]; // a = a-b
	
	printf("\nArray after swapping:\n"); // print array after swap
	for (i = 0; i < a; i++){
		printf("%d\t", arr[i]);
	}
	
}

