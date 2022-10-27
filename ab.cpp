#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int DataType;
//将Data与length封装成一个结构
typedef struct seqList 
{
	DataType data[MAXSIZE];
		int length;
}SeqList,*PSeqList;
//初始化
PSeqList Init_seqList(void)
{
	PSeqList PL;
	PL=(PSeqList)malloc(sizeof(SeqList));
	if(PL!=NULL)
		PL->length=0;
return (PL);
}
//销毁
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
//查找
int Location_SeqList(PSeqList PL,DataType x)
{
   int i=0;
   if(!PL)
   {
	   printf("表不存在");
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

//插入数据
int Insert_SeqList(PSeqList PL,int i,DataType x)
{
	int j;
	if(!PL)
	{ 
		printf("表不存在");
	 return(-2);
	}
	if(PL->length>=MAXSIZE)
	{
		printf("表溢出");
		return(-1);
	}
	if(i<1||i>PL->length+1)
	{
		printf("插入位置不合法");
	return(0);
	}
	for(j=PL->length-1;j>=i-1;j--)
		PL->data[j+1]=PL->data[j];
		PL->data[i-1]=x;
	    PL->length++;
	return(1);
}
//删除
int Delete_SeqList(PSeqList PL,int i)
{
   int j;
   if(!PL)
{
	printf("表不存在");
	return(-1);
}
if(i<1||i>PL->length)
{
	printf("删除位置不合法");
	return(0);
}
for(j=i;j<PL->length;j++)
PL->data[j-1]=PL->data[j];
PL->length--;
return(1);
}
//打印数据、顺序表遍历输出
int Print_SeqList(PSeqList PL)
{
	int i=0;
	if(!PL)
	{
		printf("表不存在");
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
	printf("请输入A集合的数据：\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&x);
		Insert_SeqList(A,i+1,x);
        Insert_SeqList(C,i+1,x);
	}
	printf("A集合\n");
	Print_SeqList(A);
	printf("\n请输入B集合的数据:\n");
	B=Init_seqList();
    for(i=0;i<5;i++)
	{
		scanf("%d",&x);
		Insert_SeqList(B,i+1,x);
	}
	printf("B集合\n");
	Print_SeqList(B);
	printf("\nA与B的交集\n");
	Inter_sec(A,B);
	Print_SeqList(A);
    printf("\nA与B的并集\n");
	Merge_sec(C,B);
	Print_SeqList(C);
    Destory_SeqList(&A);
    Destory_SeqList(&B);
	return 1;

}