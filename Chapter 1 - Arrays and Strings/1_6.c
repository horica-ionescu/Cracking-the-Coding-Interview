/* 	Given an image represented by an NxN matrix, where each pixel in the image 
	is 4 bytes, write a method to rotate the image by 90 degrees.

	Input will be 'N', which is the number of rows and columns in the matrix,
	followed by the NxN elements of the matrix. */

#include <stdio.h>
#include <stdlib.h>

void print(int **matrix, int size){
	int i, j;
	
	printf("\n");
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int **instantiate_matrix(int size){
	int i, **matrix;

	//Allocating memory
	matrix = malloc(sizeof(int *) * size);
	if (matrix == NULL){
		fprintf(stderr, "Out of memory\n");
		return 0;
	}
	for (i = 0; i < size; i++){
		matrix[i] = malloc(sizeof(int) * size);
		if (matrix[i] == NULL){
			fprintf(stderr, "Out of memory\n");
			return 0;
		}
	}

	return matrix;
}

int **clockwise(int **matrix, int size){
	int **blank_matrix, i, j;

	blank_matrix = instantiate_matrix(size);

	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			blank_matrix[j][size-1-i] = matrix[i][j];
		}
	}

	return blank_matrix;
}

int **counter_clockwise(int **matrix, int size){
	int **blank_matrix, i, j;

	blank_matrix = instantiate_matrix(size);

	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			blank_matrix[size-1-j][i] = matrix[i][j];
		}
	}

	return blank_matrix;
}

void flip(int **matrix, int size){
	int option;
	printf("Which way do you want to flip the matrix?\n");
	printf("1) - Clockwise\n");
	printf("2) - Counter-clockwise\n");
	printf("3) - Exit\n");
	scanf("%d", &option);
	
	if (option == 1){
		matrix = clockwise(matrix, size);
	}
	else if (option == 2){
		matrix = counter_clockwise(matrix, size);
	}
	else if (option == 3){
		exit(1);
	}
	else{
		printf("You have entered an incorrect selection. Try again\n\n");
		flip(matrix, size);
	}

	print(matrix, size);

	printf("Neat, huh?\n\n");
	flip(matrix, size);
}

int main(){
	int size_of_matrix, **matrix, i, j;
	FILE *ifp;

	ifp = fopen("input.txt", "r");

	//Scanning size
	fscanf(ifp, "%d", &size_of_matrix);
	//printf("%d\n", size_of_matrix);

	matrix = instantiate_matrix(size_of_matrix);

	//Reading in matrix
	for (i = 0; i < size_of_matrix; i++){
		for (j = 0; j < size_of_matrix; j++){
			fscanf(ifp, "%d", &matrix[i][j]);
		}
	}
	
	print(matrix, size_of_matrix);

	flip(matrix, size_of_matrix);

	//Freeing memory
	for (i = 0; i < size_of_matrix; i++){
		free(matrix[i]);
	}

	free(matrix);
	return 0;
}
