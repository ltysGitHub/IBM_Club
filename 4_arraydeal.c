#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

int count1 = 0;
int count2 = 0;

void input(int** p ,int count){		//输入数组
	int i = 0;
	*p = (int*)calloc(count, sizeof(int));
	while (i < count){
		scanf_s("%d", (*p+i));	
		i++;
	}
}

int add(int* p1, int* p2,int** result){		//合并数组
	int i = 0;
	int n = 0;
	int key = 0;
	if (count2 <= count1){
		*result = (int*)realloc(p1, (count1 + count2) * sizeof(int));
		for (; i < count2; i++){
			key = *(p2 + i);
			for (n = count1 - 1; n >= 0; n--){
				if (key < *(*result + n)){
					*(*result + n + 1) = *(*result + n);
				}
				else{
					*(*result + n + 1) = key;
					count1 += 1;
					break;
				}
			}
		}
		return count1;
	}
	else{
		*result = (int*)realloc(p2, (count1 + count2) * sizeof(int));
		for (; i < count1; i++){
			key = *(p1 + i);
			for (n = count2 - 1; n >= 0; n--){
				if (key < *(*result + n)){
					*(*result + n + 1) = *(*result + n);
				}
				else{
					*(*result + n + 1) = key;
					count2 += 1;
					break;
				}
			}
		}
		return count2;
	}

}

void output(int* result, int count){	//输出数组
	int i = 0;
	for (; i < count; i++){
		printf("%d",*(result + i));
	}
}

int main(void){
	int* p1 = NULL;
	int* p2 = NULL;
	int* result = NULL;
	printf("输入两个升序排列的数组\n"); 


	printf("input the moment of the first array :\n");  //输入第一个数组
	scanf_s("%d",&count1);
	if (count1 <= 0){
		printf("error!");
		system("pause");
		exit(1);
	}
	printf("input the first array:\n");
	input(&p1, count1);


	printf("input the moment of the second array :\n");	//输入第二个数组
	scanf_s("%d", &count2);
	if (count2 <= 0){
		printf("error!");
		system("pause");
		exit(1);
	}
	printf("input the second array:\n");
	input(&p2, count2);


	int a = add(p1,p2,&result);
	printf("after putting them together,the result is: \n");
	output(result, a);	//输出结果
	system("pause");
	return 0;
}