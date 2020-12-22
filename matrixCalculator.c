#include <stdio.h>
#include <stdlib.h>

void addition(char symbol) 
{

}


int main()
{
    printf("Please provide the dimensions of your matrix: \n");
    int dim;
    scanf("%d", &dim);

    printf("So far we haven't incorporated operations with non-square matrix dimensions. Knowing this, we will assume you are operating with a %d x %d matrix.\n", dim, dim);

    printf("If you wish to continue, please enter the symbol of the desired operation (e.g. + for addition): \n");

    char symbol;
    scanf("%c", &symbol);

    printf("Please provide the values of your first matrix, row by row: \n");
    int **matrix1 = malloc(dim * sizeof(int));
    for(int i = 0; i < dim; i++) {

    }

    switch(symbol) {
        case '+':
            void addition(symbol);
            break;

        case '-':

            break;
        
        default:
            printf("Error. Invalid operation input. %c is not an acceptable form of operation on matrices\n", symbol);
    }
    switch()
    return 0;
}