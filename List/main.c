#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int data;
    struct tagNode *next;
} LNode, *LinkList;
void InitList(LinkList *L);
void CreatLinkR(LinkList L, int n);
void CreatLinkL(LinkList L, int n);
void TraverseList(LinkList L);
int LastElem(LinkList L);

int main() {

    LinkList L;
    InitList(&L);

    int n;
    scanf("%d",&n);
    printf("1.ͷ�巨��������\n");
    CreatLinkL(L, n);
    TraverseList(L);
    printf("2.β�巨��������\n");
    CreatLinkR(L, n);
    TraverseList(L);
    printf("��������һ��Ԫ���ǣ�%d", LastElem(L));
    return 0;
}

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));    // ���������ͷ�ڵ�, L ָ��ͷ�ڵ�
    (*L)->next = NULL;                         // ��ʼ��������ʼʱΪ������
}
void CreatLinkR(LinkList L, int n)
{
    /*
     * β�巨��������
     */
    LinkList p, s;
    p = L;
    while (n-->0) {
        s = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&s->data);
        p->next = s;
        p = s;
    }
    p->next = NULL;
}
void CreatLinkL(LinkList L, int n)
{
    /*
     * ͷ�巨��������
     */
    LinkList p ;
    while (n-->0) {
        p = malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}
void TraverseList(LinkList L)
{
    /*
     * ��������
     */
    LinkList p = L->next;
    while (p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int LastElem(LinkList L)
{
    /*
     * �����������һ��Ԫ��
     */
    LinkList p = L->next;
    int e;
    while (p != NULL) {
        e = p->data;
        p = p->next;
    }
    return e;
}