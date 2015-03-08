#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

char* xx = NULL;
char* zx = NULL;
int count1 = 0;
int count2 = 0;
typedef struct node node;

struct node{
	node* left;
	node* right;
	char value;
};

void input(char** inp, int* count){
	char* ch = NULL;
	bool b = true;
	char a = 13;
	while (b){
		a = _getch();
		if (*count == 0 && a == 13){
			printf("can't be empty");
		}
		else if (*count != 0 && a == 13){
			b = false;
		}
		else if ((a - 'a' <= 25 && a - 'a' >= 0) || (a - 'A' <= 25 && a - 'A' >= 0)){
			(*count)++;
			printf("%c", a);
			ch = (char*)realloc(*inp, (*count)*sizeof(char));
			if (ch == *inp){
				ch = NULL;
			}
			else if (ch != inp){
				free(*inp);
				*inp = ch;
				ch = NULL;
			}
			*(*inp + (*count) - 1) = a;
		}
		else{
			printf("\nyou pressed a error key!!\n");
		}
	}
}

int zuozishuzhi(node* root){
	int i = 0;
	char c = root->value;
	while(*(zx + i) != c) {
		i++;
	}
	return i;
}
/*  zuoshu：中序表中当前树根（不含在内）的左边位数
fuzuoshu：中序表中当前树最后一位（包含在内）左边的位数
i：当前树根在先序表中的索引
qianzuoshu：中序表中当前树第一位（不包含）左边的位数
当前根节点的子左树位数求法：zuoshu - qianzuoshu
当前根节点的左子树根值求法： *（xx + i +1）
当前根节点的右子树位数求法：fuzishu - zuoshu - 1
当前根节点的右子树根值求法： *（xx + i + zuoshu - qianzuoshu + 1）
判断左子树根是否还含有子树：zuoshu - qianzuoshu >= 2?
判断右子树根是否还含有子树：fuzuoshu - zuoshu - 1 >= 2?
判断是否有左子树：zuoshu - qianzuoshu >= 1?
判断是否有右子树：fuzishu - zuoshu - 1 >= 1?
*/
void jianshu(node* root, int i, int fuzuoshu, int qianzuoshu){
	int zuoshu = zuozishuzhi(root);
	node* leftroot = NULL;
	node* rightroot = NULL;
	leftroot = (node*)malloc(sizeof(node));
	rightroot = (node*)malloc(sizeof(node));
	leftroot->left = leftroot->right = rightroot->left = rightroot->right = NULL;
	if (zuoshu - qianzuoshu >= 1){
		leftroot->value = *(xx + i + 1);
		root->left = leftroot;
	}
	if (fuzuoshu - zuoshu - 1 >= 1){
		rightroot->value = *(xx + i + zuoshu - qianzuoshu + 1);
		root->right = rightroot;
	}
	if (zuoshu - qianzuoshu >= 2){
		jianshu(leftroot, i + 1, zuoshu, qianzuoshu);
	}
	if (fuzuoshu - zuoshu - 1 >= 2){
		jianshu(rightroot, i + zuoshu - qianzuoshu + 1, fuzuoshu, zuoshu + 1);
	}
}

void houxubianli(node* root){
	if (root->left != NULL)
		houxubianli(root->left);

	if (root->right != NULL){
		houxubianli(root->right);
	}

	printf("%c", root->value);
}

int main(void){
	printf("\n输入先序遍历结果：\n");
	input(&xx, &count1);
	printf("\n输入中序遍历结果：\n");
	input(&zx, &count2);
	if (count1 != count2){
		printf("\nthe number should be same!!");
		system("pause");
		exit(1);
	}
	node* root = (node*)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	root->value = *xx;
	jianshu(root, 0, count1, 0);
	printf("后序遍历结果为：\n");
	houxubianli(root);
	system("pause");
	return 0;
}
