#include<stdio.h>
#include<conio.h>
#include<dirent.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void menu(){
	printf("1) Read file\n");
	printf("2) Copy files\n");
	printf("3) Merge two files\n");
	printf("4) List files in a directory\n");
	printf("5) Delete file\n");
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

void readFile(char fileName[50]){
    int c;
	FILE *file;
	file = fopen(fileName, "r");
	if (file) {
    	while ((c = getc(file)) != EOF)
        	putchar(c);
        printf("\n");
    	fclose(file);
	}	
}

void copyFile(){
   	char ch, sourceFile[50], targetFile[50];
   	FILE *source, *target;

	printf("Enter name of file to copy: ");
   	while(true){
		fflush(stdin);
		gets(sourceFile);
		if(strlen(sourceFile) == 0){
			printf("File name can't empty. Please enter again!!\n");
		}else{
			break;
		}
	}
 
   	source = fopen(sourceFile, "r");
	
	if(source == NULL){ // if source file does not exist --> exit
    	printf("Press any key to exit...\n");
      	exit(EXIT_FAILURE);
   	}
 
   	printf("Enter name of target file: ");
   	while(true){
		fflush(stdin);
		gets(targetFile);
		if(strlen(targetFile) == 0){
			printf("File name can't empty. Please enter again!!\n");
		}else{
			break;
		}
	}
 
   	target = fopen(targetFile, "w");
 
   	if(target == NULL){ // if can't open target file --> exit
    	fclose(source);
      	printf("Press any key to exit...\n");
      	exit(EXIT_FAILURE);
   	}
			   	
   	while((ch = fgetc(source)) != EOF)
      	fputc(ch, target);
 
   	printf("File copied successfully.\n");
 	
  	fclose(source);
   	fclose(target);
}

void mergeFile(){
	char ch, file1[50], file2[50], result[50];
	FILE *fp1, *fp2, *fResult;
   	
   	printf("Enter name of first file: ");
   	while(true){
		fflush(stdin);
		gets(file1);
		if(strlen(file1) == 0){
			printf("File name can't empty. Please enter again!!\n");
		}else{
			break;
		}
	}
   	
   	fp1 = fopen(file1, "r");
   	
   	if(fp1 == NULL){ // if first file does not exist --> exit
    	printf("Press any key to exit...\n");
      	exit(EXIT_FAILURE);
   	}
   	
   	printf("Enter name of second file: ");
   	while(true){
		fflush(stdin);
		gets(file2);
		if(strlen(file2) == 0){
			printf("File name can't empty. Please enter again!!\n");
		}else{
			break;
		}
	}
   	
   	fp2 = fopen(file2, "r");
   	
   	if(fp2 == NULL){ // if second file does not exist --> exit
    	printf("Press any key to exit...\n");
      	exit(EXIT_FAILURE);
   	}
   	
   	printf("Enter name of file to copy: ");
   	while(true){
		fflush(stdin);
		gets(result);
		if(strlen(result) == 0){
			printf("File name can't empty. Please enter again!!\n");
		}else{
			break;
		}
	}
   	
   	fResult = fopen(result, "w");
   	
   	if(fResult == NULL){ // if can't open result file --> exit
    	printf("Press any key to exit...\n");
      	exit(EXIT_FAILURE);
   	}
  
   	while ((ch = fgetc(fp1)) != EOF) // loop until EOF
      	fputc(ch, fResult);
  	
  	fprintf(fResult, "%s", "\n");
  	
   	while ((ch = fgetc(fp2)) != EOF) // loop until EOF
      	fputc(ch, fResult);
  
   	printf("Two files were merged into %s file successfully!!\n", result);
  
   	fclose(fp1);
   	fclose(fp2);
   	fclose(fResult);
}

void listFile(){
	DIR *d;
  	struct dirent *dir;
  	d = opendir(".");
  	if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}

void deleteFile(char fileName[50]){
	if (remove(fileName) == 0) {
        printf("%s file deleted successfully!!!\n", fileName);
    } else {
        printf("The file is not deleted.\n");
    }	
}

int main(){
	char fileName[50];
	
    while(true){
    	menu();
		printf("\nChoose an option: ");
		int option = inputInteger();
		
		switch(option){
			case 1: 
				fflush(stdin);
				printf("Enter the name of file you wish to see: ");
				while(true){
					fflush(stdin);
					gets(fileName);
					if(strlen(fileName) == 0){
						printf("File name can't empty. Please enter again!!\n");
					}else{
						break;
					}
				}
			    readFile(fileName);
				break;
			case 2:
				fflush(stdin);
				copyFile();
				break;
			case 3:
				fflush(stdin);
				mergeFile();
				break;
			case 4:
				listFile();
				break;
			case 5:
				fflush(stdin);
				printf("Enter the name of file you wish to delete: ");
				while(true){
					fflush(stdin);
					gets(fileName);
					if(strlen(fileName) == 0){
						printf("File name can't empty. Please enter again!!\n");
					}else{
						break;
					}
				}
				deleteFile(fileName);
				break;
			default:
				printf("=>You must choose from 1 to 5! Enter again.\n\n");
		}
	}
}

