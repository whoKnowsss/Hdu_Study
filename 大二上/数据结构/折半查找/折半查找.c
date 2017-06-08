#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

#define N 10



typedef int DataType;//定义比较的元素类型?



					 //静态查找表的顺序存储结构

typedef struct {

	DataType * data;//数据元素存储空间基址，按实际长度分配，0号单元留空?

					//建表时按实际长度分配，0 号单元留空?

	int length;//表长度?

}SSTable;





//创建一个静态表，内容为20以内的随机数

void createST(SSTable* ST, int n) {

	int i;

	time_t t;

	if (ST != NULL) {

		ST->data = (DataType*)calloc(n + 1, sizeof(DataType));

		if (ST->data != NULL) {

			srand((unsigned)time(&t));

			for (i = 1; i <= n; i++) {

				ST->data[i] = rand();//产生20以内的随机数?

			}

			ST->length = n;

		}

	}

}



//创建一个静态表，内容按从小到大排列，以便折半查找?

void createST_binary(SSTable* ST, int n) {

	int i, j = 0;

	time_t t;

	if (ST != NULL) {

		ST->data = (DataType*)calloc(n + 1, sizeof(DataType));

		if (ST->data != NULL) {

			for (i = 1; i <= n; i++) {

				ST->data[i] = j;

				j += 4;

			}

			ST->length = n;

		}

	}

}



//打印出静态表的内容?

void print_SSTable(SSTable* ST) {

	int i, n = ST->length;

	if (ST != NULL) {

		for (i = 1; i <= n; i++) {

			printf("%d ", ST->data[i]);

		}

		printf("\n");

	}

}







int search_seq(SSTable ST, DataType key) {

	int i;

	if (ST.data == NULL)return 0;

	ST.data[0] = key;

	for (i = ST.length; ST.data[i] != key; i--);

	return i;

}



//折半查找(Binary Search)?

int search_binary(SSTable ST, DataType key) {

	int low, high, mid;

	low = 1;

	high = ST.length;

	while (low <= high) {//当表空间存在时

		mid = (low + high) / 2;

		if (ST.data[mid] == key) {

			return mid;//查找成功，返回mid?

		}

		if (key<ST.data[mid]) {

			high = mid - 1;//继续在前半区间查找?

		}

		else {

			low = mid + 1;//继续在后半区间查找?

		}

	}

	return 0;//查找失败?

}







int main() {

	int n = 20;

	SSTable ST, ST_binary;?

	createST(&ST, n);//创建一个随机静态表?

	createST_binary(&ST_binary, n);//创建一个从小到大顺序排列的静态表?

	//采用顺序查找?

	printf("原始数据:");

	print_SSTable(&ST);

	printf("顺序查找5的结果:%d\n", search_seq(ST, 5));

	printf("顺序查找10的结果:%d\n", search_seq(ST, 10));

	printf("顺序查找12的结果:%d\n", search_seq(ST, 12));

	printf("顺序查找15的结果:%d\n", search_seq(ST, 15));

	printf("顺序查找20的结果:%d\n", search_seq(ST, 20));



	printf("--------------------------------------------\n");

	//采用折半查找?

	printf("原始数据:");

	print_SSTable(&ST_binary);

	printf("折半查找5的结果:%d\n", search_binary(ST_binary, 5));

	printf("折半查找10的结果:%d\n", search_binary(ST_binary, 10));

	printf("折半查找12的结果:%d\n", search_binary(ST_binary, 12));

	printf("折半查找15的结果:%d\n", search_binary(ST_binary, 15));

	printf("折半查找20的结果:%d\n", search_binary(ST_binary, 20));



	system("pause");

	free(ST.data);

	return 0;

}