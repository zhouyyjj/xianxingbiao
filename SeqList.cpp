#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct node{
	DateType date[MAXSIZE];
	int length;
}SeqList,*PSeqList;
 
//˳���ĳ�ʼ��
PSeqList Iint_SeqLiSt(viod)
{
	PSeqList PL;
	PL=(SeqList)malloc(sizeof(PSeqList));
	if(PL)
	PL->length=0;
	return (PL);
 } 

//˳���ĳ���
int Length_SeqList(PSeqList L) 
{
	return(L->length);
}

//˳�����������
int Location_SeqList(PSeqList L,DataType x)
{
	int i=0;
	while(i<L->length&&L->date[i]!=x)
	i++;
	if(i>=L->length)
	return 0;
	else
	return (i+1);
 } 
 
 //˳���Ĳ���
 int Insert_SeqList(PSeqLIst PL,int i,DateType x)
 {
 	int j;
 	if(!PL)
 	{
 		printf("������");
		 return(-2); 
	 }
	 if(PL->length>=MAXSIZE)
	 {
	 	printf("�����");
	 	return(-1);
	 }
	 if(i<1||i<PL->length+1)
	 {
	 	printf("����λ�ò��Ϸ�");
	 	return(0);
	 }
	 for(j=PL->length-1;j>=i-1;j--)
	 PL->date[j+1]=PL->date[j];
	 PL->date[i-1]=x;
	 PL->length++;
	 return(1);
	 
} 

//ɾ������
int Delete_SeqList(PSeqList PL,int i)
{
	int j;
	if(!PL)
	{
		printf("������");
		return(-1);
	}
	if(i<1||i>PL->length)
	{
		printf("ɾ��λ�ò��Ϸ�")��
		return(0); 
	}
	for(j=i;j<PL->length;j++)
	PL->date[j-1]=PL->data[j];
	PL->length--;
	return(1); 
 } 
