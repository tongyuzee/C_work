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
void LinkContact(LinkList L1, LinkList *L2);
void DestroyList(LinkList *L);
int LengthList(LinkList L);
int InsertList(LinkList L, int i, int e);

int main() {

    LinkList L1, L2;
    InitList(&L1);
    InitList(&L2);

    int n, m;
    scanf("%d %d",&n,&m);

    printf("ͷ�巨��������L1��\n");
    CreatLinkL(L1, n);
    TraverseList(L1);
    printf("L1��������һ��Ԫ���ǣ�%d\n", LastElem(L1));

    printf("β�巨��������L2��\n");
    CreatLinkR(L2, m);
    TraverseList(L2);

    printf("������L2����L1�ĺ��棺\n");
    LinkContact(L1, &L2);
    TraverseList(L1);

    int i, e, flag;
    printf("��������Ҫ�����Ԫ�أ�\ne=");
    scanf("%d", &e);
    printf("��������Ҫ����Ԫ�ص�λ��(i<=%d)��\ni=", LengthList(L1));
    scanf("%d", &i);
    flag = InsertList(L1, i, e);
    if (flag == 1)
    {
        printf("Ԫ�ز���ɹ���\n��λ��%d����Ԫ��%d�������Ϊ��\n", i, m);
        TraverseList(L1);
    }
    else
        printf("Ԫ�ز���ʧ�ܡ�\n");


    // �������� L1 �� L2
    // ���ն�̬�ڴ��ʹ��Ҫ�󣬵�����ʹ������ʱ���߳������֮ǰ����Ҫ�������б�ʱ��������н����ڴ��ͷŵ���
    DestroyList(&L1);
    DestroyList(&L2);

    return 0;
}

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));    // ���������ͷ�ڵ�, *L ָ��ͷ�ڵ�
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
void LinkContact(LinkList L1, LinkList *L2)
{
    /*
     * ������L2����L1�ĺ���
     */
    LinkList p = L1->next, q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
    }
    if (q != NULL && *L2 != NULL) {
        q->next = (*L2)->next;
        free(*L2);              // �ͷ�����L2��ͷ�ڵ�
        *L2 = NULL;
    }
}
void DestroyList(LinkList *L)
{
    /*
     * �������� L
     */
    LinkList q, p = *L;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    *L = NULL;
}
int InsertList(LinkList L, int i, int e)
{
    /*
     * ������L�ĵ�i��λ�ó���Ԫ��e
     */
    LinkList p = L->next, s;
    while (p != NULL && i > 1) {
        p = p->next;
        i--;
    }
    if (p == NULL || i < 1) return 0 ;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}
int LengthList(LinkList L)
{
    int cnt = 0;
    LinkList p = L->next;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}