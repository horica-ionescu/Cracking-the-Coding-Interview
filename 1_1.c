/*	Arrays and Strings: Implement an algorithm to determine if a string has all 
	unique characters. What if you cannot use additional data structures? */

#include <stdio.h>
#include <string.h>

int main(){
	int ascii_values[128] = {0};
	int i;
	char str[10];
	
	printf("Enter a string less than 10 characters long:\n");
	scanf("%s", &str);

	//Checks that string length requirement is met
	if (strlen(str) > 10){
		printf("String too long\n");
		return 0;
	}
	
	//Increases each ascii value by one as it appears in 'str'
	for (i = 0; i < strlen(str); i++){
		if (ascii_values[str[i]]++ != 0){
			printf("String does not contain all unique characters\n");
			return 0;
		}
	} 

	
	printf("All unique characters!\n");	

	return 0;
}

/* 'Solution Notes from Book'

One simple optimization we can make is to automatically return 'false' if the 
length of the string is greater than the number of unique characters in the 
alphabet (128 for ASCII, 1,114,112 Unicode)

*/
