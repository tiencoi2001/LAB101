#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void menu(){
	printf("1. Output first primes of the inputted number\n");
	printf("2. Check a Fibonacci number\n");
	printf("3. Sum of digits in a positive natural number");
}

int inputInteger(){
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
			return a;
		}else{
			printf("Must enter positive integer. Please enter again!\n");
		}	
	}
}

bool checkPrime(int a){ // check prime
	int i;
	for (i = 2; i <= a/2; i++){
		if(a % i == 0){
			return false;
		}
	}
	
	return true;
}

void firstPrime(){ // option 1
	int n;
	while (true){
		printf("Number of primes: ");
		n = inputInteger();
		if(n>0 && n<=50){
			break;
		}
	}
	int count = 0;
	int i = 2;
	while (count < n){
		if(checkPrime(i)){
			printf("%d ", i);
			count++;
		}
		i++;
	}
	printf("\n");
}

bool fibonacciNumber(){ // option 2
	int c;
	while (true){
		printf("Number tested: ");
		c = inputInteger();
		if(c>0 && c<=1000){
			break;
		}
	}
	int a = 0, b = 1;
	if (c == a || c == b){
		return true;
	}else{
//		0 1 1 2 3 5 8 13 ...
		int sum = a + b;
		while (true){
			if (sum == c || sum > c){
				break;
			}
			sum += b;
			b = sum-b;	
		}
		
		if (sum == c){
			return true;
		}else {
			return false;
		}
	}	
}

long sumDigtis(){ // option 3
	char s[100];
	printf("Enter an integer: "); 
	long a = inputInteger();
	sprintf(s, "%ld", a);
	int i;
	long sum = 0;
	for(i = 0; i < strlen(s); i++){
		sum += s[i] - '0';
	}
	return sum;
	
}


int main(){
	while(true){
		menu();
		printf("\nChoose an option: ");
		int option = inputInteger();
		switch(option){
			case 1:
				firstPrime();
				break;
			case 2:
				if(fibonacciNumber()){
					printf("It's a Fibonacci number.\n\n");
				}else {
					printf("It's not a Fibonacci number.\n\n");
				}
				break;
			case 3:
				printf("Sum of it's digits: %ld\n\n", sumDigtis());
				break;
			default:
				printf("=>You must choose from 1 to 3! Enter again.\n\n");
		}
	}
	
}
