#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//행렬 출력 함수 선언
void print_matrix(int **matrix, int row, int column);
//행렬 덧셈 함수 선언
int **addition_matrix(int **matrix1, int **matrix2, int row, int column);
//행렬 뺄셈 함수 선언
int **subtraction_matrix(int **matrix1, int **matrix2, int row, int column);
//행렬 전치 함수 선언
int **transpose_matrix(int **matrix, int row, int column);
//행렬 곱셈 함수 선언
int **multiply_matrix(int **matrix1, int **matrix2, int row1, int column1, int row2, int column2);
//메모리 해제 함수 선언
void free_matrix(int **matrix, int row);


int main() {

    printf("[----- [Your Name]  [Student ID] -----]\n");
    //행렬의 크기와 행렬 포인터 변수 선언
    int row1, column1, row2, column2; 
    int **matrix1, **matrix2, **result; 
    int i, j;

    srand(time(NULL));  //난수 초기화
    printf("\nEnter the number of rows and columns of matrix A: "); //행렬 A의 크기 입력
    scanf("%d %d", &row1, &column1);
    printf("Enter the number of rows and columns of matrix B: "); //행렬 B의 크기 입력
    scanf("%d %d", &row2, &column2); 

    matrix1 = (int **)malloc(sizeof(int *) * row1); //행렬 A 메모리 할당
    for (i = 0; i < row1; i++) {
        matrix1[i] = (int *)malloc(sizeof(int) * column1);
    }

    matrix2 = (int **)malloc(sizeof(int *) * row2);//행렬 B 메모리 할당
    for (i = 0; i < row2; i++) {
        matrix2[i] = (int *)malloc(sizeof(int) * column2);
    }


    for (i = 0; i < row1; i++) {  //행렬 A에 난수 할당
        for (j = 0; j < column1; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < row2; i++) { //행렬 B에 난수 할당
        for (j = 0; j < column2; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }


    printf("Matrix A:\n"); //행렬 A 출력
    print_matrix(matrix1, row1, column1); 
    printf("Matrix B:\n"); //행렬 B 출력
    print_matrix(matrix2, row2, column2); 

    result = addition_matrix(matrix1, matrix2, row1, column1); //행렬 A와 B 덧셈 후 출력
    printf("Matrix A + B:\n"); 
    print_matrix(result, row1, column1); 
   
    free_matrix(result, row1); //결과 행렬 메모리 해제
    result = subtraction_matrix(matrix1, matrix2, row1, column1); //행렬 A와 B 뺄셈 후 출력
    printf("Matrix A - B:\n"); 
    print_matrix(result, row1, column1);
    free_matrix(result, row1); //결과 행렬 메모리 해제


    result = transpose_matrix(matrix1, row1, column1); //행렬 A 전치 후 출력
    printf("Transpose matrix A:\n"); 
    print_matrix(result, column1, row1); 
    free_matrix(result, column1); //결과 행렬 메모리 해제

    result = multiply_matrix(matrix1, matrix2, row1, column1, row2, column2); //행렬 A와 B 곱셈 후 출력
    printf("Matrix A * B:\n"); 
    print_matrix(result, row1, column2); 
 
    free_matrix(result, row1); //결과 행렬 메모리 해제
    free_matrix(matrix1, row1); //입력 행렬 메모리 해제
    return 0;
}

void print_matrix(int **matrix, int row, int column) { 
    int i, j; //반복문 제어 변수 선언

    for (i = 0; i < row; i++) { 
        for (j = 0; j < column; j++) { 
            printf("%d ", matrix[i][j]); //현재 원소 출력
        }
        printf("\n"); //한 행이 끝날 때마다 줄바꿈
    }
}

int **addition_matrix(int **matrix1, int **matrix2, int row, int column) { 
    int **result; //결과 행렬 포인터
    int i, j; //반복문 제어 변수

    result = (int **)malloc(sizeof(int *) * row); //결과 행렬의 행에 대한 메모리 할당
    for (i = 0; i < row; i++) {
        result[i] = (int *)malloc(sizeof(int) * column); //결과 행렬의 각 행에 대한 열 메모리 할당
    }

    for (i = 0; i < row; i++) { 
        for (j = 0; j < column; j++) { 
            result[i][j] = matrix1[i][j] + matrix2[i][j]; //행렬 덧셈 수행
        }
    }

    return result; //결과 행렬 반환
}

int **subtraction_matrix(int **matrix1, int **matrix2, int row, int column) {
    int **result; //결과 행렬 포인터
    int i, j; //반복문 제어 변수

    result = (int **)malloc(sizeof(int *) * row); //결과 행렬의 행에 대한 메모리 할당
    for (i = 0; i < row; i++) {
        result[i] = (int *)malloc(sizeof(int) * column); //결과 행렬의 각 행에 대한 열 메모리 할당
    }

    for (i = 0; i < row; i++) { 
        for (j = 0; j < column; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j]; //행렬 뺄셈 수행
        }
    }

    return result; //결과 행렬 반환
}

int **transpose_matrix(int **matrix, int row, int column) {
    int **result; //결과 행렬 포인터
    int i, j; //반복문 제어 변수

    result = (int **)malloc(sizeof(int *) * column); //전치 행렬의 '행'에 대한 메모리 할당(원본 행렬의 열 수 만큼)
    for (i = 0; i < column; i++) {
        result[i] = (int *)malloc(sizeof(int) * row); //전치 행렬의 각 '행'에 대한 '열' 메모리 할당(원본 행렬의 행 수 만큼)
    }

    for (i = 0; i < column; i++) { 
        for (j = 0; j < row; j++) { 
            result[i][j] = matrix[j][i]; //전치 수행(행과 열을 바꿔 할당)
        }
    }

    return result; //결과 행렬 반환
}

int **multiply_matrix(int **matrix1, int **matrix2, int row1, int column1, int row2, int column2) {
    int **result; //결과 행렬 포인터
    int i, j, k; //반복문 제어 변수

    result = (int **)malloc(sizeof(int *) * row1); //결과 행렬의 행에 대한 메모리 할당
    for (i = 0; i < row1; i++) {
        result[i] = (int *)malloc(sizeof(int) * column2); //결과 행렬의 각 행에 대한 열 메모리 할당
    }

    for (i = 0; i < row1; i++) { 
        for (j = 0; j < column2; j++) { 
            result[i][j] = 0; //결과 행렬 초기화
            for (k = 0; k < column1; k++) { //첫 번째 행렬의 열/두 번째 행렬의 행 순회
                result[i][j] += matrix1[i][k] * matrix2[k][j]; //행렬 곱셈 수행
            }
        }
    }

    return result; //결과 행렬 반환
}

void free_matrix(int **matrix, int row) {
    int i; //반복문 제어 변수

    for (i = 0; i < row; i++) {
        free(matrix[i]); //각 행에 할당된 메모리 해제
    }
    free(matrix); //행렬 전체에 할당된 메모리 해제
}