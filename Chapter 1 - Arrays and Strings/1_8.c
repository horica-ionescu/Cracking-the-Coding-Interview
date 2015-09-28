/* 	Use a method 'isSubstring' which checks if one word is a substring of 
	another. Given two strings, s1 and s2, write code to check if s2 is a 
	rotation of s1 using one call to isSubstring (.e.g. "waterbottle" is a 
	rotation of "erbottlewat"). */

#include <stdio.h>
#include <string.h>

int isSubstring(char *string, char *substring){
	int i, j;

	if (strlen(string) < strlen(substring)){
		return 0;
	}

	for (i = 0; i < strlen(string); i++){
		for (j = 0; j < strlen(substring); j++){
			if (substring[j] != string[i + j]){
				break;			
			}
			if (j == strlen(substring) - 1){
				return 1;
			}
		}
	}
	
	return 0;
}

int main(){
	char str1[100], str2[100], doublestring[200];
	int i;

	printf("Enter string 1: \n");
	scanf("%s", &str1);
		
	printf("Enter string 2: \n");
	scanf("%s", &str2);
	
	//strcpy(str1, "waterbottle");
	//strcpy(str2, "erbotelewa");

	strcat(doublestring, str1);
	strcat(doublestring, str1);

	//printf("%d\n", isSubstring(doublestring, str2));
	
	if (isSubstring(doublestring, str2)){
		printf("The strings are rotations of each other!\n");
	}
	else{
		printf("The strings are not rotations of each other\n");
	}

	return 0;
}
