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

int main() {

    LinkList L1, L2;
    InitList(&L1);
    InitList(&L2);

    int n, m;
    scanf("%d %d",&n,&m);

    printf("头插法创建链表L1：\n");
    CreatLinkL(L1, n);
    TraverseList(L1);
    printf("L1链表的最后一个元素是：%d\n", LastElem(L1));

    printf("尾插法创建链表L2：\n");
    CreatLinkR(L2, m);
    TraverseList(L2);

    printf("将链表L2接在L1的后面：\n");
    LinkContact(L1, &L2);
    TraverseList(L1);

    return 0;
}

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));    // 创建链表的头节点, L 指向头节点
    (*L)->next = NULL;                         // 初始化链表，初始时为空链表
}
void CreatLinkR(LinkList L, int n)
{
    /*
     * 尾插法创建链表
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
     * 头插法创建链表
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
     * 遍历链表
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
     * 返回链表最后一个元素
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
     * 将链表L2接在L1的后面
     */
    LinkList p = L1->next, q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
    }
    if (q != NULL && *L2 != NULL) {
        q->next = (*L2)->next;
        free(*L2);
        *L2 = NULL;
    }

}