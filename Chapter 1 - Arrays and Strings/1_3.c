/* 	Given two strings, write a method to decide if one is a permutation of the
	other. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int permutation(char *str1, char *str2){


	int i, j, count = 0, *array;
	array = malloc(strlen(str1)*sizeof(int));
	
	//Checking is string length for both strings is equal
	if (strlen(str1) != strlen(str2)){
		return 0;
	}

	//0(n^2) operation, i for str1, j for str2
	for (i = 0; i <= strlen(str1); i++){
		for (j = 0; j <= strlen(str1); j++){
			//If array is not equal to 0, this value is already used			
			if (array[j])
				continue;
			//If the characters match
			else if (str1[i] == str2[j]){
				array[j]++;
				count++;
				i++;
				j = 0;
				continue;
			}
			//If we made it to the end and haven't found a match, it's over
			else if (j == strlen(str1) - 1){
				return 0;
			}
		}
	} 

	//Making sure the number of characters that match is equal to the strlen
	if (count == strlen(str1))
		return 1;
	else {
		return 0;
	}
}

int main(){
	char str1[15], str2[15];

	printf("Enter string one:\n");
	scanf("%s", &str1);

	printf("Enter string two:\n");
	scanf("%s", &str2);

	if (permutation(str1, str2)){
		printf("It's a permutation!\n");
	}
	else
		printf("It's not a permutation :(\n");

	return 0;
}

/* If two strings are permutations, then we know they have the same characters, bun in different orders. Therefore, sorting the strings will put the characters from two permutations in the same order */
