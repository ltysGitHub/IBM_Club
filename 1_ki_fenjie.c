#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void){
	printf("�������ָ�����n����\n");
	int count;
	scanf_s("%d", &count);
	printf("����Ҫʹ�õ�����k��i����\n");
	float ki = 0;
	scanf_s("%f", &ki);
	float* array1 = (float*)calloc(count+1,sizeof(float));
	int i = 0;
	float number = 0;
	int counthead = 0;
	int countfoot = 0;
	for (; i < count; i++){
		printf("�����%d������:\n",i + 1);
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
	printf("������˳��\n");
	for (i = 0; i <= count; i++){
		printf(" %f ",*(array1+i));
	}
	system("pause");
	return 0;
}