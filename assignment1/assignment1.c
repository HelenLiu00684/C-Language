/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 15-01-2025  
 * Course: CST8234 
 * Project: Assignment1 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TOLERANCE 1e-9 /*Define tolerance for calculate sqrtroot*/ 

void inputSudokuGrid(int **parray2D, int grid_size);    /*Input Sudoku grid function*/ 
void printSudokuGrid(int **parray2D, int num);    /*Printout Sudoku grid function*/ 
void solveSudoku(int **parray2D, int num);    /*Solve Sudoku grid function to invoke backtrack sub_function*/ 
bool backtrack(int **parray2D, int row, int col,int grid_size);     /*Backtracking algorithm*/ 
void freeMemory(int **parray2D, int num);       /*Free memory*/ 
bool isValid(int **parray2D, int row, int col, int number, int grid_size);  /*Check if a number is valid*/ 
double sqrtroot(double grid_size);  /*Calculate square root*/
double my_fabs(double x);   /*Calculate absolute value*/ 

int main(void) {
    char choice_char;   /* Use char for reading characters*/
    int row=-1; 
    int root;   /*Square root*/ 
    int **parray2D=NULL;    /*2D array to store Sudoku grid*/ 
    double grid_size=-1;    /*Input at 9/16/25 for Sudoku grid*/ 
    int flag = 0 ;      /*remain in the main menu*/ 

    while(true){
    printf("Menu System:\n");
    printf("1. Input a new Sudoku puzzle\n");
    printf("2. Solve the current puzzle\n");
    printf("3. Display the current grid\n");
    printf("4. Exit\n");
    printf("Enter your choice (1/2/3/4): ");

    scanf(" %c", &choice_char); /* Important: Space before %c to consume leftover newline*/


        switch (choice_char) {
        case '1':

            while (flag != 1) {
            printf("Enter the size of Sudoku grid (e.g., 9 for 9x9, 16 for 16x16, 25 for 25 * 25):");
            scanf("%lf", &grid_size);
            root=(int)sqrtroot(grid_size);/*Calculate square root*/ 
            if(root==-1){   /*If not a perfect square*/ 
                printf("Error: Invalid Size. Please enter a valid Sudoku grid size(e.g, 9,16,etc)\n");printf("The root is : %d\n",root);
                while (getchar() != '\n'); 
                continue; 
            }
            else{
                printf("The root is: %d\n", root);
                break;
            }

            if (grid_size > 0 && root) {    /*Check if grid size is valid*/ 
                break;
            }else{    
                perror("Error: Cannot be negative and the grid_size can sqrt is integer. Please enter a valid degree\n");
                while (getchar() != '\n');
                }
            }

            /* Allocate memory *before* calling add SUDOKU values*/
            parray2D = (int **)malloc(grid_size * sizeof(int *));
            if (parray2D == NULL) {
                perror("parray2D Memory allocation failed");
                exit(1); /* Exit with error */
            }

            for (row = 0; row < grid_size; row++) {
                parray2D[row] = (int *)malloc(grid_size * sizeof(int));
                if (parray2D[row] == NULL) {
                    perror("Parray2D[i] Memory allocation failed");
                    exit(1);/*Memory allocation failed, exit*/ 
                }
            }
            inputSudokuGrid(parray2D,grid_size);
            break;
        case '2':
            printf("2. Solve the current puzzle\n");
                solveSudoku(parray2D,grid_size);
                printSudokuGrid(parray2D,grid_size);
            break;
        case '3':
            printf("3. Display the current grid\n");
            printSudokuGrid(parray2D,grid_size);
            break;
        case '4': /* Handle both lowercase and uppercase 'x'*/
            freeMemory(parray2D, grid_size);
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;

    
}

void inputSudokuGrid(int **parray2D, int grid_size) {
    int i=-1,j=-1;
    printf("Enter the Sudoku grid values row by row：(0---unknown number)\n");
    for (i = 0; i < grid_size; i++) {
        printf("Enter the Row %d value: ", i + 1);
        for (j = 0; j < grid_size; j++) {
            if (scanf("%d", &parray2D[i][j] )!= 1) {              
                printf("Error: Please enter a valid integer for the value;\n");
                while (getchar() != '\n');
                j--;
                continue;
            }
        }
    }

    
    printf("\n");
    for(i=0;i<grid_size;i++){
        for(j=0;j<grid_size;j++){    
            printf("%d ",parray2D[i][j]);
        }
        printf("\n");
    }    
    for(i=0;i<grid_size;i++){
        for(j=0;j<grid_size;j++){
            if(parray2D[i][j]!=0){
                if(isValid(parray2D, i, j, parray2D[i][j], grid_size)==false){
                    printf("the item parray2D[%d][%d] is duplicate,the value is %d\n",i,j,parray2D[i][j]);
                    }
                }
            }
        }
   
    }

void printSudokuGrid(int** grid, int size) {
    int i,j;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int **parray2D, int row, int col, int number, int grid_size) {
    int i, j;
    int subsize;
    int start_row, start_col;

    
    /*Check Row for Duplicates*/ 
    for (i = 0; i < grid_size; i++) {
        if (parray2D[row][i] == number&&i != col) {
            return false; /*Found duplicate in row, placement is invalid*/ 
        }
    }

    /*Check Column for Duplicates*/ 
    for (i = 0; i < grid_size; i++) {
        if (parray2D[i][col] == number&& i != row) {
            return false; /*Found duplicate in column, placement is invalid*/ 
        }
    }

    /*Check Sub grid for Duplicates*/ 
    subsize = (int)sqrtroot(grid_size);
    start_row = (row / subsize) * subsize;
    start_col = (col / subsize) * subsize;
    for (i = 0; i < subsize; i++) {
        for (j = 0; j < subsize; j++) {
            if (parray2D[start_row + i][start_col + j] == number&&(start_row + i != row || start_col + j != col)) {
                return false; /*Found duplicate in sub grid, isValued is invalid*/ 
            }
        }
    }
    return true; /*No duplicates found in row, column, or subgrid, isValued is valid*/ 
}
void solveSudoku(int** grid, int size) {
    if(backtrack(grid, 0, 0, size))
        printf("The puzzle has been solved.\n");
    else
        printf("The puzzle can not be soloved.\n");
   
}

bool backtrack(int** grid, int row, int col, int size) {
    int num;
    if (row == size) return true; /*At the bottom of the row */ 
    if (col == size) return backtrack(grid, row + 1, 0, size); /* change to the next row */ 
    if (grid[row][col] != 0) return backtrack(grid, row, col + 1, size); /*change to the next number*/ 
    for (num = 1; num <= size; ++num) {
        if (isValid(grid, row, col, num, size)) {
            grid[row][col] = num;
            if (backtrack(grid, row, col + 1, size)) return true;
            grid[row][col] = 0; /*withdraw the value*/ 
        }
    }
    return false;
}
void freeMemory(int **parray2D, int grid_size){
    /* Free memory *after* solove the puzzle is done*/
    int i=-1;
        for (i = 0; i < grid_size; i++) {
            free(parray2D[i]);
        }
        free(parray2D);
}



double sqrtroot(double grid_size) {     /*calculate sqrt number based on the grid_size*/
    double left,right; 
    double result;
    double mid;
    if (grid_size <= 0) {
        return 0;
    }

    left = 0.0, right = grid_size;

    while (right - left > TOLERANCE) {
        mid = (left + right) / 2.0;
        if (mid * mid < grid_size) {
            left = mid;
        } else {
            right = mid;
        }
    }

    result = (left + right) / 2.0;
    if (my_fabs(result - (int)(result + 0.5)) < TOLERANCE) {
        return (int)((int)(result + 0.5)); /*return sqrt value if result is closer*/ 
    } else {
        return -1; /*return -1 don't have the sqrt number.*/ 
    }
}

/* Get absolute value */
double my_fabs(double x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}