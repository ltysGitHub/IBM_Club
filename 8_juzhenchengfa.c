#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void){
	//创建三个二阶指针用以储存三个矩阵；
	int** p1 = NULL;
	int** p2 = NULL;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int** p3 = NULL;
	int count5 = 0;
	int count6 = 0;
	int i = 0;
	int m = 0;
	printf("input the row number of the first matrix:");
	scanf_s("%d",&count1);
	printf("input the col number of the first matrix:");
	scanf_s("%d",&count2);
	printf("input the row number of the second matrix:");
	scanf_s("%d", &count3);
	printf("input the col number of the second matrix:");
	scanf_s("%d", &count4);
	p1 = (int**)malloc(count1*sizeof(int*));
	p2 = (int**)malloc(count3*sizeof(int*));
	for (; i < count1; i++){
		*(p1 + i) = (int*)malloc(count2*sizeof(int));
	}
	i = 0;
	for (; i < count3; i++){
		*(p2 + i) = (int*)malloc(count4*sizeof(int));
	}
	if (count2 != count3){
		printf("error !");
		system("pause");
		exit(1);
	}
	printf("intput the first matrix:\n");
	i = m = 0;
	for (; i < count1; i++){
		m = 0;
		for (; m < count2; m++){
			printf("input(%d,%d) of the first matrix: ",i+1,m+1);
			scanf_s("%d",(*(p1+i)+m));
		}
	}
	printf("input the second matrix:\n");
	i = m = 0;
	for (; i < count3; i++){
		m = 0;
		for (; m < count4; m++){
			printf("input(%d,%d) of the second matrix: ", i + 1, m + 1);
			scanf_s("%d", (*(p2 + i) + m));
		}
	}
	count5 = count1;
	count6 = count4;
	i = 0;
	p3 = (int**)malloc(count5*sizeof(int*));
	for (; i < count5; i++){
		*(p3 + i) = (int*)malloc(count6*sizeof(int));
	}
	i = 0;
	for (; i < count5; i++){
		m = 0;
		for (; m < count6; m++){
			int n = 0;
			*(*(p3 + i) + m) = 0;
			for (; n < count2; n++){
				*(*(p3 + i) + m) += (*(*(p1 + i) + n)) * (*(*(p2 + n) + m));
			}
		}
	}
	i = 0;
	m = 0;
	for (; i < count1; i++){
		m = 0;
		for (; m < count2; m++){
			printf(" %d ", *(*(p1 + i) + m));
		}
		printf("\n");
	}
	i = 0;
	m = 0;
	printf("   *  \n");
	for (; i < count3; i++){
		m = 0;
		for (; m < count4; m++){
			printf(" %d ", *(*(p2 + i) + m));
		}
		printf("\n");
	}
	i = 0;
	m = 0;
	printf("   =   \n");
	for (; i < count5; i++){
		m = 0;
		for (; m < count6; m++){
			printf(" %d ", *(*(p3 + i) + m));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}