/*	Write a method to replace all spaces in a string with '%20'. You may assume
	that the string has sufficient space at the end of the string to hold the
	additional characters, and that you are given the "true" length of the
	string. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace(char *str, int size){
	char *str2;
	int spaces = 0, i, j = 0;

  	for (i = 0; i < size; i++){
		if (str[i] == ' ')
			spaces++;
	}
		
	printf("%d\n", spaces);
	
	str2 = malloc(sizeof(char) * (size + spaces * 2 + 1));	

	for (i = 0; i < size; i++){
		if (str[i] != ' '){
			str2[j++] = str[i];
		}
		else{
			str2[j++] = '%';
			str2[j++] = '2';
			str2[j++] = '0';
		}
	}
	
	str2[j] = '\0';
	printf("%s\n", str2);
}

int main(){
	char str[100];
	char buffer;
	int size;

	printf("Enter string on one line, and length on the next\n");
	scanf("%[^\n]" , &str);
	scanf("%d", &size);

	printf("%s, %d\n", str, size);	

	replace(str, size);

	return 0;
}
