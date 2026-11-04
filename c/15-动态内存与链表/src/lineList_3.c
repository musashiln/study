#include <stdio.h>
#include <stdlib.h>

// 动态链表尾插法

// 1.定义链表节点
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *createList();
void printNodeList(Node *node);
int main()
{
    Node *head = createList();
    printNodeList(head);
    return 0;
}
/**
 * @brief createList 创建链表
 * @return  创建好的链表
 */
Node *createList(){
    // 1.创建头节点
    Node *head = (Node *)malloc(sizeof(Node));
    if(head == NULL){
        return NULL;
    }
    head->next = NULL;

    // 2.接收用户输入数据
    int num = -1;
    printf("请输入节点数据\n");
    scanf("%i", &num);

    // 3.通过循环创建其它节点
    // 定义变量记录上一个节点
    Node *pre = head;
    while(num != -1){
        // 3.1创建一个新的节点
        Node *cur = (Node *)malloc(sizeof(Node));
        cur->data = num;

        // 3.2让新节点链接到上一个节点后面
        pre->next = cur;
        // 3.3当前节点下一个节点等于NULL
        cur->next = NULL;
        // 3.4让当前节点编程下一个节点的上一个节点
        pre = cur;

        // 3.5再次接收用户输入数据
        scanf("%i", &num);
    }

    // 3.返回创建好的节点
    return head;
}
/**
 * @brief printNodeList 遍历链表
 * @param node 链表指针头
 */
void printNodeList(Node *node){
    Node *head = node->next;
    while(head != NULL){
        int currentData = head->data;
        printf("currentData = %i\n", currentData);
        head = head->next;
    }
}
