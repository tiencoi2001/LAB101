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
		if(s[0] == '-'){
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

int inputSizeOfMatrix(char s[]){
	while(true){
			printf("%s", s);
		int n = inputInteger();
		if(n>0){
			return n;
		}else{
			printf("Size of matrix must positive number! Re-enter");
		}
	}
}

int main(){
	// enter matrix 1
	int row1 = inputSizeOfMatrix("Please enter row of matrix 1: ");
	int col1 = inputSizeOfMatrix("Please enter column of matrix 1: ");
	
	int matrix1[row1][col1];
	int i, j;
	
	for(i = 0; i < row1; i++){
		for(j = 0; j < col1; j++){
			printf("Element[%d][%d] = ", i+1,j+1); 
			matrix1[i][j] = inputInteger();
		}
	}
	
	// enter matrix 2
	int row2 = inputSizeOfMatrix("Please enter row of matrix 2: ");
	int col2 = inputSizeOfMatrix("Please enter column of matrix 2: ");
	
	int matrix2[row2][col2];
	
	for(i = 0; i < row2; i++){
		for(j = 0; j < col2; j++){
			printf("Element[%d][%d] = ", i+1,j+1); 
			matrix2[i][j] = inputInteger();
		}
	}
	
	// add two matrixes
	int matrixResult[row1][col1];
	if(row1 == row2 && col1 == col2){
		for(i = 0; i < row2; i++){
			for(j = 0; j < col2; j++){
				matrixResult[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
		
		//  [1] [2]     [3] [4] 
 		// [1 + 3] [2 + 4]
 		
		// [1]     [1] [2]
		// can't add matrix
		
		printf("Result:\n"); // print matrix result = matrix1 + matrix 2
		for(i = 0; i < row2; i++){
			for(j = 0; j < col2; j++){
				printf("[%d]",matrixResult[i][j]); 
			}
			printf("\n");
		}
	}else{
		printf("\n=>Two matrixes don't the same size!");
	}	
	
	return 0;
}
