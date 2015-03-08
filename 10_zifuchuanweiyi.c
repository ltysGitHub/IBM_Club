#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

int count = 1;

void move_one(char*p){
	char swap = *(p + count - 1);
	int i = 1;
	while(i<count){
		*(p + count - i) = *(p + count - i - 1);
		i++;
	}
	*(p + 0) = swap;
}

void move(char* p, int m){
	int i = 0;
	for (;i<m;i++){
		move_one(p);
	}
}

int main(void){
	printf("please input your string:\n");
	bool x = true;
	char* p = (char*)malloc(count*sizeof(char));
	char* p1 = NULL;
	char a = ' ';
	int m = 0;
	while (x){
		a = _getch();
		if (a != 13){
			printf("%c", a);
			*(p + count - 1) = a;
			count++;
			p1 = (char*)realloc(p,count*sizeof(char));
			if (p1 == p){
				p1 = NULL;
			}
			else{
				free(p);
				p = p1;
				p1 = NULL;
			}

		}
		else{
			x = false;
			count--;
		}
	}
	printf("\nplease input a number£º");
	scanf_s("%d", &m);
	m = m % count;
	move(p, m);
	printf("\nyour string have became:\n");
	int i = 0;
	for (; i < count; i++){
		printf("%c", *(p + i));
	}
	system("pause");
	return 0;
}