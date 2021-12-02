#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void menu(){
	printf("1) Play the slot machine.\n");
	printf("2) Save game.\n");
	printf("3) Cash out.\n");
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

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

double play(double money){
	srand((int)time(0));
	int a, b, c;
	a = random(0, 9);
	b = random(0, 9);
	c = random(0, 9);
	
	printf("The slot machine shows %d%d%d\n", a, b, c);
	if(a == b && a == c){
		printf("You win the big price, $10.00!\n");
		money = money - 0.25 + 10;
	}else if(a == b || a == c || c == b){
		printf("You win 50 cents!\n");
		money = money - 0.25 + 0.5;
	}else{
		printf("Sorry you don't win anything.\n");
		money = money - 0.25;
	}
	return money;
}

void save(double money){
	FILE *fSave = fopen("save.txt", "w");
	fprintf(fSave, "%.2lf", money);
	fclose(fSave);
}

int main(){
	double money = 0;
	
	FILE *fMoney = fopen("save.txt", "r");
	
	if(fMoney == NULL){
		printf("Welcome come to play Slot Machine\n");
		money = 10;
	}else{
		fscanf(fMoney, "%lf", &money);
		if(money == 0){
			money = 10;
		}
	}
	
	while(true){
		if(money <= 0){
			save(0);
			printf("You lose\n");
			return 0;
		}
		printf("You have $%.2lf\n", money);
		printf("\nChoose one of the following menu option: \n");
		menu();
		int option = inputInteger();
		switch(option){
			case 1:{
				money = play(money);
				break;
			}
			case 2:{
				printf("Your money had saved!\n");
				save(money);
				break;
			}
			case 3:
				save(0);
			    printf("Thanks for playing. You end with $%.2lf!", money);
				return 0;	
			default:
				printf("You must choose from 1 to 3. Choose again!\n");
		}
	}
}
