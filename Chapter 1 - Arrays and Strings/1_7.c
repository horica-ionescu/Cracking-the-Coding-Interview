/*	Write an alogorithm such that if an element in an MxN matrix is 0, it's 
	entire row and column are set to 0. 

	Input file has 2 digits to start - row length (M) and column length (N). 
	The proceding lines are the contents of the matrix. */

#include <stdio.h>
#include <stdlib.h>

int **set_row_zero(int **matrix, int *rows, int row_length, int col_length){
	int i, j;	

	for (i = 0; i < row_length; i++){
		if (rows[i] == 1){
			for (j = 0; j < col_length; j++){
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}

int **set_col_zero(int **matrix, int *cols, int row_length, int col_length){
	int i, j;	

	for (j = 0; j < col_length; j++){
		if (cols[j] == 1){
			for (i = 0; i < row_length; i++){
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}

int **instantiate_matrix(int row_length, int col_length){
	int i, **matrix;

	matrix = malloc(sizeof(int *) * row_length);
	if (matrix == NULL){
		printf("Error with memory allocation\n");
		exit(1);
	}
	for (int i = 0; i < row_length; i++){
		matrix[i] = malloc(sizeof(int) * col_length);
		if (matrix[i] == NULL){
			printf("Error with memory allocation\n");
			exit(1);
		}
	}	

	return matrix;
}

void free_memory(int **matrix, int row_length){
	int i;

	for (i = 0; i < row_length; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int main(){
	int i, j, **zero_matrix, **matrix, row_length, col_length, *rows, *cols;
	FILE *ifp = fopen("input.txt", "r");

	fscanf(ifp, "%d", &row_length);
	fscanf(ifp, "%d", &col_length);
	printf("%d %d\n", row_length, col_length);

	matrix = instantiate_matrix(row_length, col_length);
	
	//Scanning in matrix
	for (i = 0; i < row_length; i++){
		for (j = 0; j < col_length; j++){
			fscanf(ifp, "%d", &matrix[i][j]);			
		}
	}
	
	//Allocating memory for 'row' array
	rows = malloc(sizeof(int) * row_length);
	if (rows == NULL){
		printf("Error with malloc\n");
		return 1;
	}

	//Allocating memory for 'col' array
	cols = malloc(sizeof(int) * col_length);
	if (cols == NULL){
		printf("Error with malloc\n");
		return 1;
	}

	//Placing 1 in 'row' and 'col' array for each row and column that has a 0
	for (i = 0; i < row_length; i++){
		for (j = 0; j < col_length; j++){
			if (matrix[i][j] == 0){
				rows[i] = 1;
				cols[j] = 1;
			}			
		}
	}
	
	//Changing the correct values for 0 by row and column
	matrix = set_row_zero(matrix, rows, row_length, col_length);
	matrix = set_col_zero(matrix, cols, row_length, col_length);
	
	//Printing 'zeroed' matrix
	for (i = 0; i < row_length; i++){
		for (j = 0; j < col_length; j++){
			printf("%d ", matrix[i][j]);			
		}
		printf("\n");
	}

	//Freeing memory
	free_memory(matrix, row_length);
	free(rows);
	free(cols);
	return 0;
}
