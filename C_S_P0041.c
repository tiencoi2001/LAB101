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

int main(){
	int n = inputSizeOfArray("Enter the size of an array\n");
	int a[n];
	int i;
	
	printf("Enter the elements of the array\n");
	for(i = 0; i <n ; i++ ){ // input element
		a[i] = inputInteger();
	}
	
	printf("Array elements:\n");
    for(i = 0; i < n; i++) // display array
        printf("%d ", a[i]);
    printf("\n");
    printf("\n");
    
    int max = a[0];
    for(i = 1; i < n; i++) // find max
        if(max < a[i])
            max = a[i];
    printf("Array maximum value:\n");
    printf("The max is %d\n", max);
    printf("\n");
    printf("\n");
    
    int check = 0;
    for(i = 0; i < n; i++)
        if(a[i] % 2 == 0){ // check even number
            check ++;
            if(check == 1)
                printf("Array even values:\n");
            printf("%d  ", a[i]);
        }
    if(check == 0)
        printf("The array does not contain any even number\n");
        
return 0;
}

