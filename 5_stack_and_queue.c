#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

int ele_number = 0;
int count = 0;

int isfull(void){
	if (ele_number == count){
		return 1;
	}
	else
		return 0;
}

int isempty(void){
	if (ele_number){
		return 0;
	}
	else
		return 1;
}

void refresh(int** stack1, int** stack2){
	int i = 0;
	for (; i < ele_number; i++){
		**(stack2 + count - i -1) = **(stack1 + count - ele_number + i);
	}
}

void output(int** stack2){
	int i = count - ele_number;
	if (isempty())
		printf("your queue is empty!!\n");
	else{
		for (; i < count; i++){
			printf(" %d ", **(stack2 + i));
		}
		printf("\n");
	}
	
}

void initial(int** stack1,int**stack2){
	int n = 0;
	int element = 0;
	printf("input your queue's elements (can't be 0):\n");
	for (; n < count; n++){
		printf("element %d :", n+1);
		scanf_s("%d", &element);
		if (element){
			*(stack1 + count - 1 -n) = (int*)malloc(sizeof(int));
			*(stack2 + n) = (int*)malloc(sizeof(int));
			**(stack1 + count - n - 1) = element;
			**(stack2 + n) = 0;
			ele_number += 1;
			
		}
		else{
			printf("element can't be 0!\n");
			n--;
		}
	}
	refresh(stack1, stack2);
}

void add(int a,int** stack1, int** stack2){
	if (isfull()){
		printf("the queue is full!\n");
	}
	else{
		**(stack1 + count - ele_number - 1 ) = a;
		ele_number += 1;
		refresh(stack1, stack2);
		printf("%d has add to your queue...\n",a);
	}
	
}

void delete(int** stack1, int** stack2){
	int a = 0;
	if (isempty())
		printf("your queue is empty!!\n");
	else{
		a = **(stack2 + count - ele_number);
		**(stack2 + count - ele_number) = 0;
		ele_number -= 1;
		refresh(stack2,stack1);
		printf("%d has been deleted...\n", a);
	}
}

int main(void){
	int command = 0;
	int var = 0;
	printf("input the size of your queue:\n");
	scanf_s("%d", &count);
	int** stack1 = NULL;
	int** stack2 = NULL;
	stack1 = (int**)malloc(count*sizeof(int*));
	stack2 = (int**)malloc(count*sizeof(int*));
	printf("initial your queue:\n");
	initial(stack1, stack2);
	while (true){
		printf("waiting for command....1、add; 2、delete; 3、print;4、exit:\n ");
		scanf_s("%d", &command);
		switch (command){
		case 1:
			printf("input a element(can't be 0):\n");
			scanf_s("%d", &var);
			if (var)
				add(var, stack1, stack2);
			else
				printf("the element can't be 0!!\n");
			break;
		case 2:
			delete(stack1, stack2);
			break;
		case 3:
			output(stack2);
			break;
		case 4:
			return 0;
			break;
		default:
			printf("the operation isn't exit!!\n");
		}
	}
}