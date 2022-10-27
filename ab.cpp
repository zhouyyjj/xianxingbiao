#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int DataType;
//��Data��length��װ��һ���ṹ
typedef struct seqList 
{
	DataType data[MAXSIZE];
		int length;
}SeqList,*PSeqList;
//��ʼ��
PSeqList Init_seqList(void)
{
	PSeqList PL;
	PL=(PSeqList)malloc(sizeof(SeqList));
	if(PL!=NULL)
		PL->length=0;
return (PL);
}
//����
void Destory_SeqList(PSeqList *PL)
{
	if(PL&&*PL)
free(*PL);
*PL=NULL;
return;
}
int Length_SeqList(PSeqList PL)
{
	if(PL)
		return(PL->length);
	return(-1);
}
//����
int Location_SeqList(PSeqList PL,DataType x)
{
   int i=0;
   if(!PL)
   {
	   printf("������");
	   return(-1);
   }
   while(i<PL->length && PL->data[i]!=x)
   {
	   i++;}
   if(i>=PL->length)
	   return 0;
   else 
	   return(i+1);
}

//��������
int Insert_SeqList(PSeqList PL,int i,DataType x)
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
	if(i<1||i>PL->length+1)
	{
		printf("����λ�ò��Ϸ�");
	return(0);
	}
	for(j=PL->length-1;j>=i-1;j--)
		PL->data[j+1]=PL->data[j];
		PL->data[i-1]=x;
	    PL->length++;
	return(1);
}
//ɾ��
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
	printf("ɾ��λ�ò��Ϸ�");
	return(0);
}
for(j=i;j<PL->length;j++)
PL->data[j-1]=PL->data[j];
PL->length--;
return(1);
}
//��ӡ���ݡ�˳���������
int Print_SeqList(PSeqList PL)
{
	int i=0;
	if(!PL)
	{
		printf("������");
		return(-1);
}
	while(i<PL->length)
{
	printf("%4d",PL->data[i]);
	i++;
}
return(1);
}
void Inter_sec(PSeqList A,PSeqList B)
{
	int i=0;
	while(i<A->length)
	{
		if(!Location_SeqList(B,A->data[i]))
			Delete_SeqList(A,i+1);
		else i++;
	}
}
void Merge_sec(PSeqList A,PSeqList B)
{
	int i;
	for(i=0;i<B->length;i++)
	{
		if(!Location_SeqList(A,B->data[i]))
			Insert_SeqList(A,A->length+1,B->data[i]);
	}
}
 main()
{
	PSeqList A,B,C;
	A=Init_seqList();
    C=Init_seqList();
	int i,x;
	printf("������A���ϵ����ݣ�\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&x);
		Insert_SeqList(A,i+1,x);
        Insert_SeqList(C,i+1,x);
	}
	printf("A����\n");
	Print_SeqList(A);
	printf("\n������B���ϵ�����:\n");
	B=Init_seqList();
    for(i=0;i<5;i++)
	{
		scanf("%d",&x);
		Insert_SeqList(B,i+1,x);
	}
	printf("B����\n");
	Print_SeqList(B);
	printf("\nA��B�Ľ���\n");
	Inter_sec(A,B);
	Print_SeqList(A);
    printf("\nA��B�Ĳ���\n");
	Merge_sec(C,B);
	Print_SeqList(C);
    Destory_SeqList(&A);
    Destory_SeqList(&B);
	return 1;

}