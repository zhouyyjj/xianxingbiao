#include "stdio.h"
#include "malloc.h"


typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}LNode,*LinkList;

//�����յĵ����� 
LinkList Creat_LinkList(void){
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if(H)
		H->next=NULL;
	return H;
}
//���Ҳ�����1.����Ų��� 
LinkList Locate_LinkList_Pos(LinkList H, int i)
{
	LinkList p = H;
	int j = 0;

	while(p && j<i)
	{
		p = p->next;
		j++;
	}
	if (j!=i || !p)
	{
		printf("����i�������������");
		return NULL;
	}
	return p;
}
//���Ҳ�����2.��ֵ���� 
LinkList Locate_LinkList_Value(LinkList H, DataType x)
{
	LinkList p = H->next;
	
	while(p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//���룺�ڵ����� �ĵ�i��λ��ǰ����һ��ֵΪx���½�� 
int Insert_LinkList(LinkList H,int i,DataType x){
	LinkList p,q;
	p=Locate_LinkList_Pos(H,i-1);
	if(!p){
		return -1;
	}
	q=(LinkList)malloc(sizeof(LNode));
	if(!q){
		
		return 0;
	}
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}

//ɾ�� ��i�����
int Del_LinkList(LinkList H,int i){
	//ɾ��������H�ϵĵ�i����㣬��ڲ�����������ɾ��Ԫ����ţ����ز������ɹ���־��0��ʾ���ɹ���1��ʾ�ɹ�
	LinkList p,q;
	if(H==NULL||H->next==NULL) {
		printf("���������ڻ�ձ���ɾ��");
		return 0;
	}
	p = Locate_LinkList_Pos(H,i-1);//�ҵ�i-1������ַ
	if(p==NULL||p->next==NULL){
		printf("����i����");
		return 0;
	} 
	q=p->next;
	p->next=q->next;
	free(q);
	return 1;
} 
 
//���ٵ����� 
void Destroy_LinkList(LinkList *H){
	
	LinkList p,q;
	p = *H;
	while(p){
		q=p;
		p=p->next;
		free(q);
	}
	*H=NULL;
}
void print_LinkList(LinkList H)
{
	LinkList p;
	
	if(H == NULL || H->next == NULL)
	{
		printf("�������ڻ�����Ϊ��");
		return;
	}

	printf("����������Ϊ��\n");
	p = H->next;
	while(p)
	{
		printf("%4d ", p->data);
		p = p->next;
	}
	printf("\n");
}

