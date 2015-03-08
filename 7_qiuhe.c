#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

int count = 0;
int result = 0;
bool pan = false;

void sort(int* p,int start,int end){
	int key = *(p + start);
	int m = start + 1;
	int n = end;
	int i = start;
	int swap = 0;
	while ( m <= n){
		if (*(p + n) >= key){
			n--;
		}
		else{
			swap = *(p + i);
			*(p + i) = *(p + n);
			*(p + n) = swap;
			i = n;
			n--;
			while (m <= n){
				if (*(p + m) <= key){
					m++;
				}
				else{
					swap = *(p + i);
					*(p + i) = *(p + m);
					*(p + m) = swap;
					i = m;
					m++;
					break;
				}
			}
		}
	}
	if (start<i)
	sort(p,start,i);
	if (i<end)
	sort(p, i+1, end);
}

void erfenchazhao(int*p, int first, int end, int cha, int A , int i)
{
	if (first <= end)
	{
		int m = (end + first) / 2;
		if (*(p + m) + cha == A && end != i)
		{
			printf("%d + %d = %d", cha, *(p + m), A);
			pan = true;
			return;
		}
		else if (*(p + m) + cha < A)
		{
			erfenchazhao(p, m + 1, end, cha, A, i);
		}
		else if (*(p + m) + cha > A)
		{
			erfenchazhao(p, first, m - 1, cha, A, i);
		}
	}
	else
		return;
}

int main(void){
	printf("input the size of your array:");
	scanf_s("%d",&count);
	int* p = (int*)malloc(count*sizeof(int));
	int i = 0;
	for (; i < count; i++){
		printf("input the %d number",i+1);
		scanf_s("%d",(p+i));
		
	}
	sort(p,0,count - 1);
	printf("input the result you want:\n");
	scanf_s("%d", &result);
	for (i = 0; i < count && pan==false; i++){
		erfenchazhao(p,0,count-1,*(p+i),result,i);
	}
	if (pan == false)
		printf("can't find!");
	system("pause");
	return 0;

}

