#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
                long value;
                struct node* last;
                struct node* next;
            };
typedef struct node node;

node* first= NULL; //节点起始指针
node* p = NULL;

int isnone(void);//判断链表是否为空
void initial(long x);//插入节点同时会对节点排序，方便后续操作
void pop(long x);//删除节点
void deletesamenode(void);//清除重复节点
void printnode(void);//顺序输出所有节点

int main(void)
{
    int select = 1;

    for(;;)
    {
        printf("您希望执行什么操作？添加节点（1），删除节点（2），清除重复节点（3），输出所有节点（4），退出（5）\n");
        scanf_s("%d",&select);
        switch(select)
            {
                case 1:
                    {
                        int test1 = 1;
                        while(true)
                            {
                                if(test1==1)
                                    {
                                        long x =0;
                                        printf("输入节点的值（long）:");
                                        scanf_s("%ld",&x);
                                        initial(x);
                                        
                                    }
                                else
                                    {
                                        break;
                                    }
                                printf("\n是否继续添加元素？是（1）/否（0）\n");
                                scanf_s("%d",&test1);
                            }
                    }
                break;
                case 2:
                   {
                        int test2 =1;
                        while(true)
                            {
                                if(test2==1)
                                    {
                                        if(isnone())
                                            {
                                                printf("链表为空！！！");
                                            }
                                        else
                                            {
                                                long x = 0;
                                                printf("\n输入你想删除的节点的值：");
                                                scanf_s("%ld",&x);
                                                pop(x);
                                            }
                                    }
                                else
                                    {
                                        break;
                                    }
                                printf("\n是否继续删除节点？是（1）/否（0）\n");
                                scanf_s("%d",&test2);
                            }
                   }
                break;
                case 3:
					deletesamenode();
                break;
				case 4:
					printnode();
					break;
                case 5:
                    goto end;
                default:
                    printf("输入选项不存在！\n");
                break;
            }
    }
    end:system("pause");
    return 0;
}

int isnone(void)
{
    if (first==NULL)
    {
        return 1;
    }
    else
        return 0;
}

void initial(long x)
{
	p = (node*)malloc(sizeof(node));
	node* p1 = first;
	if (isnone())
	{
		first = p;
		first->last = NULL;
		first->value = x;
		first->next = NULL;
	}
	else
	{

		while (x > p1->value&&p1->next != NULL){
			p1 = p1->next;
		}
		if (p1->value >= x && p1->last!=NULL){
			p1->last->next = p;
			p->last = p1->last;
			p1->last = p;
			p->next = p1;
			p->value = x;
		}
		else if( p1->value >= x && p1->last == NULL){
			first = p;
			first->next = p1;
			p1->last = p;
			p->value = x;
			p->last = NULL;
		}
		else{
			p1->next = p;
			p->next = NULL;
			p->last = p1;
			p->value = x;
		}
	}
	printf("\n已添加新节点，其值为：%ld", p->value);
	
}


void pop(long x)
{
    node* now=first;
    while(now!=NULL)
        {
            if(now->value==x)
                {
                    if(now->last!=NULL&&now->next!=NULL)
                        {
                            now->last->next=now->next;
                            now->next->last=now->last;
                        }
                    else if(now->next!=NULL&&now->last==NULL)
                        {
                            now->next->last=NULL;
                            first = now->next;
                        }
                    else if(now->last!=NULL&&now->next==NULL)
                        {
                            now->last->next=NULL;

                        }
                    else
                        {
                            first=NULL;
                        }
                    free(now);
                    printf("\n值为%ld的节点已被删除",x);
                    break;
                }
            else
                {
                    if(now->next != NULL && now->next->value <= x)
                        {
                            now = now->next;
                        }
                    else
                        {
                            printf("\n未找到值为%ld的节点",x);
                            break;
                        }
                }
        }


}

void deletesamenode(void){
	if (isnone())
	{
		printf("链表为空！！！");
	}
	else
	{
		int state = 1;
		node* p1 = first;
		node* p2 = NULL;
		while (p1->next != NULL){
			if (state == 1){
				p2 = p1->next;
				if (p1->value == p2->value){
					p1->next = p2->next;
					if (p2->next != NULL){
						p2->next->last = p1;
					}
					free(p2);
					state = 1;
				}
				else{
					state = 0;
				}

			}
			else{
				p1 = p1->next;
				state = 1;
			}
		}
	}
}

void printnode(void){
	if (isnone())
	{
		printf("链表为空！！！");
	}
	else
	{
		node* p = first;
		while (p != NULL){
			printf(" %ld ",p->value);
			p = p->next;
		}
		printf("\n");
	}
}




