#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

bool check(char a[]) {
	int i;
	for ( i = 0; i < strlen(a); i++) {
		if (isalpha(a[i]) == false && isdigit(a[i] == false)  && a[i] == ' ') { // if string contian special charecter --> check = false
			return (false);
		}
	}
	return (true);
}

void deleteSpace(char s[90],int pos){
	int i;
	int n = strlen(s);
    for(i = pos; i < n; i++) // reassign string
    	s[i] = s[i+1];
	s[n-1] = '\0';
}

void convert(char*s){
	int i;
    for(i=0;i<strlen(s);i++) 
		if(s[i]==' '&& s[i+1]==' ') // if charecter at index i and i + 1 are ' ' --> reassign string
		{
			deleteSpace(s,i);
			i--;
		}
    if(s[0]==' ') // if first charecter is ' ' --> reassign string
		deleteSpace(s,0);
    if(s[strlen(s)-1]==' ') // if last charecter is ' ' --> reassign string
		deleteSpace(s,strlen(s)-1);
}

int main(){
    char ch, s[90];
    while(true){ // loop until press 'Esc'
		fflush(stdin);
	    printf("Please enter a string: ");
	    gets(s);
	    
	    if(check(s) == false){ // if string contian special charecter --> re-enter
	    	printf("String must not contain special charecter\n");
	    	continue;
		}
	    
	    convert(s);
	    printf("The string after removing: ");
	    puts(s);
	    printf("Press enter to continue, Esc to exit\n");
	    
	    while(true){ // loop until press 'Enter' or 'Esc'
	    	fflush(stdin);
	    	ch = getch();
		    if(ch == 27){ // if press 'Esc' --> end program
		    	return 0;	
			}
			if(ch == 13){ // if press 'Enter' --> continue
		    	break;	
			}
		}
	}
    return 0;
}

