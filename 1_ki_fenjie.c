#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void){
	printf("输入数字个数（n）：\n");
	int count;
	scanf_s("%d", &count);
	printf("输入要使用的数字k【i】：\n");
	float ki = 0;
	scanf_s("%f", &ki);
	float* array1 = (float*)calloc(count+1,sizeof(float));
	int i = 0;
	float number = 0;
	int counthead = 0;
	int countfoot = 0;
	for (; i < count; i++){
		printf("输入第%d个数字:\n",i + 1);
		scanf_s("%f", &number);
		if (number <= ki){
			*(array1 + counthead) = number;
			counthead += 1;
		}
		else{
			*(array1 + count - countfoot) = number;
			countfoot += 1;
		}
	}
	*(array1 + counthead) = ki;
	printf("插入后的顺序：\n");
	for (i = 0; i <= count; i++){
		printf(" %f ",*(array1+i));
	}
	system("pause");
	return 0;
}