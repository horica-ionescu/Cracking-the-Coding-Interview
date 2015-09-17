/* 	Implement a function void reverse(char *str) in C of C++ which reverses
	a null-terminated string. */

#include <stdio.h>
#include <string.h>

void reverse(char *str){
	char temp_front, temp_back;
	int i;
	
	for (i = 0; i <= strlen(str) - 1 - i; i++){
		temp_front = str[i];
		temp_back = str[strlen(str) - 1 - i];
		str[i] = temp_back;
		str[strlen(str) - 1 - i] = temp_front;
	}
}

int main(){
	char str[15];
	
	printf("Enter a string:\n");
	scanf("%s", &str);

	reverse(str);	
	
	printf("%s\n", str);

	return 0;
}
