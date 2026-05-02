//Rocco duPont

#include <stdio.h>
#define WORDIN "word.txt"

int check(char word[], char answer[]);
int main(){

	char answer[6];
	char word[6][5];
	
	FILE* fptr;
	fptr = fopen("word.txt", "r");
	
	if(fptr == NULL){
		printf("%s could not be found. Sorry!\n", WORDIN);
		return 0;
		}
		
	fscanf(fptr, "%s", answer);
	fclose(fptr);
	
	printf("Welcome to Wordle! For each guess, please enter a 5 letter word.\n");
	
	int i;
	for (i = 0; i < 6; i ++){
	
	printf("GUESS %d:\n", i+1);
	printf("================================\n");
	
	scanf("%s", word[i]);
	
	int result = check(word[i], answer);
	
	if (result ==1){
		break;
		}
	if (i == 5){
	
		printf("Sorry, the correct answer was %s. Thanks for playing!\n",answer); 
		}
	}

	return 0;
}

int check(char word[], char answer[]){
	
	if (word[6] == '\0'){
	
	int matches = 0;
	for (int i = 0; i < 5; i++){
		if (word[i] == answer[i]){
			matches++;
			}
		}
	if (matches == 5){
		for (int k = 0; k <5; k++){
			word[k] = answer[k];
			}
			word[5] = '\0';
		printf("YOU WIN!\n");
		return 1;
		}
	else{
		
	for (int i = 0; i < 5; i++){
		if (word[i] == answer[i]){
			printf("%c", word[i]-32);
			}
		else{
			printf("%c", word[i]);
			}
		}
	printf("\n");
	for (int i = 0; i < 5; i++){
		if (word[i] == answer[i]){
			printf(" ");
			}
		else{
			int found = 0;
			for (int j = 0; j < 5; j++){
				if(word[i] == answer [j]){
					found = 1;
					break;
				}
			}
		if (found){
			printf("^");
			}
		else {
			printf(" ");
			}
		}
	}
}	
}
	else{
	printf("Word does not contain 5 letters. Try again!\n");
	}
return 0;
}
	

