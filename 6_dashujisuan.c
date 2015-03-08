#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

void chushihua(short* p, int count){//将每一位初始化为零
	int i = 0;
	for (; i < count; i++){
		*(p + i) = 0;
	}
}

void jinwei(short* p, int count){//对每一位进行进位运算
	short wei = 0;
	int i = 0;
	for (; i < count-1; i++){
		if (*(p + count - 1- i) >= 10){
			wei = *(p + count - 1 - i) / 10;
			*(p + count - 1 - i) %= 10;
			*(p + count - 2 - i) += wei;
		}
	}
}

void jiewei(short* p, int count){//对每一位进行借位运算
	short wei = 0;
	int i = 0;
	for (; i < count - 1; i++){
		if (*(p + count - 1 - i) < 0){
			wei = 1;
			*(p + count - 1 - i) += 10;
			*(p + count - 2 - i) -= wei;
		}
	}
}

int bijiao(short* p1, short* p2, short count1, int count2, int i){//比较两个数的大小
	if (count1>count2){
		return 1;
	}
	else if (count1 < count2){
		return -1;
	}
	else if (count1 == count2){
		if (i < count1){
			if (*(p1 + i) > *(p2 + i)){
				return 1;
			}
			else if (*(p1+i)<*(p2+i)){
				return -1;
			}
			else{
				i += 1;
				bijiao(p1,p2,count1,count2,i);
			}
		}
		else{
			return 0;
		}
	}
}

void jia(short* p1, short* p2, short* result, int count1, int count2, int count3){  //加运算
	int i = 0;
	short result0 = 0;
	int max_count = count1 >= count2 ? count1 : count2;
	int min_count = count2 > count1 ? count1 : count2;
	for (; i < min_count; i++){
		result0 = *(p1+count1-i-1) + *(p2+count2-1-i);
		*(result + count3 - 1 - i) += result0;
	}
	if (count1>count2){
		for (; i < count1; i++){
			*(result + count3 - 1 - i) += *(p1 + count1 - 1 - i);
		}
	}
	if (count1 < count2){
		for (; i < count2; i++){
			*(result + count3 - 1 - i) += *(p2 + count2 - 1 - i);
		}
	}
	jinwei(result, count3);
}

int jian(short* p1, short* p2, short* result, int count1, int count2, int count3){  //减运算
	int i = 0;
	int daxiao = bijiao(p1, p2, count1, count2, i);
	short result0 = 0;
	if (daxiao == 1){
		for (; i < count2; i++){
			result0 = *(p1 + count1 - 1 - i) - *(p2 + count2 - 1 - i);
			*(result + count3 - i - 1) += result0;
		}
		for (; i < count1; i++){
			*(result + count3 - 1 - i) += *(p1 + count1 - 1 - i);
		}
		jiewei(result,count3);
		return 0;
	}
	else if(daxiao == 0){
		return 0;
	}
	else{
		jian(p2,p1,result,count2,count1,count3);
		return 1;
	}
}

void cheng(short* p1, short* p2, short* result, int count1, int count2, int count3){ //乘运算
	short * p3 = NULL;
	short *p4 = NULL;
	p3 = (short*)calloc(count3, sizeof(short));
	p4 = (short*)calloc(1, sizeof(short));
	chushihua(p3, count3);
	*p3 = *p4 = 0;
	int i1 = 0;
	int i2 = 0;
	short result0 = 0;
	int count_min = count2 > count1 ? count1 : count2;
	int count_max = count1 > count2 ? count1 : count2;
	if (count1 > count2){
		for (; i2 < count_min; i2++){
			i1 = 0;
			for (; i1 < count_max; i1++){
				result0 =(*(p1+count1-1-i1)) * (*(p2+count2-1-i2));
				*(p3 + count3 - 1 - i2 - i1) = result0;
			}
			jinwei(p3, count3);
			jia(p3,p4,result,count3,1,count3);
			int i = 0;
			chushihua(p3, count3);
		}
	}
	if (count1 <= count2){
		for (; i2 < count_min; i2++){
			i1 = 0;
			for (; i1 < count_max; i1++){
				result0 = (short)((*(p2 + count2 - 1 - i1)) * (*(p1 + count1 - 1 - i2)));
				*(p3 + count3 - 1 - i2 - i1) = result0;
			}
			jinwei(p3, count3);
			jia(p3, p4, result, count3, 1, count3);
			chushihua(p3, count3);
		}
	}
}

void chu(int* p1, int* p2, int* result, int count1, int count2, int count3){  //除运算
	printf("sorry，this operation is not working。。。。。");
}



int main(void){
	int i = 0;
	int count1 = 0;
	int count2 = 0;
	int st = 0;
	bool x = true;
	short* wp = NULL;
	short* p1 = NULL;
	short* p2 = NULL;

	printf("input the first number:");
		while (x){
			st = (short)_getch() - 48;
			if (count1 == 0 && st == 0){
				printf("the first can't be 0!!!");
				system("pause");
				exit(1);
			}
			else if (count1 == 0 && st == -35){
				printf("number can't be empty!!!");
				system("pause");
				exit(1);
			}
			else if (st!=-35 && (st >= 10 || st < 0)){
				printf("pressed an error key! please input a number");
				system("pause");
				exit(1);
			}
			else if (count1 > 0 && st == -35){
				x = false;
			}
			else{
				count1++;
				wp = (short*)realloc(p1, count1*sizeof(short));
				if (wp == p1){
					wp = NULL;
				}
				else{
					free(p1);
					p1 = wp;
					wp = NULL;
				}
				*(p1 + count1 -1) = st;
				printf("%d", st);
			}
		}
	printf("\n");
	x = true;
	printf("input the second number:");
	while (x){
		st = (short)_getch() - 48;
		if (count2 == 0 && st == 0){
			printf("the first can't be 0!!!");
			system("pause");
			exit(1);
		}
		else if (count2 == 0 && st == -35){
			printf("number can't be empty!!!");
			system("pause");
			exit(1);
		}
		else if (st != -35 && (st >= 10 || st < 0)){
			printf("pressed an error key! please input a number");
			system("pause");
			exit(1);
		}
		else if (count2 > 0 && st == -35){
			x = false;
		}
		else{
			count2++;
			wp = (short*)realloc(p2, count2*sizeof(short));
			if (wp == p2){
				wp = NULL;
			}
			else{
				free(p2);
				p2 = wp;
				wp = NULL;
			}
			*(p2 + count2 - 1) = st;
			printf("%d",st);
		}
	}
	printf("\n");
	int action;
	printf("\ninput action:'+' '-' '*' '/':");//输入要进行的操作
	action = (int)_getch();
	if (action != 43 && action != 42 && action != 45 && action != 161){
		printf("entered an error action!!!");
		system("pause");
		exit(1);
	}
	switch (action)
	{
	case 43:
		; printf("+\n\n\n");
		int count3 = 1 + (count1 > count2 ? count1 : count2);
		short* result1 = (short*)calloc(count3, sizeof(short));
		chushihua(result1, count3);
		jia(p1, p2, result1,count1,count2,count3);
		for (i = 0; i < count1; i++){
			printf("%d", *(p1 + i));
		}
		printf(" + ");
		for (i = 0; i < count2; i++){
			printf("%d", *(p2 + i));
		}
		printf(" \n= ");
		for (i = 0; i < count3; i++){
			printf("%d",*(result1+i));
		}
		printf("\n");
		break;
	case 45:
		; printf("-\n\n\n");
		int count4 = 1 + (count1 > count2 ? count1 : count2);
		short* result2 = (short*)calloc(count4, sizeof(short));
		chushihua(result2, count4);
		for (i = 0; i < count1; i++){
			printf("%d", *(p1 + i));
		}
		printf(" - ");
		for (i = 0; i < count2; i++){
			printf("%d", *(p2 + i));
		}
		printf(" \n= ");
		if (jian(p1, p2, result2, count1, count2, count4))
			printf("-");
		for (i = 0; i < count4; i++){
			printf("%d", *(result2+i));
		}
		printf("\n");
		break;
	case 42:
		; printf("*\n\n\n");
		int count5 = 2 * (count1 > count2 ? count1 : count2);
		short* result3 = (short*)calloc(count5, sizeof(short));
		chushihua(result3, count5);
		cheng(p1, p2, result3, count1, count2, count5);
		for (i = 0; i < count1; i++){
			printf("%d", *(p1 + i));
		}
		printf(" * ");
		for (i = 0; i < count2; i++){
			printf("%d", *(p2 + i));
		}
		printf(" \n= ");
		for (i = 0; i < count5; i++){
			printf("%d", *(result3 + i));
		}
		printf("\n");
		break;
	case 161:
		; printf("/\n\n\n");
		int count6 = 2 * (count1 > count2 ? count1 : count2);
		short* result4 = (short*)calloc(count6, sizeof(short));
	chushihua(result4, count6);
	chu(p1, p2, result4, count1, count2, count6);
	for (i = 0; i < count1; i++){
		printf("%d", *(p1 + i));
	}
	printf(" - ");
	for (i = 0; i < count2; i++){
		printf("%d", *(p2 + i));
	}
	printf(" \n= ");
	for (i = 0; i < count6; i++){
		printf("%d", *(result4 + i));
	}
	printf("\n");
	break; 
	default:
		printf("input a error number");
	}
	system("pause");
	return 0;
}

