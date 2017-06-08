#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef struct {
	ElemType *head;         //数组的基址
	int col;               //矩阵的行
	int row;                //矩阵的列
}ARRAY;
enum Status
{
	OK, ERROR, OVERFLOW
};
enum BOOL
{
	FALSE, TRUE
};
//初始化数组
Status InitArray(ARRAY * arr, int col, int row) {
	arr->head = (ElemType *)malloc(col*row * sizeof(ElemType));
	if (!arr->head)return ERROR;
	memset(arr->head, 0, col*row*sizeof(int));
	arr->col = col;
	arr->row = row;
	return OK;
}
//销毁数组
Status DestoryArray(ARRAY *arr) {
	free(arr->head);
	arr->col = arr->row = 0;
	return OK;
}
//获取指定值
Status Value(ARRAY arr, ElemType *e, int col, int row) {
	if (arr.col == 0 || arr.row == 0||col>arr.col||arr.row<row || col<1 || row<1)return ERROR;
	*e = arr.head[(row - 1)*arr.col + col - 1];
	return OK;
}
//赋值
Status Assign(ARRAY *arr, ElemType e, int col, int row) {
	if (arr->col == 0 || arr->row == 0 || col>arr->col || arr->row<row||col<1||row<1)return ERROR;
	arr->head[(row-1)*arr->col + col-1] = e;
	return OK;
}
//转置
Status TransposeSMatrix(ARRAY * arr) {
	int i,j; 
	if (arr->col <= 0 || arr->row <= 0)
        return ERROR;
	for ( i = 0; i < arr->col; i++)
		for ( j = i; j < arr->row; j++) {
			 ElemType temp = arr->head[j*arr->col + i];
			 arr->head[j*arr->col + i] = arr->head[i*arr->col + j];
			 arr->head[i*arr->col + j] = temp;
		}
	return OK;
}
//矩阵乘法(arr1*arr2)
Status MultSMatrix(ARRAY arr1, ARRAY arr2, ARRAY * arr) {
	int j,k,i;
	if (arr1.col != arr2.row)
        return ERROR;
	arr->head = (ElemType *)malloc(arr1.row*arr2.col * sizeof(ElemType));
	arr->col = arr1.col; arr->row = arr2.row;
	for( j=0;j<arr1.col;j++)
		for ( k = 0; k < arr2.row; k++) {
			ElemType templine = 0;
			for ( i = 0; i < arr1.col; i++) {
				templine += arr1.head[j*arr1.col + i] * arr2.head[i*arr2.col + k];
			}
			arr->head[j*arr->col + k] = templine;
		}
	return OK;
}

int main() {
	int col = 5, row = 3;
	ARRAY arr,arr1;
	InitArray(&arr, col, row);
	InitArray(&arr1, row, col);
	ElemType e = 5;
	ElemType e1 = -1;
	Assign(&arr, e, 2, 1);
	Assign(&arr1, e, 2, 1);
	printf("1行2列数据赋值为5后再获取值：");
	Value(arr, &e1, 2, 1);
	printf("%d\n", e1);
	TransposeSMatrix(&arr);
	printf("转置后1行2列数据与2行1列数据：");
	ElemType e2 = -1,e3=-1;
	Value(arr, &e2, 2, 1);
	Value(arr, &e3, 1, 2);
	printf("%d %d\n", e2,e3);
	ARRAY arr2;
	MultSMatrix(arr, arr1, &arr2);
	Value(arr2, &e1, 2, 2);
	printf("初始化为2行1列为5的arr，1行2列为5的arr1,arr*arr1后在2行2列的值为:%d\n", e1);
	DestoryArray(&arr);
	return 0;
}
