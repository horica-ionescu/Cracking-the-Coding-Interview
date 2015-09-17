/*	Implement a method to perform basic string compression using the counts of
	repeated characters. For example, the string aabcccccaaa would become 
	a2b1c5a3. If the "compressed" string would not become smaller than the 
	original string, your method should return the original string. You can
	assume the string has only upper and lower case letters (a-z) */

#include <stdio.h>
#include <string.h>

int main(){
	int i, next = 0, count = 0, flag = 0;
	char str1[100], str2[100], character;

	printf("Enter string\n");
	scanf("%s", &str1);

	for (i = 0; i < strlen(str1); i++){
		//If str1[i] does not equal the current character
		if (str1[i] != character){
			//If count is more than 0 (instance isn't the first)
			if (count != 0){
				str2[next++] = count + '0';
			}
			str2[next++] = str1[i];
			character = str1[i];
			count = 1;
		}
		else{
			count++;
			if (count > 2)
				flag = 1;
		}
	}

	//Adding the last number and the null character	
	str2[next++] = count + '0';
	str2[next++] = '\0';
	
	//If flag = 0, then str1 is less than or equal to the length of str2
	if (!flag)
		printf("%s\n", str1);
	else
		printf("%s\n", str2);

	return 0;
}
