#include <stdio.h>
#include <stdlib.h>

// 动态链表头插法

// 1.定义链表节点
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *createList();

int main()
{
    Node *head = createList();
    return 0;
}
// 创建空链表
Node *createList(){
    // 1.创建一个节点
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL){
        exit(-1);
    }
    // 2.设置下一个节点为NULL
    node->next = NULL;
    // 3.返回创建好的节点
    return node;
}
