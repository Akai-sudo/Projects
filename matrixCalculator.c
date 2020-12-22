//Basic Matrix calculator
#include <stdio.h>
#include <stdlib.h>

//TODO
void addition(char symbol) 
{

}


int main()
{
    printf("Please provide the dimensions of your matrix: \n");
    int dim;
    scanf("%d", &dim);

    printf("So far we haven't incorporated operations with non-square matrix dimensions. With that in mind, we will assume you are operating with a %d x %d matrix.\n", dim, dim);

    printf("If you wish to continue, please enter the symbol of the desired operation (e.g. + for addition): \n");

    char symbol;
    scanf("%c", &symbol);

    printf("Please provide the values of your first matrix, row by row: \n");
    
    //allocate memory for creation of matrix
    int **matrix1 = malloc(dim * sizeof(int));
    for(int i = 0; i < dim; i++) {
        matrix1[i] = malloc(dim * sizeof(int));
    }
    
    int **matrix2 = malloc(dim * sizeof(int));
    for(int i = 0; i < dim; i++) {
        matrix2[i] = malloc(dim * sizeof(int));
    }
    
    //read user input
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            scanf("%d", matrix1[i][j]);
        }
    }
    
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            scanf("%d", matrix2[i][j]);
        }
    }
    

    switch(symbol) {
        case '+':
            addition(symbol);
            break;

        case '-':

            break;
        
        default:
            printf("Error. Invalid operation input. %c is not an acceptable form of operation on matrices\n", symbol);
    }
    
    
    //free allocated memory for matrix int values
    for(int i = 0; i < dim; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    return 0;
}
