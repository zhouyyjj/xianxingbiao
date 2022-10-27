#include<stdio.h>
#include<stdlib.h>

typedef struct Table{
    int * head;
    int length;
    int size;
}table;

//��ʼ��˳���
table initTable(int size){
    table t;
    t.head=(int*)malloc(size*sizeof(int));
    if (!t.head)
    {
        printf("��ʼ��ʧ��\n");
        exit(0);
    }
    t.length=0;
    t.size=size;
    return t;
}
 
void DisplayList(table t1)
{
     int m, i, j;
    int k=0;
    printf("\n");
    printf("�������������ĳ���: \n");
    scanf("%d", &m);
    printf("\n");
    printf("���д���������:\n");
    for (i=t1.length; i>0; i--)
     {
         k=(k+m-1)%i;
         printf("%d ",t1.head[k]);
        for (j=k;j<i-1; j++)
         {
             t1.head[j] = t1.head[j+1];
         }
         t1.length = t1.length - 1;
    }
    printf("\n");
}
 
int main()
{
    int size,i;
    printf("�����������������");
    scanf("%d",&size);
    table t1=initTable(size);
    for (i=1; i<=size; i++) {
     t1.head[i-1]=i;
     t1.length++;
    }
    DisplayList(t1);
}