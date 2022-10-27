#include<stdio.h>  
#include<stdlib.h>  
 
typedef struct Node{  
    int data;  
    struct Node* next;  
}LNode,*LinkList;  
 
void Josephus(int n, int m, int k)  
{  
    LinkList p = NULL, x = NULL, list = NULL;  
    int i;  
    for(i = 1; i <= n; i++)  
    {  
        p = (LNode*)malloc(sizeof(LNode));//��ϵͳ�����ڴ�  
        if (p==NULL) {//ȷ��ָ��ʹ��ǰΪ�ǿ�ָ�룬��pΪ��ָ��ʱ��������  
            printf("����ʧ�ܣ�");  
            exit(1);  
        }  
        p->data = i;//���  
        if(list == NULL)  
            list = p;  
        else  
            x->next = p;//��x��p�ڵ㴮����  
            x = p;//xָ�����  
    }  
    p->next = list;//����һ��ѭ������  
    p = list;//pָ�����  
    for(i = 1; i < k; i++)  
    {  
        x = p;  
        p = p->next;  
    }            //��ʱpָ���1��������  
    while(p->next != p)  
    {  
        for(i=1; i<m; i++)  
        {  
            x = p;  
            p = p->next;  
        }                    //pָ���m����㣬xָ���m-1�����  
       x->next = p->next;              //ɾ����m�����  
        printf("%d�ų���\n", p->data);         //���һ�������  
        free(p);                        //�ͷű�ɾ�����Ŀռ�  
        p = x->next;                    //pָ���µĳ�����  
	}  
    printf("%d�ų���\n", p->data);   //�������Ǹ����ı��  
    free(p);  
}  
int main()  
{  
    int m,k,n;  
    printf("��������������");  
    scanf("%d",&n);  
    printf("������ӵڼ��˱�����");  
    scanf("%d",&k);  
    printf("�������������ĳ��У�");  
    scanf("%d",&m);  
    Josephus(n, m, k);  
}  