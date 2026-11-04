#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.定义链表节点
typedef struct node{
    int data;
    struct node *next;
}Node;
int main()
{

    // 2.创建链表节点
    Node a;
    Node b;
    Node c;

    // 3.初始化节点数据
    a.data = 1;
    b.data = 3;
    c.data = 5;

    // 4.链接节点
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    // 5.创建链表头
    Node *head = &a;

    // 6.使用链表
    while(head != NULL){
        int currentData = head->data;
        printf("currentData = %i\n", currentData);
        head = head->next;
    }
    return 0;
}
