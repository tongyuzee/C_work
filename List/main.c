#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int data;
    struct tagNode *next;
} LNode, *LinkList;
void CreatLinkR(LinkList L, int n);
void CreatLinkL(LinkList L, int n);
void TraverseList(LinkList L);

int main() {

    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));    // 创建链表的头节点, L 指向头节点
    L->next = NULL;                         // 初始化链表，初始时为空链表

    int n;
    scanf("%d",&n);
    printf("1.头插法创建链表：\n");
    CreatLinkL(L, n);
    TraverseList(L);
    printf("2.尾插法创建链表：\n");
    CreatLinkR(L, n);
    TraverseList(L);
    return 0;
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
